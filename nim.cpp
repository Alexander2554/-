#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int RODS(15);
    const int OBJECTS(10);
    int * array;
    int number_of_rods(1);
    int player(1);
    int rod_chosen;
    int objects_removed;
    bool allzero(false);
    // Алгоритм:
    // Подсказка и считывание количества кучек
    number_of_rods=read_rods (RODS);
    // Подсказка и считывание количества спичек в каждой кучки
    array=new int [number_of_rods];
    procedure (array,number_of_rods,OBJECTS);
    // Нарисуйте спички в кучке
    draw_rods (array,number_of_rods);
    // Отображение статистики
    statistics (array,number_of_rods);
    // Пока какая-то кучка не бюудет пуста
    while (!allzero)
    {
        // Подсказать и прочитать следующий ход игрока
        next_move (array,number_of_rods,player,rod_chosen,objects_removed);
        // Удалить указанное количество спичек из указанной кучки
        move_objects (array,rod_chosen,objects_removed);
        // Если все кучи пусты, то
        allzero=all_zero (array,number_of_rods);
        if(allzero)
        {
            // Распечатать сообщение, поздравляющее победившего игрока.
            congrats (player);
        }
        //Иначе
        else
        {
            // Перерисуйте кучки с процентами
            draw_rods (array,number_of_rods);
            // Отображение статистики
            statistics (array,number_of_rods);
            // Переключиться на другого игрока
            switch_the_turn (player);
            // КОНЕЦ, ЕСЛИ
        }
        // КОНЕЦ ПОКА
    }
    delete [] array;
    return 0;
}

