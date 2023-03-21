#include "Observer.h"

Observer::Observer(sf::RenderTarget *window) {
    this->window=window;
    initFont();
}

void Observer::initFont() {
    if(!textFont.loadFromFile("./font/octosquare/octosquare.ttf")){
        printf("Font doesn't load");
    }
}
