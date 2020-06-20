#include <iomanip>
#include <iostream>
using namespace std;

bool all_zero(const int array[], int size)
{
    bool zero = true;
    int knots_without_matchs(0);
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            knots_without_matchs++;
        }
    }
    ifS(knots_without_matchs != size)
    {
        zero = false;
    }
    if (zero) {
        return (true);
    } else {
        return (false);
    }
}

void next_move(
        int array[],
        int size,
        int player,
        int& knot_chosen,
        int& matchs_removed)
{
    knot_chosen = choose_knot(player);
    validate_knot(player, knot_chosen, size);
    validate_knot1(array, player, knot_chosen);
    matchs_removed = numofmatchs_to_remove(array[knot_chosen], knot_chosen);
    validate_matchs(array, knot_chosen, matchs_removed, array[knot_chosen]);
}

int choose_knot(int player)
{
    int knot_id;
    cout << "Игрок (" << player << ") :На какой кучки вы хотели бы играть? ";
    cin >> knot_id;
    return (knot_id);
}

void validate_knot(int player, int& knot_chosen, int size)
{
    while (knot_chosen < 0 || knot_chosen > size - 1) {
        cout << "Неверный номер кучки. Пожалуйста, попробуйте еще раз." << endl;
        knot_chosen = choose_knot(player);
    }
}

void validate_knot1(int array[], int player, int& knot_chosen)
{
    while (array[knot_chosen] == 0) {
        cout << "Кучка " << knot_chosen
             << " имеет ноль спичек. Пожалуйста, выберите другую кучку."
             << endl;
        knot_chosen = choose_knot(player);
    }
}
