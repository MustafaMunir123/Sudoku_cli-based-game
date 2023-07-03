#include <iostream>
#include <string>

using namespace std;

class B{
    public:
    string name;

    public:
    B(){};
    B(string name): name(name) {};
};

class A {
    public:
    B *arr;

    public:
    A(){
        arr = new B[2];
    }
    void createB(){
        // B *array[2];
        for (int i=0; i<2; i++){
            string name;
            cin >> name;
            arr[i] =  B(name);
        }

        for (int i=0; i<2; i++){
            cout << arr[i].name;
        }
    }

};


int main(){
    A a;
    a.createB();

    return 0;
}