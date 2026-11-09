#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void Create(int** a, int n, int m, int low, int high) // випадкові числа
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = low + rand() % (high - low + 1); // -10 + rand() % 31
}

void Print(int** a, int n, int m) // виведення
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(5) << a[i][j];

        cout << endl;
    }
    cout << endl;
}

int MaxColumn(int** a, int n, int j) // знаходження максимума в конкретному стовпці
{
    int max = a[0][j];

    for (int i = 1; i < n; i++) // i = 1 , перший стовпець вже максимум
        if (a[i][j] > max)
            max = a[i][j];

    return max;
}

int SearchMinMax(int** a, int n, int m) // знаходженння найменшого серед максимумів непарних стовпців
{
    int min = MaxColumn(a, n, 1); // знаходження мінумуму в стовпці з індексом 1 , позначення за перший мінимум

    for (int j = 3; j < m; j += 2) // j += 2 переходимо через один стовпець , щоб не шукати в парних
    {
        int max = MaxColumn(a, n, j);

        if (max < min)
            min = max;
    }

    return min;
}

int main()
{
    srand((unsigned)time(NULL));

    int n = 5, m = 6;
    int low = -10, high = 20; // границі для випадкових чисел

    int** a = new int* [n];

    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    Create(a, n, m, low, high);

    cout << "Matrix:" << endl;
    Print(a, n, m);

    int result = SearchMinMax(a, n, m);

    cout << "Result = " << result << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];

    delete[] a;

    return 0;
}
