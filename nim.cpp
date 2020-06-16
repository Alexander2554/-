int main()
{
    const int KNOTS(15);
    const int MATCHS(10);
    int * array;
    int number_of_knots(1);
    int player(1);
    int knot_chosen;
    int matchs_removed;
    bool allzero(false);
    // Алгоритм:
    // Подсказка и считывание количества кучек
    number_of_knots=read_knots (KNOTS);
    // Подсказка и считывание количества спичек в каждой кучки
    array=new int [number_of_knots];
    procedure (array,number_of_knots,MATCHS);
    // Нарисуйте спички в кучке
    draw_knots (array,number_of_knots);
    // Отображение статистики
    statistics (array,number_of_knots);
    // Пока какая-то кучка не бюудет пуста
    while (!allzero)
    {
        // Подсказать и прочитать следующий ход игрока
        next_move (array,number_of_knots,player,knot_chosen,matchs_removed);
        // Удалить указанное количество спичек из указанной кучки
        move_matchs (array,knot_chosen,matchs_removed);
        // Если все кучи пусты, то
        allzero=all_zero (array,number_of_knots);
        if(allzero)
        {
            // Распечатать сообщение, поздравляющее победившего игрока.
            congrats (player);
        }
        //Иначе
        else
        {
            // Перерисуйте кучки с процентами
            draw_knots (array,number_of_knots);
            // Отображение статистики
            statistics (array,number_of_knots);
            // Переключиться на другого игрока
            switch_the_turn (player);
            // КОНЕЦ, ЕСЛИ
        }
        // КОНЕЦ ПОКА
    }
    delete [] array;
    return 0;
}