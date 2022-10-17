//
// Created by david on 14/09/2022.
//
#include "Game.h"
#include "Graphics/Button.h"
#include <cstdlib>
#include <ctime>



Game::Game() { // NOLINT(cppcoreguidelines-pro-type-member-init)

    this->initVariables();
    this->initWindow();
    this->initTextures();

    this->player = new Player(5);

    this->crono = new Timer();

    this->map =new Map();
    //plant'sbuttons
    for(int i = 0 ; i<NUMBEROFPLANTS; i++)
        this->buttons[i] = new Button(i, buttonImages[i]);
    //zombies
    this->initZombieVariables();
    this->updateZombies();

}

Game::~Game() {
    delete window;
    for(auto *i:this->zombies)
    {
        delete i;
    }
}

bool Game::running(){
    return this->window->isOpen();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->e))
    {
        switch (this->e.type) {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if(e.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;

            case sf::Event::MouseButtonReleased:
                if(this->e.mouseButton.button==sf::Mouse::Left && this->map->isOver(mousePosition)){
                    Vector2<unsigned int> pos = this->map->getPosition(mousePosition);
                    this->map->setPlant((int)pos.x,(int)pos.y,*player);
                }

                break;


            default:
                break;
        }
    }
}

void Game::update() {
    this->pollEvents();
    this->updateMousePosition();
    this->player->update();
    if(crono->getTime()>=lastEnergyUp+5) {
        player->increaseEnergy();
        map->actions(*player);
        lastEnergyUp+=5;
    }
    for(auto & button : this->buttons)
        button->update(this->mousePosition, *player);

    srand(time(NULL));
    this->updateZombies();

}

void Game::render() {

    this->window->clear();
    this->drawBackground();
    //draw button
    for(auto & button : this->buttons)
        button->render(this->window);
    //draw HUD
    this->player->render(this->window);

    this->map->draw(this->window);

    //draw zombies
    for(auto *zombie:this->zombies)
    {
        zombie->renderZombie(this->window);
    }

    for(auto & button : this->buttons)
        button->render(this->window);

    this->player->render(this->window);

    this->map->draw(this->window);

    this->window->display();
}

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    this->vm.height = VideoMode::getDesktopMode().height;
    this->vm.width = VideoMode::getDesktopMode().width;

    this->window = new RenderWindow(this->vm, "PlantsVSZombies", sf::Style::Titlebar);
}

void Game::drawBackground(){
    RectangleShape gameBackground;
    gameBackground.setSize(Vector2f(this->window->getSize()));
    Texture back;
    back.loadFromFile("../images/BackgroundGame.jpg");
    gameBackground.setTexture(&back);
    this->window->draw(gameBackground);
}



void Game::updateMousePosition() {
    this->mousePosition = (Vector2f) sf::Mouse::getPosition(*this->window);
}

void Game::initTextures() {
    this->buttonImages[0].loadFromFile("../images/Sunflower.jpg");
    this->buttonImages[1].loadFromFile("../images/Nut.jpg");
    this->buttonImages[2].loadFromFile("../images/ShooterPlant.jpg");
    this->buttonImages[3].loadFromFile("../images/SnowPlant.jpg");
    this->buttonImages[4].loadFromFile("../images/FirePlant.jpg");
}


void Game::updateZombies() {
    rows[0] = this->window->getSize().y/5.60/2.0;
    rows[1] = rows[0]*2.5;
    rows[2] = rows[0]*4.5;
    rows[3] = rows[0]*6.5;
    rows[4] = rows[0]*8.5;
    x=rand()%11;
    this->spawnTimer += 0.03f;//velocità con cui spawnare gli zombie
    if (crono->getTime() >=0) {
        type = ZombieType::BASIC;
        if(crono->getTime()>=20){
            if(x<=3){
                type = ZombieType::BASIC;
            }
            else if(x>3 && x<6){
                type = ZombieType::TANK;
            }
            else{
                type=ZombieType::SHOVEL;
            }
        }
    }
    if (this->spawnTimer >= this->spawnTimerMax) {
        this->zombies.push_back(new Zombie(this->window->getSize().x, rows[rand() %5],type));//posizione in cui spawnare gli zombie
        this->spawnTimer = 0.f;
    }
    for (int k = 0; k < this->zombies.size(); k++) {
        this->zombies[k]->update();
        //tolgo gli zombie che arrivano infondo
        if (this->zombies[k]->getBounds().left > this->window->getSize().x)//se gli zombie superano la x dello schermo
        {
            this->zombies.erase(this->zombies.begin() + k);
        }
    }
}

void Game::initZombieVariables() {
    this->spawnTimerMax=10;
    this->spawnTimer=this->spawnTimerMax;
}


