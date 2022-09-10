#include <iostream>
using namespace std;

// hoan doi gia tri 2 so
void swapNumber(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool asc(int a, int b)
{
    return a > b;
}

bool desc(int a, int b)
{
    return a < b;
}

void selectionSort(int *arr, int n, bool (*comparisonFcn)(int, int))
{
    int i, j, find_idx;

    for (i = 0; i < n - 1; i++)
    {
        find_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (comparisonFcn(arr[find_idx], arr[j]))
            {
                find_idx = j;
            }
        }

        swapNumber(arr[find_idx], arr[i]);
    }
}

// mac dinh ham duoc sap xep tang dan neu khong truyen vao doi so thu 3
void selectionSort(int *arr, int n, bool (*comparisonFcn)(int, int) = asc);

// function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(int);

    // sap xep tang
    selectionSort(arr, n);
    cout << "Asc array: \n";
    printArray(arr, n);

    // sap xep giam
    selectionSort(arr, n, desc);
    cout << "Desc array: \n";
    printArray(arr, n);

    return 0;
}