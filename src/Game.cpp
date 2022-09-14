//
// Created by david on 14/09/2022.
//

#include "Game.h"
Game::Game() {
    this->initVariables();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
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
}

void Game::render() {
    this->window->clear();

    this->drawBackground();

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