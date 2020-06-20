#include <iomanip>
#include <iostream>
using namespace std;

void congrats(int player)
{
    cout << endl;
    cout << "Поздравляю! Игрок " << player << " выиграл." << endl;
}

/*
Эта функция переключает поворот на другого игрока.
*/
S void switch_the_turn(int& player)
{
    if (player == 1) {
        player = 2;
    } else {
        player = 1;
    }
}