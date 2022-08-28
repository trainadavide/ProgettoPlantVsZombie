#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Titolo", sf::Style::Default);
    while (window.isOpen()){
        sf::Event event{};

        while(window.pollEvent(event)){
            switch(event.type){

                case sf::Event::EventType::Closed:
                    window.close();
                    break;

                case sf::Event::EventType::KeyPressed:
                    if(event.key.code == sf::Keyboard::Key::Space){
                        window.clear(sf::Color::Red);
                        window.display();
                    }
                    break;

                case sf::Event::EventType::KeyReleased:
                    if(event.key.code == sf::Keyboard::Key::Space){
                        window.clear(sf::Color::Black);
                        window.display();
                    }
                    break;
            }
        }

    }

}
