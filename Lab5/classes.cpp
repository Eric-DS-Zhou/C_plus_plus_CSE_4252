#include <iostream>
using namespace std;

class A {
    protected:
     int var;
    public:
     A() { var = 0; }
     void increment() { var++; }
     virtual void decrement() { var--; }
     /* Original script*/
     // void print() { cout << "var = " << var << endl; }
     /* Question 1*/
      virtual void print() { cout << "var = " << var << endl; }
};

class B : public A {
    protected:
     int varB;
    public:
     B() { varB = 0; }

     void increment() { var += 3; }
     virtual void decrement() { var -= 3; }
     void print() {
        cout << "var = " << var << ", varB = " << varB << endl;
     }
};

/* Question 4: */
A test (A obj) {
    return obj;
}

int main() {
    /* Original script */
    // A a;
    // A * ptr;
    // ptr = &a;

    /* Question 1: */
    // B b;
    // A* ptr;
    // ptr = &b;
    // ptr -> increment();
    // ptr -> print();
    // ptr -> decrement();
    // ptr -> print();

    /* Question 2: */
    // A a;
    // B b;
    // A* ptr;
    // a = b;
    // a.print();
    // ptr = &a;
    // ptr -> print();

    /* Question 3: */
    // b.A::print();

    /* Question 4*/
    B b;
    A a = test(b);
    a.print();

    return 0;
}