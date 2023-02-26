#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Визначення класса студента
class Student {
public:
    string surname; // Фамілія
    string name; // Імя
    int mathGrade; // Оцінка по математиці
    int physicsGrade; // Оцінка по фізиці
    int informaticsGrade; // Оцінка по інформатиці
};

int main() {
    vector<Student> students; // Створення вектора екземплярів класу Student
    ifstream file("data.txt"); // Відкривання файлу для читання
    string line; // Змінна для зберігання рядка, що зчитується
    // Вектор екземплярів класу це вектор, елементами якого є об'єкти класу. Вектор є одним із контейнерів стандартної бібліотеки мови C++, який є динамічним масивом елементів одного типу.
    // Читання файлу построчно
    while (getline(file, line)) {
        istringstream iss(line); // Створення потоку istringstream для розбиття рядка на складові

        // Зчитування фамілії, імя і оцінок студентів
        string surname, name;
        int mathGrade, physicsGrade, informaticsGrade;
        iss >> surname >> name >> mathGrade >> physicsGrade >> informaticsGrade;

        // Створення екземпляра класу Student та додавання його до вектора
        Student student = { surname, name, mathGrade, physicsGrade, informaticsGrade };
        students.push_back(student);
    }

    // Сортування вектора студентів на прізвище та ім'я
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.surname + a.name < b.surname + b.name;
        });

    // Вивід всіх студентів та їх оцінок
    cout << "List of all students and their grades:" << endl;
    for (const auto& student : students) {
        cout << student.surname << " " << student.name << " " << student.mathGrade << " "
            << student.physicsGrade << " " << student.informaticsGrade << endl;
    }

    // Запит користувачем оцінки з фізики
    int physicsGrade;
    cout << "Enter the physics grade: ";
    cin >> physicsGrade;

    // Фільтрування студентів з оцінки з фізики та виведення відфільтрованого списку за алфавітом
    cout << "List of students with the physics grade " << physicsGrade << ":" << endl;
    for (const auto& student : students) {
        if (student.physicsGrade == physicsGrade) {
            cout << student.surname << " " << student.name << endl;
        }
    }

    return 0;
}