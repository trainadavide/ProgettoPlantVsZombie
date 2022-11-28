//
// Created by david on 14/09/2022.
//
#include "Game.h"
#include "Graphics/Button.h"
#include <cstdlib>
#include <ctime>

Game::Game() {
    //initializing Game attributes and assets
    this->initVariables();
    this->initWindow();
    this->initTextures();
    //creating player
    this->player = new Player(5,this->window->getSize());
    //timer start
    this->crono = new Timer();
    //creating map
    this->map =new Map();

    //plant's buttons
    for(int i = 0 ; i<NUMBEROFPLANTS; i++)
        this->buttons[i] = new Button(i, buttonImages[i], this->window->getSize().x);
    //initializing zombies
    this->initZombieVariables();
    this->updateZombies();

}

Game::~Game() {
    delete window;
    //Deleting zombies
    for(auto *i:this->zombies)
    {
        delete i;
    }
}

bool Game::running(){
    return this->window->isOpen();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->e))//waiting events
    {
        switch (this->e.type) {
            //if close button is pressed
            case sf::Event::Closed:
                this->window->close();
                break;
            //if escape is pressed
            case sf::Event::KeyPressed:
                if(e.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            //if mouse is pressed
            case sf::Event::MouseButtonReleased:
                if(this->e.mouseButton.button==sf::Mouse::Left && this->map->isOver(mousePosition)){
                    Vector2<unsigned int> pos = this->map->getPosition(mousePosition);
                    this->map->setPlant((int)pos.x,(int)pos.y,*player, this->window->getSize());
                }

                break;


            default:
                break;
        }
    }
}

void Game::update() {
    //managing events
    this->pollEvents();
    this->updateMousePosition();
    this->player->update();
    //if 5 seconds have passed since last EnergyUp->EnergyUp
    if(crono->getTime()>=lastEnergyUp+5) {
        player->increaseEnergy();
        //calls all plants'actions
        map->actions(*player,bullets);
        lastEnergyUp+=5;
    }
    //calls the update of all buttons
    for(auto & button : this->buttons)
        button->update(this->mousePosition, *player, this->window->getSize().x);
    //time root
    srand(time(NULL));
    //when game updates,update zombies
    this->updateZombies();
    this->updateBullets();

}

void Game::render() {

    this->window->clear();
    this->drawBackground();
    //draw button
    for(auto & button : this->buttons)
        button->render(this->window);
    //draw HUD
    this->player->render(this->window);
    //draw grid
    this->map->draw(this->window);

    //draw zombies
    for(auto *zombie:this->zombies)
    {
        zombie->renderZombie(this->window);
    }

    for(auto *bullet: this->bullets){
        bullet->draw(this->window);
    }

    this->window->display();
}

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    //set window dimensions depending on screen resolution
    this->vm.height = VideoMode::getDesktopMode().height;
    this->vm.width = VideoMode::getDesktopMode().width;
    //create window
    this->window = new RenderWindow(this->vm, "PlantsVSZombies", sf::Style::Titlebar);
}

void Game::drawBackground(){
    RectangleShape gameBackground;
    gameBackground.setSize(Vector2f(this->window->getSize()));
    Texture back;
    back.loadFromFile("./images/BackgroundGame.jpg");
    gameBackground.setTexture(&back);
    this->window->draw(gameBackground);
}



void Game::updateMousePosition() {
    this->mousePosition = (Vector2f) sf::Mouse::getPosition(*this->window);
}

void Game::initTextures() {
    this->buttonImages[0].loadFromFile("./images/Sunflower.jpg");
    this->buttonImages[1].loadFromFile("./images/Nut.jpg");
    this->buttonImages[2].loadFromFile("./images/ShooterPlant.jpg");
    this->buttonImages[3].loadFromFile("./images/SnowPlant.jpg");
    this->buttonImages[4].loadFromFile("./images/FirePlant.jpg");
}

void Game::initZombieVariables() {
    //spawnTimerMax needed to set spawning speed
    this->spawnTimerMax = 10;
    this->spawnTimer = this->spawnTimerMax;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
void Game::updateZombies() {
    //setting Zombies`rows depending on window dimensions
    rows[0] = this->window->getSize().y * (1 - HEIGHT_PROPORTION - ZOMBIE_ALIGNAMENT);
    rows[1] = rows[0] + this->window->getSize().y * (HEIGHT_PROPORTION / 5);
    rows[2] = rows[1] + this->window->getSize().y * (HEIGHT_PROPORTION / 5);
    rows[3] = rows[2] + this->window->getSize().y * (HEIGHT_PROPORTION / 5);
    rows[4] = rows[3] + this->window->getSize().y * (HEIGHT_PROPORTION / 5);
    //x needed to change randomly zombie types
    x = rand() % 11;
    this->spawnTimer += 0.03f;//spawning speed
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
        if (this->spawnTimer >= this->spawnTimerMax) {
            //spawning positions
            this->zombies.push_back(new Zombie(this->window->getSize().x, rows[rand() % 5],type));
            this->spawnTimer = 0.f;
        }
        for (int k = 0; k < this->zombies.size(); k++) {
            //to move zombies
            //TODO using delta time to move zombies
            this->zombies[k]->update();
            //removing zombies who reach the end
            if (this->zombies[k]->getBounds().left > this->window->getSize().x)//checking x position of zombies
            {
                this->zombies.erase(this->zombies.begin() + k);
            }
        }
    }
#pragma clang diagnostic pop

}

void Game::updateBullets() {
    for (int k = 0; k < this->bullets.size(); k++) {
        //to move zombies
        //TODO using delta time to move zombies
        this->bullets[k]->update();
        //removing zombies who reach the end
        if (this->bullets[k]->getPosition() > this->window->getSize().x)//checking x position of bullets
        {
            this->bullets.erase(this->bullets.begin() + k);
        }
    }
}
