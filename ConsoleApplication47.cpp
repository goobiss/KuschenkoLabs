#include <iostream>
using namespace std;
//Введення класу Node і змінних
class Node {
public:
    int data;
    Node* next;

    Node(int d = 0, Node* n = nullptr) {
        data = d;
        next = n;
    }
};
//Введення класу LinkedList і змінних
class LinkedList {
private:
    Node* head;


public:
	int size;
    //Конструктор
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    // Деструктор
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        size = 0;
    }

    // Вставлення вузлу у кінець списку
    void push_back(int data) {
        if (head == nullptr) {
            head = new Node(data, nullptr);
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(data, nullptr);
        }
        size++;
    }

    // Доступ до елемента в списку
    int& operator[](int i) {
        if (i >= size || i <0){
            throw out_of_range("Index out of bounds");
        }
        Node* current = head;
        for (int j = 0; j < i; j++) {
            current = current->next;
        }
        return current->data;
    }

    // Об’єднати два списки
    void merge(LinkedList& other) {
        if (head == nullptr) {
            head = other.head;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = other.head;
        }
        size += other.size;
        other.head = nullptr;
        other.size = 0;
    }
};

int main() {
    LinkedList list1;
    LinkedList list2;

    // Заповеннення списку 1
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    // Заповеннення списку 2
    list2.push_back(4);
    list2.push_back(5);

    // Доступ до елемента в списку
    cout << "list1[1] = " << list1[1] << endl;

    // З'єднання списку 1 і 2
    list1.merge(list2);

    // Виведення з'єднаного листа
    for (int i = 0; i < list1.size; i++) {
        cout << "list1[" << i << "] = " << list1[i] << endl;
    }

    return 0;
}
