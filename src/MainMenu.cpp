//
// Created by Nayla on 07/09/2022.
//

#include "MainMenu.h"
#include <iostream>
using namespace std;
using namespace sf;
MainMenu::MainMenu(unsigned short int width, unsigned short int height) {
    if(!font.loadFromFile("../font/peach_days/Peach Days.ttf")){
        cout<<"No font is here";
    }
    //Play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::Blue);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(80);
    mainMenu[0].setPosition(500,250);
    //EXit
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Exit");
    mainMenu[1].setCharacterSize(80);
    mainMenu[1].setPosition(500,350);

    MainMenuSelected=0;
}
MainMenu::~MainMenu() {

}
void MainMenu::draw(sf::RenderWindow &window) {
    for(int i=0;i<Max_main_menu;i++){
        window.draw(mainMenu[i]);
    }
}
//MoveUp
void MainMenu::MoveUp() {
    if(MainMenuSelected+1>=0){
        mainMenu[MainMenuSelected].setCharacterSize(80);
        mainMenu[MainMenuSelected].setFillColor(Color::White);

        MainMenuSelected--;
        if(MainMenuSelected==-1){
            MainMenuSelected=1;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
        mainMenu[MainMenuSelected].setCharacterSize(80);
    }
}
//MoveDown
void MainMenu::MoveDown() {
    if(MainMenuSelected-1<=Max_main_menu){
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        mainMenu[MainMenuSelected].setCharacterSize(80);

        MainMenuSelected++;
        if(MainMenuSelected==2){
            MainMenuSelected=0;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
        mainMenu[MainMenuSelected].setCharacterSize(80);
    }
}

void MainMenu::render(RenderWindow* menu, RectangleShape* background){
    (*menu).clear();
    (*menu).draw(*background);
    this->draw(*menu);
    (*menu).display();
}