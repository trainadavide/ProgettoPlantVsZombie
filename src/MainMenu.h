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
    MainMenu(unsigned short int width, unsigned short int height);
    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();

    void render(RenderWindow* menu, RectangleShape* background);

    int MainMenuPressed() const{
        return MainMenuSelected;
    }
    ~MainMenu() = default;
private:
    int MainMenuSelected;
    Font font;
    Text mainMenu[Max_main_menu];
};