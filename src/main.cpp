//
// Created by Nayla on 07/09/2022.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
using namespace sf;
using namespace std;

int main(){

    RenderWindow MENU(VideoMode(1200,700),"Menu",Style::Default);
    MainMenu mainMenu(MENU.getSize().x,MENU.getSize().y);
    RectangleShape background;
    background.setSize(Vector2f(MENU.getSize()));
    Texture Maintexture;
    Maintexture.loadFromFile("../immagini/MenuBackground.jpg");
    background.setTexture(&Maintexture);
    while(MENU.isOpen())
    {
        Event event;
        while(MENU.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                MENU.close();
            }
            if(event.type==Event::KeyReleased)
            {
                if(event.key.code==Keyboard::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }
                if(event.key.code==Keyboard::Down){
                    mainMenu.MoveDown();
                    break;
                }
                if(event.key.code==Keyboard::Return){
                    RenderWindow Play(VideoMode::getDesktopMode(),"PlantsVSZombies");

                    int x=mainMenu.MainMenuPressed();
                    if(x==0)
                    {
                        while(Play.isOpen())
                        {
                            Event aevent;
                            while(Play.pollEvent(aevent)){
                                if(aevent.type==Event::Closed)
                                {
                                    Play.close();
                                }
                                if(aevent.type==Event::KeyPressed)
                                {
                                    if(aevent.key.code==Keyboard::Escape)
                                    {
                                        Play.close();
                                    }
                                }
                            }
                            //background game
                            RectangleShape GameBackground;
                            GameBackground.setSize(Vector2f(Play.getSize()));
                            Texture back;
                            back.loadFromFile("../immagini/BackgroundGame.jpg");
                            GameBackground.setTexture(&back);
                            Play.clear();
                            Play.draw(GameBackground);
                            Play.display();
                        }
                    }
                    if(x==1)
                    {
                        MENU.close();
                        break;
                    }
                }
            }
        }
        MENU.clear();
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.display();
    }
}