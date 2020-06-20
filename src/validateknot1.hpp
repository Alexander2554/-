#ifndef VALIDATEKNOT1_H
#define VALIDATEKNOT1_H
using namespace std;

void validate_knot1(int array[], int player, int& knot_chosen);
int numofmatchs_to_remove(int matchs, int knot_chosen);
void validate_matchs(
        int array[], int knot_chosen, int& matchs_removed, int matchs);
void move_matchs(int array[], int knot_chosen, int matchs_removed);
#endif