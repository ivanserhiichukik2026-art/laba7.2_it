
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, int rowCount, int colCount, int Low, int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, int rowCount, int colCount)
{
    cout << endl;

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << a[i][j];

        cout << endl;
    }

    cout << endl;
}

int MaxColumn(int** a, int rowCount, int j)
{
    int max = a[0][j];

    for (int i = 1; i < rowCount; i++)
    {
        if (a[i][j] > max)
            max = a[i][j];
    }

    return max;
}

int SearchMinMax(int** a, int rowCount, int colCount)
{
    int min = MaxColumn(a, rowCount, 1);

    for (int j = 3; j < colCount; j += 2)
    {
        int max = MaxColumn(a, rowCount, j);

        if (max < min)
            min = max;
    }

    return min;
}

int main()
{
    srand((unsigned)time(NULL));

    int rowCount = 5;
    int colCount = 6;
    int Low = -10;
    int High = 20;

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);

    cout << "Matrix:";
    Print(a, rowCount, colCount);

    int result = SearchMinMax(a, rowCount, colCount);

    cout << "Result = " << result << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];

    delete[] a;

    return 0;
}
