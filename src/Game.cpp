//
// Created by david on 14/09/2022.
//
#include "Game.h"
#include "Graphics/Button.h"
#include <cstdlib>
#include <ctime>

Game::Game() {
    //initializing Game attributes and assets
    initVariables();
    initWindow();
    initTextures();
    //creating player
    player = new Player(5,window->getSize());
    //timer start
    crono = new Timer();
    //creating map
    map =new Map();

    incremented=false;
    observer = new Observer(window);

    //plant's buttons
    for(int i = 0 ; i<NUMBEROFPLANTS; i++)
        buttons[i] = new Button(i, buttonImages[i], window->getSize().x);
    //initializing zombies
    initZombieVariables();
    updateZombies();

}

Game::~Game() {
    delete window;
    //Deleting zombies
    for(auto *i:zombies)
    {
        delete i;
    }
}

bool Game::running(){
    return window->isOpen();
}

void Game::pollEvents() {
    while (window->pollEvent(e))//waiting events
    {
        switch (e.type) {
            //if close button is pressed
            case sf::Event::Closed:
                window->close();
                break;
            //if escape is pressed
            case sf::Event::KeyPressed:
                if(e.key.code == sf::Keyboard::Escape)
                    window->close();
                break;
            //if mouse is pressed
            case sf::Event::MouseButtonReleased:
                if(e.mouseButton.button==sf::Mouse::Left && map->isOver(mousePosition)){
                    Vector2<unsigned int> pos = map->getPosition(mousePosition);
                    if(map->isEmpty(pos.x,pos.y)) {
                        map->setPlant((int) pos.x, (int) pos.y, *player, window->getSize());
                    }

                }

                break;


            default:
                break;
        }
    }
}

void Game::update() {
    //managing events
    pollEvents();
    updateMousePosition();
    player->update();
    //if 5 seconds have passed since last EnergyUp->EnergyUp
    if(crono->getTime()%5==0 && !incremented) {
        player->increaseEnergy();
        //calls all plants'actions
        map->actions(*player,bullets,window->getSize().x);
        incremented = true;
        for(int i=0;i<zombies.size();i++){
            if(map->checkCollision(zombies[i])){
                map->hitPlant(zombies[i]);
            }
        }
    }
    if((crono->getTime()-1)%5==0)
        incremented=false;
    //calls the update of all buttons
    for(auto & button : buttons)
        button->update(mousePosition, *player, window->getSize().x);
    //time root
    srand(time(NULL));
    //when game updates,update zombies
    updateZombies();
    updateBullets();
    //collisions
    Collisions();

}

void Game::render() {

    window->clear();
    drawBackground();
    //draw button
    for(auto & button : buttons)
        button->render(window);
    //draw HUD
    player->render(window);
    //draw grid
    map->draw(window);

    //draw zombies
    for(auto *zombie:zombies)
    {
        zombie->renderZombie(window);
    }

    for(auto *bullet: bullets){
        bullet->draw(window);
    }

    renderAchievements();

    window->display();
}

void Game::initVariables() {
    window = nullptr;
}

void Game::initWindow() {
    //set window dimensions depending on screen resolution
    vm.height = VideoMode::getDesktopMode().height;
    vm.width = VideoMode::getDesktopMode().width;
    //create window
    window = new RenderWindow(vm, "PlantsVSZombies", sf::Style::Titlebar);
    window->setFramerateLimit(120);
}

void Game::drawBackground(){
    RectangleShape gameBackground;
    gameBackground.setSize(Vector2f(window->getSize()));
    Texture back;
    back.loadFromFile("./images/BackgroundGame.jpg");
    gameBackground.setTexture(&back);
    window->draw(gameBackground);
}



void Game::updateMousePosition() {
    mousePosition = (Vector2f) sf::Mouse::getPosition(*window);
}

void Game::initTextures() {
    buttonImages[0].loadFromFile("./images/Sunflower.jpg");
    buttonImages[1].loadFromFile("./images/Nut.jpg");
    buttonImages[2].loadFromFile("./images/ShooterPlant.jpg");
    buttonImages[3].loadFromFile("./images/SnowPlant.jpg");
    buttonImages[4].loadFromFile("./images/FirePlant.jpg");
}

void Game::initZombieVariables() {
    //spawnTimerMax needed to set spawning speed
    spawnTimerMax = 10;
    spawnTimer = spawnTimerMax;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
void Game::updateZombies() {
    //setting Zombies`rows depending on window dimensions
    rows[0] = window->getSize().y * (1 - HEIGHT_PROPORTION - ZOMBIE_ALIGNAMENT);
    rows[1] = rows[0] + window->getSize().y * (HEIGHT_PROPORTION / 5);
    rows[2] = rows[1] + window->getSize().y * (HEIGHT_PROPORTION / 5);
    rows[3] = rows[2] + window->getSize().y * (HEIGHT_PROPORTION / 5);
    rows[4] = rows[3] + window->getSize().y * (HEIGHT_PROPORTION / 5);
    //x needed to change randomly zombie types
    x = rand() % 11;
    spawnTimer += 0.03f;//spawning speed
    //setting zombie type probability
    if (crono->getTime() >= 0) {
        type = ZombieType::BASIC;
        if (crono->getTime() >= 20) {
            if (x <= 3) {
                type = ZombieType::BASIC;
            } else if (x > 3 && x < 6) {
                type = ZombieType::TANK;
            } else {
                type = ZombieType::SHOVEL;
            }
        }

        //time gap between spawns
        if (spawnTimer >= spawnTimerMax) {
            //spawning positions
            zombies.push_back(new Zombie(window->getSize().x, rows[rand() % 5],type));
            spawnTimer = 0.f;
        }
        for (int k = 0; k < zombies.size(); k++) {
            //to move zombies
            if(!map->checkCollision(zombies[k]))
                zombies[k]->update();

            //removing zombies who reach the end
            if (zombies[k]->getBounds().left > window->getSize().x)//checking x position of zombies
            {
                zombies.erase(zombies.begin() + k);
            }
        }
    }
#pragma clang diagnostic pop

}

void Game::updateBullets() {
    for (int k = 0; k < bullets.size(); k++) {
        //to move zombies
        bullets[k]->update();
        //removing zombies who reach the end
        if (bullets[k]->getPosition() > window->getSize().x)//checking x position of bullets
        {
            bullets.erase(bullets.begin() + k);
        }
    }
}
//collisions
void Game::Collisions() {
    if(!bullets.empty() && !zombies.empty())
    for(int k=0;k<bullets.size(); k++){
        for(int i=0;i<zombies.size();i++){
            if(bullets[k]->getBounds().intersects(zombies[i]->getBounds()))
            {
                if(bullets[k]->isIce()){
                    zombies[i]->setSpeed(-2.5f);
                }
                zombies[i]->takeDamage(bullets[k]->getPower());
                if(zombies[i]->isDead()){
                    zombies.erase(zombies.begin()+i);
                    observer->update();
                }
                bullets.erase(bullets.begin()+k);
                i=zombies.size();
            }
        }
    }
}

void Game::renderAchievements() {
    if(observer->isDrawable())
        observer->draw(this->window);
}


