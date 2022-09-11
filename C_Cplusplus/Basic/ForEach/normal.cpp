#include <iostream>
using namespace std;

#define MAX 5
int main()
{
    int arr[MAX] = {14, 3, 6, 27, 12};
    // for (int i = 0; i < MAX; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // for each structure
    for (const auto &item : arr)
    {
        cout << item << " ";
    }

    cout << endl;
}