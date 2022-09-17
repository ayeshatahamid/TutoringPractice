#include <iostream>
using namespace std;

/*** Passing by Pointer ***/

void ChangeOriginal(int* num) {
    *num +=1;
}

class Pencil {
    int length;
public:
    Pencil();
    void Write();
    int getLength();
    void setLength(int x);
};

void usePencil(Pencil* p) {
    cout << "This pencil is writing" << endl;
    p->Write();
}

Pencil::Pencil() {
 length = 10;
}

void Pencil::Write() {
    length--;
}

int Pencil::getLength() {
    return length;
}

void Pencil::setLength(int x) {
    length = x;
}

void sharpenPencil(Pencil& p) {
    int x = p.getLength();
    x-=2;
}
int main() {

    /*** Pointers basics ***/
    //pointers point to an address
    //"&" will give the address of a variable

    int x = 9;
    cout << "Address of x using &: " << &x << endl;
    //--> "0xF11AE4001
    //  "*" in a variable declaration/definition will declare a pointer
    int* ptr1 = &x;
    //or
    int *ptr2 = &x;
    // ptr1 is a pointer to x's address

    //"*" will also dereference a pointer into a regular value (not an address)
    int y = *ptr1 + 1;
    cout << "Value of *ptr1+1 --> " << y << endl;
    // --> y is 10



    /*** Pointers and Arrays ***/
    // setting a ptr equal to an array will technically only be pointing to the first
    // element in the array.
    int arr[] = {0, 1, 2, 3};
    int* ptr3 = arr;
    cout << "Ptr3 = arr; --> " << *ptr3 << endl; //will print out 0, the first element

    // Since the array is connected, you can still reference other elements by adding to the pointer
    cout << "Ptr3 + 1 --> " << *(ptr3 + 1) << endl; //will now print out 1
    //Or referencing a specific element in the array
    ptr3 = &arr[2];
    cout << "Ptr3 = &arr[2] --> " << *ptr3 << endl;
                // Remember to dereference

    /*** Passing by Pointer ***/

    //You can pass in a pointer OR an address into a function
    //Uses: saves space and can change original data passed in while being a void function
    int num = 2;
    int* anotherPtr = &num;

    //these 2 function calls act the same
    ChangeOriginal(anotherPtr);
    ChangeOriginal(&num);

    /*void ChangeOriginal(int* num) {
        *num+=1;
    }*/
    cout << "Passing pointer thru function: " << num << endl;
    //if ChangeOriginal did not pass in a pointer, then the variable would not have changed


    /*** Pointers use arrows ***/
    /* class Pencil {
        int length;
    public:
        void Write();
    };*/

    Pencil no2;
    Pencil* pencilPtr = &no2;

    /*void usePencil(Pencil* p) {
        cout << "This pencil is writing" << endl;
    }*/
    cout << pencilPtr->getLength() << endl;
    cout << (*pencilPtr).getLength() << endl;

    usePencil(pencilPtr);
    cout << pencilPtr->getLength() << endl;
    cout << (*pencilPtr).getLength() << endl;

    /*** Dynamics Memory ***/
    Pencil* no3 = new Pencil();
    //Pencil no4 = new Pencil();

    //Mainly used for arrays
    Pencil* array = new Pencil[10];

    //delete before reassigning
    delete[] array;

    array = new Pencil[100];



    /*** References ***/
    //Direct references to something
    //Must be created as a definition, there is no declaration
    int a = 12;
    int &ref = a;

    //changes to a or to ref will change both
    ref++;
    cout << "a: " << a << endl;

    //Using references in functions is most always easier than using pointers
    //Why use it? Saves space
    //Use it to pass class objects
    //Can basically treat references like the actual object
    sharpenPencil(no2); //<-- don't have to specify that you want to pass in a reference
    //Only need to specify in the function parameters
    /* void sharpenPencil(Pencil& p) {
        int x = p.getLength();
        x-=2;
    } */

    //Limitations (where u should use pointers instead)
    //Cannot create an array of references
    //Cannot reassign references

    return 0;
}

