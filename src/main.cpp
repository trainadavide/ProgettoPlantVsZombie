//
// Created by Nayla on 07/09/2022.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Graphic/Button.h"
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
            switch (event.type) {
                case Event::Closed:
                    MENU.close();

                case Event::KeyReleased:
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
                        Button btn1({180,180}, 0);
                        Button btn2({180,180}, 1);

                        int x=mainMenu.MainMenuPressed();
                        if(x==0)
                        {
                            while(Play.isOpen())
                            {
                                Event playEvent;
                                while(Play.pollEvent(playEvent)){
                                    switch (playEvent.type) {
                                        case Event::Closed:
                                            Play.close();
                                        break;

                                        case Event::KeyPressed:
                                            if(playEvent.key.code==Keyboard::Escape)
                                            {
                                                Play.close();
                                            }
                                        break;

                                        case Event::MouseMoved:
                                            if(btn1.isMouseOver(Play)){
                                                btn1.setSize({200,200});
                                            }
                                            else{
                                                btn1.setSize({180,180});
                                            }
                                            if(btn2.isMouseOver(Play)){
                                                btn2.setSize({200,200});
                                            }
                                            else{
                                                btn2.setSize({180,180});
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
                                btn1.drawTo(Play);
                                btn2.drawTo(Play);
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