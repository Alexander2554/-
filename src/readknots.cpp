#include <iomanip>
#include <iostream>
using namespace std;

int read_knots(const int KNOTS)
{
    int knots;
    cout << "Сколько кучек в этой игре? ";
    cin >> knots;
    while (knots < 1 || knots > KNOTS) {
        cout << "Количество кучек должно быть положительным и меньше или равно"
             << KNOTS << endl;
        cout << "Введите количество стержней: ";
        cin >> knots;
    }
    cout << endl;
    return (knots);

    void procedure(int array[], int size, const int MATCHS)
    {
        int n;
        for (int i = 0; i < size; i++) {
            cout << "Сколько спичек находится в кучке" << i << ": ";
            cin >> n;
            while (n < 1 || n > MATCHS) {
                cout << "Извините, количество спичек должно быть положительным "
                        "и меньше или равно "
                     << MATCHS << "." << endl;
                cout << "Сколько объектов находится на стержне " << i << ": ";
                cin >> n;
            }
            array[i] = n;
        }
    }

    void draw_knots(int array[], int size)
    {
        int sum(0);
        for (int i = 0; i < size; i++) {
            sum = sum + array[i];
        }
        cout << endl;
        for (int i = 0; i < size; i++) {
            draw_knots1(i, array[i], sum);
        }
        cout << endl;
    }

    void draw_knots1(int array_index, int number_of_matchs, int sum)
    {
        cout << "Кучка " << setw(3) << array_index << ": ";
        for (int x = 0; x < number_of_matchs; x++) {
            cout << "#";
        }
        double percentage = number_of_matchs * 100.00 / sum;
        cout << setw(16 - number_of_matchs) << "(" << fixed << setprecision(3)
             << percentage << "%)" << endl;
    }
