#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ROW 3
#define COL 3 // cot khong duoc de trong

int main()
{
    int a[][COL] = {
        {
            6,
        },
        {7, 8},
        {7, 2, 8}};

    int b[ROW][COL]{};
    srand(time(NULL));

    int row, col;
    cout << "Nhap so dong: ";
    cin >> row;
    cout << "Nhap so cot: ";
    cin >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            b[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << b[i][j] << "\t"; // t -> tab
        }
        cout << endl;
    }
}