#include <iomanip>
#include <iostream>
using namespace std;

void statistics(int array[], int size)
    {
        smallest(array, size);
        largest(array, size);
        average(array, size);
        cout << endl;
    }

    
    void smallest(int array[], int size)
    {
        int smallest = array[0];
        if (array[0] == 0) {
            for (int i = 1; i < size; i++) {
                if (array[i] != 0) {
                    smallest = array[i];
                }
            }
        }
        for (int i = 1; i < size; i++) {
            if (array[i] != 0 && array[i] < smallest) {
                smallest = array[i];
            }
        }
        for (int i = 0; i < size; i++) {
            if (array[i] == smallest) {
                cout << "Кучка " << i
                     << " имеет наименьшее количество объектов с " << smallest
                     << " спичек." << endl;
            }
        }
    }

    
    void largest(int array[], int size)
    {
        int largest = array[0];
        for (int i = 1; i < size; i++) {
            if (array[i] > largest) {
                largest = array[i];
            }
        }
        for (int i = 0; i < size; i++) {
            if (array[i] == largest) {
                cout << "Кучка " << i
                     << " имеет наибольшее количество объектов с" << largest
                     << " спичек." << endl;
            }
        }
    }

    
    void average(int array[], int size)
    {
        int sum(0);
        int knots_with_object(0);
        for (int i = 0; i < size; i++) {
            if (array[i] != 0) {
                sum = sum + array[i];
                knots_with_object++;
            }
        }
        double average = sum * 1.00 / knots_with_object;
        cout << "Среднее число спичек в кучке (т. е. кучки с спичками) равно"
             << fixed << setprecision(2) << average << " спичек." << endl;
    }
