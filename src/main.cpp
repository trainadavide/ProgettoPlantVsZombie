//
// Created by Nayla on 07/09/2022.
//
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MainMenu.h"
using namespace sf;
using namespace std;

int main(){

    //Main Menu window creation
    RenderWindow menu(VideoMode(1200,700),"Menu",Style::Default);
    MainMenu mainMenu(menu.getSize().x,menu.getSize().y);

    //Menu Background
    RectangleShape background;
    background.setSize(Vector2f(menu.getSize()));
    Texture MainTexture;
    MainTexture.loadFromFile("./images/MenuBackground.jpg");
    background.setTexture(&MainTexture);

    while(menu.isOpen())
    {
        mainMenu.render(&menu , &background);
        Event event{};
        while(menu.pollEvent(event))    //Menu loop
        {
            switch (event.type) {
                //Close button pressed
                case Event::Closed:
                    menu.close();
                    break;

                case Event::KeyReleased:
                    //Move UP
                    if (event.key.code == Keyboard::Up) {
                        mainMenu.MoveUp();
                        break;
                    }

                    //Move DOWN
                    if (event.key.code == Keyboard::Down) {
                        mainMenu.MoveDown();
                        break;
                    }

                    if (event.key.code == Keyboard::Return) {
                        //Play button pressed
                        if (mainMenu.MainMenuPressed() == 0) {
                            Game game;

                            while (game.running()) {
                                //Update
                                game.update();
                                //Render
                                game.render();
                                //Draw your game
                                }
                            }
                        }
                        //Exit button
                        if (mainMenu.MainMenuPressed() == 1) {
                            menu.close();
                            break;
                        }

                default:
                    break;
                }
            }
        }

    }
