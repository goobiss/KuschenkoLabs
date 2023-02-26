#include <iostream>

using namespace std;
//Клас що знаходиться зверху ієрархії (продукт)
class Product { 
public:
    Product() {
        cout << "Product constructor called" << endl;
    }
    virtual ~Product() {
        cout << "Product destructor called" << endl;
    }
};
//virtual- це функція, яка може бути перевизначена у класах - ніслідниках.
//Класи нижче "Підкорюються" класу "Product" Клас іграшки
class Toy : public Product {
public:
    Toy() {
        cout << "Toy constructor called" << endl;
    }
    ~Toy() {
        cout << "Toy destructor called" << endl;
    }
};
//Клас молочний продукт
class DairyProduct : public Product {
public:
    DairyProduct() {
        cout << "DairyProduct constructor called" << endl;
    }
    ~DairyProduct() {
        cout << "DairyProduct destructor called" << endl;
    }
};
//Клас товар
class Goods : public Product { 
public:
    Goods() {
        cout << "Goods constructor called" << endl;
    }
    ~Goods() {
        cout << "Goods destructor called" << endl;
    }
};
//головна функція
int main() {
    Toy toy;
    DairyProduct milk;
    Goods goods;
    return 0;
}