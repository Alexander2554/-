#ifndef ALLZERO_H
#define ALLZERO_H
using namespace std;

bool all_zero(const int array[], int size);
void next_move(
        int array[],
        int size,
        int player,
        int& knot_chosen,
        int& matchs_removed);
int choose_knot(int player);
void validate_knot(int player, int& knot_chosen, int size);
#endif