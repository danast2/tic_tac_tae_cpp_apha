#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;

const int NUM_BLOCKS = 3;
const int block = 100;
const int margin = 15;
const int width = (block * 3) + (4 * margin);
const int heigh = (block * 3) + (4 * margin);

char mas[3][3] = { 0 };
//Добавить очищение поля на спейс
int query = 0;
bool game_over = false;
int color;
int num;


sf::RectangleShape rectangle(sf::Vector2f(100, 100));
sf::RectangleShape rectangle1(sf::Vector2f(100, 100));

bool win_game(char mas[3][3], char sign) {
    int zeroes = 0;
    int signs_in_row;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (mas[row][col] == 0) {
                zeroes++;
            }
        }
    }
    for (int row = 0; row < 3; row++) {
        if ((mas[row][0] == sign) && (mas[row][1] == sign) && (mas[row][2] == sign)) {
            cout << "rrrrows";
            return true;
        }
    }
    for (int col = 0; col < 3; col++) {
        if ((mas[0][col] == sign) && (mas[1][col] == sign) && (mas[2][col] == sign)) {
            cout << "cooooooools";
            return true;
        }
    }
    for (int col = 0; col < 3; col++) {
        if ((mas[0][0] == sign) && (mas[1][1] == sign) && (mas[2][2] == sign)) {
            cout << "anottttther";
            return true;
        }
    }
    for (int col = 0; col < 3; col++) {
        if ((mas[2][0] == sign) && (mas[1][1] == sign) && (mas[0][2] == sign)) {
            cout << "anottttther";
            return true;
        }
    }
    if (zeroes == 0) {
        cout << "zeroeddddddddd";
        return false;
    }
    cout << "nothing success";
    return false;
}



int main()
{
    int query = 0;
    sf::RenderWindow window(sf::VideoMode(width, heigh), "tic tac toe");

    while (window.isOpen())
    {
        sf::Mouse mouse;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && not game_over) {
                float x_mouse = sf::Mouse::getPosition(window).x;
                float y_mouse = sf::Mouse::getPosition(window).y;
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//забираем коорд курсора
                sf::Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
                
                int kord1_x = pixelPos.x;
                int kord1_y = pixelPos.y;
                
                int kord2_x = pos.x;
                int kord2_y = pos.y;

                int col = pos.x / (block + margin);
                int row = pos.y / (block + margin);
                if (mas[row][col] == 0) {
                    if (query % 2 == 0) {
                        mas[row][col] = 'x';
                    }
                    else {
                        mas[row][col] = 'o';
                    }
                    query++;
                }
            }
            
        }
        // red = 1; green = 2; white = 0;

        if (not game_over) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    if (mas[row][col] == 'x') {
                        color = 1;
                    }
                    else if (mas[row][col] == 'o') {
                        color = 2;
                    }
                    else {
                        color = 0;
                    }
                    int x = col * block + (col + 1) * margin;
                    int y = row * block + (row + 1) * margin;
                    switch (color)
                    {
                    case(1):
                        rectangle.setFillColor(sf::Color::Red);
                        break;
                    case(2):
                        rectangle.setFillColor(sf::Color::Green);
                        break;
                    case(0):
                        rectangle.setFillColor(sf::Color::White);
                        break;
                    default:
                        break;
                    }
                    rectangle.setPosition(x, y);
                    window.draw(rectangle);
                }
            }
        }
        
        if ((query - 1) % 2 == 0) {
            game_over = win_game(mas, 'x');
        }
        else {
            game_over = win_game(mas, 'o');
        }
        if (game_over) {
            window.clear();
        }
        
        window.display();
        
        
    }

    return 0;
}


