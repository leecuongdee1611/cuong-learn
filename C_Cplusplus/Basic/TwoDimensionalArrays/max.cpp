#include <iostream>
#include <cstdlib> // for srand() and rand()
#include <ctime>   //for time
using namespace std;

// maximum row, col of array
#define ROW 100
#define COL 100

// prototype
void nhapMang(int mt[][COL], int &m, int &n);
void xuatMang(int mt[][COL], int m, int n);
int timMax(int mt[][COL], int m, int n);

int main()
{
    int mt[ROW][COL]; // array mt have max element
    int nRow, nCol;   // so phan tu dong va cot duoc su dung

    // nhap xuat mang tu dong
    nhapMang(mt, nRow, nCol);
    xuatMang(mt, nRow, nCol);

    // tim max
    int max = timMax(mt, nRow, nCol);
    cout << "Max: " << max << endl;

    return 0;
}

// Ham nhap mang
void nhapMang(int mt[][COL], int &m, int &n)
{
    // khoi tao so ngau nhien
    srand(time(NULL));

    cout << "Nhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;

    // khoi tao mang ngau nhien tu[0][0] den[m - 1][n - 1]
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mt[i][j] = rand() % 100;
        }
    }
}

// Ham xuat mang
void xuatMang(int mt[][COL], int m, int n)
{
    //xuat tung phan tu cua mang
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mt[i][j] << "\t";
        }
        cout << endl;
    }
}

int timMax(int mt[][COL], int m, int n)
{
    int i, j, max;
    max = mt[0][0];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mt[i][j] > max)
            {
                max = mt[i][j];
            }
        }
    }
    return max;
}