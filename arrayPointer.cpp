#include <iostream>
using namespace std;

int main() {
    int NUMBER_ELEMENTS;

    cout << "Please enter the number of elements: ";
    cin >> NUMBER_ELEMENTS;

    short *array1 = new short[NUMBER_ELEMENTS];

    if (array1 != nullptr) { //check nullptr
        short *ptr1 = array1;

        for (int i = 0; i < NUMBER_ELEMENTS; i++) {
            *ptr1 = i;
            ptr1++;
        }
    }

    int size = NUMBER_ELEMENTS / 2;
    short *array2 = new short[size];
    if (array2 != nullptr) {
        short *ptrRead = array1 + 1;
        short *ptrRecord = array2;

        for (int i = 0; i < size; i++) {
            *ptrRecord = *ptrRead;
            ptrRead = ptrRead + 2;
            ptrRecord = ptrRecord + 1;
        }
    }

    /*Print the output to check*/
    cout << "array1: ";
    for (short *p = array1; p < array1 + NUMBER_ELEMENTS; p++){
        cout << *p << " ";
    }
    cout << endl;

    cout << "array2: ";
    for (short *p = array2; p < array2 + size; p++)  {
        cout << *p << " ";
    }
    cout << endl;

    /*Release the memory*/
    delete [] array1; // release the array
    delete [] array2;
    array1 = nullptr; // release the ptr
    array2 = nullptr;

    return 0;
}