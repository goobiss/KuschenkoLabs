#include <iostream>
#include <cmath>

using namespace std;

class Hexagon {
private:
	float SideA;
public:

	Hexagon() {
		this->SideA = 0;
	}

	Hexagon(float SideA) {
		this->SideA = SideA;
	}

	void setSideA(float SideA) {
		this->SideA = SideA;
	}

	float getSideA() {
		return this->SideA;
	}

	float getArea() {
		return ((3*sqrt(3))/2) * pow(this->SideA, 2);
	}
	Hexagon operator +(Hexagon& obj) {
		Hexagon a(sqrt((this->getArea() + obj.getArea()) / ((3 * sqrt(3)) / 2)));
		return a;
	}
	friend ostream& operator << (ostream& t, Hexagon& obj);
};

ostream& operator << (ostream& t, Hexagon& obj) {
	t << "SideA= " << obj.getSideA() << " | HexagonArea= " << obj.getArea();
	return t;
}

int main() {
	Hexagon a(5.0), b(2.5);
	Hexagon c = a + b;

	cout << "a = " << a << endl << "b = " << b << endl;
	cout << "c = a + b = " << c << endl;
}
