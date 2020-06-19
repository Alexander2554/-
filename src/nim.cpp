#include <iostream>
#include <iomanip>
using namespace std;

int read_knots (const int KNOTS);
void procedure (int array[],int size,const int MATCHS);
void draw_knots (int array[],int size);

int main()
{
    const int KNOTS(15);
    const int MATCHS(10); 
    int * array;g
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

int read_knots (const int KNOTS)
{
    int knots;
    cout<<"Сколько кучек в этой игре? ";
    cin>>knots;
    while (knots<1 || knots>KNOTS)
    {
        cout<<"Количество кучек должно быть положительным и меньше или равно"<<KNOTS<<endl;
        cout<<"Введите количество стержней: ";
        cin>>knots;
    }
    cout<<endl;
    return (knots);

/*
Эта функция запрашивает у пользователя количество спичек для размещения в этой кучки и проверяет, находится ли количество спичек, введенных для кучки, в диапазоне от 1 до максимального разрешенного количества объектов.
array [] - это массив кучек.
size-это размер массива.
MATCHS-это максимальное количество спичек на стержень.
*/
void procedure (int array[],int size,const int MATCHS)
{
    int n;
    for (int i=0;i<size;i++)
    {
        cout<<"Сколько спичек находится в кучке"<<i<<": ";
        cin>>n;
        while (n<1||n>MATCHS)
        {
            cout<<"Извините, количество спичек должно быть положительным и меньше или равно "<<MATCHS<<"."<<endl;
            cout<<"Сколько объектов находится на стержне "<<i<<": ";
            cin>>n;
        }
        array[i]=n;
    }
}

/*
Эта функция вычисляет общее количество спичек в массиве кучек, пересекает массив кучек и вызывает вспомогательную процедуру для отображения каждой полной строки.
*/
void draw_knots (int array[],int size)
{
    int sum(0);
    for (int i=0;i<size;i++)
    {
        sum=sum+array[i];
    }
    cout<<endl;
    for (int i=0;i<size;i++)
    {
        draw_knots1 (i,array[i],sum);
    }
    cout<<endl;
}