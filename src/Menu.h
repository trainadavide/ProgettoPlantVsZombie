//
// Created by Nayla on 07/09/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#define Max_main_menu 2

class MainMenu
{
public:
    MainMenu(float width, float height);
    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int MainMenuPressed(){
        return MainMenuSelected;
    }
    ~MainMenu();
private:
    int MainMenuSelected;
    Font font;
    Text mainMenu[Max_main_menu];

};