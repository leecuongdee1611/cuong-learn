/*
Mang 1 chieu la mang tinh, co 1 so khuyet diem
    - mang tro thanh con tro va mat thong tin ve chieu dai khi truyen vao ham
    - khong co nhieu ham ho tro san
class std::array
    - khong chuyen thanh con tro khi truyen vao ham -> size(), for each ben trong ham
    at() method: truy cap vao phan tu cua mang, an toan nhung cham hon
    size() method: kich thuoc cua mang
    sort() method: sap xep mang
*/
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

#define MAX 5

/*
    - su dung tham chieu &arr -> tiet kiem bo nho va truy cap mang nhanh hon
    - const -> tranh viec thay doi gia tri cua mang
*/
void printArray(const array<int, MAX> &arr)
{
    cout << "So phan tu cua mang: " << arr.size() << endl;
    for (const auto &item : arr)
    {
        cout << item << ' ';
    }
    cout << endl;
}

int main()
{
    // khai bao 1 mang
    array<int, MAX> arr = {2, 5, 8, 3, 1};
    printArray(arr);

    // sap xep tang
    cout << "Sap xep tang: " << endl;
    sort(arr.begin(), arr.end());
    printArray(arr);

    // sap xep giam
    cout << "Sap xep giam: " << endl;
    sort(arr.rbegin(), arr.rend());
    printArray(arr);

    return 0;
}