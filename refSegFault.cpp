#include <iostream>
using namespace std;

// int& getRefVar() {
//     int x = 10;
//     return x;
// }

int main() {
    int *ptr = nullptr;

    int &ref = *ptr;

    cout << ref << endl;

    return 0;

    // int &r = getRefVar();

    // cout << r << endl;

    // return 0;
}