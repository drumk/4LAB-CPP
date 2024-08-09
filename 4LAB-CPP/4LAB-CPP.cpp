#include <iostream>
#include <cstdlib>
#include <ctime>
void randomm(int i, int j, int a[3][3])
{
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            a[i][j] = (rand() % 50) - 25;
}
void mass(int i, int j, int a[3][3])
{
    for (i = 0; i < 3; i++)
    {
        std::cout << "\n";
        for (j = 0; j < 3; j++)
        {
            std::cout.width(3);
            std::cout << a[i][j];
        }
    }
}
void countt(int i, int j, int a[3][3], int count = 0)
{
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] < 0) count++;
        }
    }
    std::cout << "\n" << "Количество отрицательных компонент : " << count;
    count = 0;
}
void max(int i, int j, int a[3][3], int sum = 0)
{
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] < 0 && (sum == 0 || sum < a[i][j]))
                sum = a[i][j];
        }
    }
    std::cout << "\nНаибольшее отрицательное число: " << sum;
    sum = 0;
}
int main()
{
    int i{}, j{}, a[3][3], count = 0, sum = 0;
    setlocale(0, "Russian");
    srand(time(0));
    randomm(i, j, a);
    std::cout << "Матрица A[3][3]";
    mass(i, j, a);
    max(i, j, a, sum = 0);
    countt(i, j, a, count = 0);
    std::cout << "\n" << "\n";
    std::cout << "Матрица B[3][3]";
    randomm(i, j, a);
    mass(i, j, a);
    max(i, j, a, sum = 0);
    countt(i, j, a, count = 0);
}
