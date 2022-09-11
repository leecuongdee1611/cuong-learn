#include <iostream>
using namespace std;

// hoan doi gia tri 2 so
void swapNumber(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// sap xep tang su dung thuat toan selection sort
void selectionSortAsc(int *arr, int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        swapNumber(arr[min_idx], arr[i]);
    }
}

// sap xep giam su dung thuat toan selection sort
void selectionSortDesc(int *arr, int n)
{
    int i, j, max_idx;

    for (i = 0; i < n - 1; i++)
    {
        max_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[max_idx] < arr[j])
            {
                max_idx = j;
            }
        }
        swapNumber(arr[max_idx], arr[i]);
    }
}

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
    selectionSortAsc(arr, n);
    cout << "Asc array: \n";
    printArray(arr, n);

    // sap xep giam
    selectionSortDesc(arr, n);
    cout << "Desc array: \n";
    printArray(arr, n);

    return 0;
}