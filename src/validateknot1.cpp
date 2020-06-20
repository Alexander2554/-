#include <iomanip>
#include <iostream>
using namespace std;

void validate_knot1(int array[], int player, int& knot_chosen)
{
    while (array[knot_chosen] == 0) {
        cout << "Кучка " << knot_chosen
             << " имеет ноль спичек. Пожалуйста, выберите другую кучку."
             << endl;
        knot_chosen = choose_knot(player);
    }
}

int numofmatchs_to_remove(int matchs, int knot_chosen)
{
    int num;
    cout << "Введите количество спичек для удаления (" << matchs
         << " или меньше) от кучки " << knot_chosen << ": ";
    cin >> num;
    return (num);
}

void validate_matchs(
        int array[], int knot_chosen, int& matchs_removed, int matchs)
{
    while (matchs_removed < 1 || matchs_removed > matchs) {
        if (matchs_removed < 1) {
            cout << "Количество спичек, которые вы можете удалить, должно "
                    "быть положительным. Пробовать снова."
                 << endl;
        }
        if (matchs_removed > matchs) {
            cout << "Можно удалить только до" << matchs
                 << " спичек. Пожалуйста, попробуйте еще раз." << endl;
        }
        matchs_removed = numofmatchs_to_remove(array[knot_chosen], knot_chosen);
    }
}

void move_matchs(int array[], int knot_chosen, int matchs_removed)
{
    array[knot_chosen] = array[knot_chosen] - matchs_removed;
}

void congrats(int player)
{
    cout << endl;
    cout << "Поздравляю! Игрок " << player << " выиграл." << endl;
}
