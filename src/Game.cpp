//
// Created by david on 14/09/2022.
//

#include "Game.h"
#include <cstdlib>
#include <ctime>
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initZombies();
    this->updateZombies();
}

Game::~Game() {
    delete this->window;

    //Delete zombies
    for(auto *i:this->zombies)
    {
        delete i;
    }
}

const bool Game::running() const {
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

            default:
                break;
        }
    }
}

void Game::update() {
    this->pollEvents();
    srand(time(0));
    this->updateZombies();
}

void Game::render() {
    this->window->clear();

    this->drawBackground();
    for(auto *zombie:this->zombies)
    {
        zombie->render(this->window);
    }
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

void Game::updateZombies() {
    float rows[5];
    rows[0]=this->window->getSize().y-(this->window->getSize().y/2.0);
    rows[1]=this->window->getSize().y/2.0+(this->window->getSize().y/2.0/2.0);
    rows[2]=this->window->getSize().y/2.0-(this->window->getSize().y/2.0/2.0);
    rows[3]=20;
    rows[4]=this->window->getSize().y;
    this->spawnTimer += 0.5f;//velocità con cui spawnare gli zombie
    if(this->spawnTimer >=this->spawnTimerMax)
    {
        this->zombies.push_back(new Zombie(this->window->getSize().x,rows[rand()%(6)]));//posizione in cui spawnare gli zombie
        this->spawnTimer=0.f;
    }
    for(int k=0;k<this->zombies.size();k++)
    {
        this->zombies[k]->update();
        //tolgo gli zombie che arrivano infondo
        if(this->zombies[k]->getBounds().left>this->window->getSize().x)//se gli zombie superano la x dello schermo
        {
            this->zombies.erase(this->zombies.begin()+k);
        }
    }



}

void Game::initZombies() {
    this->spawnTimerMax=100.f;//velocità con cui spawnano gli zombies
    this->spawnTimer= this->spawnTimerMax;
}
