#include <iostream>

using namespace std;

int func(int a){
    return a;
}

int main(){
    cout << func << '\n';
    cout << func(2) << '\n';
}