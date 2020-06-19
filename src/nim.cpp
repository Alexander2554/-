#include <iostream>
#include <iomanip>
using namespace std;

int read_knots (const int KNOTS);
void procedure (int array[],int size,const int MATCHS);
void draw_knots (int array[],int size);
void draw_knots1(int array_index,int number_of_matchs,int sum);
void statistics (int array[],int size);
void smallest (int array[],int size);
void largest (int array[],int size);
void average (int array[],int size);
bool all_zero (const int array[],int size);
void next_move (int array[],int size,int player,int & knot_chosen,int & matchs_removed);
int choose_knot (int player);
void validate_knot (int player,int & knot_chosen,int size);
void validate_knot1 (int array[],int player,int & knot_chosen);
int numofmatchs_to_remove (int matchs,int knot_chosen);

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

/*
Эта функция отображает каждую полную строку.
индекс_массива-индекс массива для такого удилища.
number_of_matchs - это количество спичек для данной кучки.
сумма - это общее количество спичек в массиве кучек.
*/
void draw_knots1(int array_index,int number_of_matchs,int sum)
{
    cout<<"Кучка "<<setw(3)<<array_index<<": ";
    for (int x=0;x<number_of_matchs;x++)
    {
        cout<<"#";
    }
    double percentage=number_of_matchs*100.00/sum;
    cout<<setw(16-number_of_matchs)<<"("<<fixed<<setprecision(3)<<percentage<<"%)"<<endl;
}

/*
Эта функция отображает статистику для списка кучек
Статистика состоит из 1) кучек с наименьшим количеством спичек, 2) кучек с наибольшим количеством спичек и 3) среднего количества спичек в кучки с учетом только кучек с спичками.
size-это размер массива.
MATCHS-это максимальное количество спичек на стержень.
*/
void statistics (int array[],int size)
{
    smallest (array,size);
    largest (array,size);
    average (array,size);
    cout<<endl;
}

/*
Эта функция отображает стержни с наименьшим количеством объектов.
*/
void smallest (int array[],int size)
{
    int smallest=array[0];
    if (array[0]==0)
    {
        for (int i=1;i<size;i++)
        {
            if (array[i]!=0)
            {
                smallest=array[i];
            }
        }
    }
    for (int i=1;i<size;i++)
    {
        if (array[i]!=0 && array[i]<smallest)
        {
            smallest=array[i];
        }
    }
    for (int i=0;i<size;i++)
    {
        if (array[i]==smallest)
        {
            cout<<"Кучка "<<i<<" имеет наименьшее количество объектов с "<<smallest<<" спичек."<<endl;
        }
    }
}

/*
Эта функция отображает стержни с наибольшим количеством объектов.
*/
void largest (int array[],int size)
{
    int largest=array[0];
    for (int i=1;i<size;i++)
    {
        if (array[i]>largest)
        {
            largest=array[i];
        }
    }
    for (int i=0;i<size;i++)
    {
        if (array[i]==largest)
        {
            cout<<"Кучка "<<i<<" имеет наибольшее количество объектов с"<<largest<<" спичек."<<endl;
        }
    }
}

/*
Эта функция отображает среднее количество объектов на стержень с учетом только стержней с объектами.
*/
void average (int array[],int size)
{
    int sum(0);
    int knots_with_object(0);
    for (int i=0;i<size;i++)
    {
        if (array[i]!=0)
        {
            sum=sum+array[i];
            knots_with_object++;
        }
    }
    double average=sum*1.00/knots_with_object;
    cout<<"Среднее число спичек в кучке (т. е. кучки с спичками) равно"<<fixed<<setprecision(2)<<average<<" спичек."<<endl;
}

/*
Эта функция возвращает true, если все стержни имеют нулевой объект, и возвращает false в противном случае.
*/
bool all_zero (const int array[],int size)
{
    bool zero=true;
    int knots_without_matchs(0);
    for (int i=0;i<size;i++)
    {
        if (array[i]==0)
        {
            knots_without_matchs++;
        }
    }
    if (knots_without_matchs!=size)
    {
        zero=false;
    }
    if (zero)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

/*
Эта функция реализует шаг (vi) алгоритма, на котором текущий игрок делает свой следующий ход.
*/
void next_move (int array[],int size,int player,int & knot_chosen,int & matchs_removed)
{
    knot_chosen=choose_knot (player);
    validate_knot (player,knot_chosen,size);
    validate_knot1 (array,player,knot_chosen);
    matchs_removed=numofmatchs_to_remove (array[knot_chosen],knot_chosen);
    validate_matchs (array,knot_chosen,matchs_removed,array[knot_chosen]);
}

/*
Эта функция предлагает игроку выбрать кучку (идентификатор кучки), а затем возвращает это значение.
*/
int choose_knot (int player)
{
    int knot_id;
    cout<<"Игрок ("<<player<<") :На какой кучки вы хотели бы играть? ";
    cin>>knot_id;
    return (knot_id);
}

/*
Эта функция проверяет кучку, выбранный этим игроком, т. е. выбранная качка должен находиться в диапазоне от 0 до n-1, где n-общее количество кучек.
*/
void validate_knot (int player,int & knot_chosen,int size)
{
    while(knot_chosen<0||knot_chosen>size-1)
    {
        cout<<"Неверный номер кучки. Пожалуйста, попробуйте еще раз."<<endl;
        knot_chosen=choose_knot (player);
    }
}

/*
Эта функция проверяет, есть ли у выбранного стержня хотя бы один объект.
*/
void validate_knot1 (int array[],int player,int & knot_chosen)
{
    while(array[knot_chosen]==0)
    {
        cout<<"Кучка "<<knot_chosen<<" имеет ноль спичек. Пожалуйста, выберите другую кучку."<<endl;
        knot_chosen=choose_knot (player);
    }
}

/*
Эта функция запрашивает и считывает, сколько объектов нужно удалить из выбранного стержня.
*/
int numofmatchs_to_remove (int matchs,int knot_chosen)
{
    int num;
    cout<<"Введите количество спичек для удаления ("<<matchs<<" или меньше) от кучки "<<knot_chosen<<": ";
    cin>>num;
    return (num);
}