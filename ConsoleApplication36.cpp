#include <iostream>
#include <cstdlib>
using namespace std;
int i;
class Array {
    int* m;
    int n;
public:
    Array(int k) {
        cout << "Constructor with parametr" << endl;
        this-> n = k;
        this-> m = new int[this->n];
        set_data();
    }
    ~Array() {
        delete this->m;
        cout << "\nDestructor." << endl;
    }
    void set_data() {
        for (i = 0; i < this->n; i++) {
            if (i % 2 == 0) {
                this-> m[i] = i - 2;
            }
            else {
                this-> m[i] = i + 5;
            }
        }
        output();
    }
    void output() {
        cout << "Vsi elementi: " << endl;
        for (i = 0; i < this->n; i++) {
            cout << this->m[i] << " ";
        }
    }

    friend void sum(Array obj);
};
void sum(Array obj) {
    int sum = 0;
    cout << "\nNeparni elements: " << obj.m << "\n";
    for (i = 0; i < obj.n; i++) {
        if ((obj.m[i] % 2) == 1) {
            cout << obj.m[i] << " ";
            sum = sum + obj.m[i];
        }
    } cout << endl;
    cout << "Summa neparnih elementiv: " << sum;
}
int main() {
    Array arr(9);
    sum(arr);
    system("pause");
    return 0;
}