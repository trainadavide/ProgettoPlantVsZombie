//
// Created by david on 14/09/2022.
//

#include "Game.h"

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initTextures();

    this->player = new Player(5);

    this->crono = new Timer();

    for(int i = 0 ; i<NUMBEROFPLANTS; i++)
        this->buttons[i] = new Button(i, buttonImages[i]);
}

Game::~Game() {
    delete this->window;
    for(int i = 0 ; i<NUMBEROFPLANTS; i++)
        delete this->buttons[i];
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
    this->updateMousePosition();
    this->player->update();
    if(crono->getTime()>=lastEnergyUp+5) {
        player->increaseEnergy();
        lastEnergyUp+=5;
    }
    for(int i = 0 ; i<NUMBEROFPLANTS; i++)
        this->buttons[i]->update(this->mousePosition, *player);
}

void Game::render() {

    this->window->clear();

    this->drawBackground();

    for(int i = 0 ; i<NUMBEROFPLANTS; i++)
        this->buttons[i]->render(this->window);

    this->player->render(this->window);

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
    this->buttonImages[3].loadFromFile("../images/IcePlant.jpg");
    this->buttonImages[4].loadFromFile("../images/FirePlant.jpg");
}
