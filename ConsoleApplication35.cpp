#include <iostream>
#include <cmath>

using namespace std;

class Hexagon {
private:
	float sidea;
public:

	Hexagon() {
		this->sidea = 0;
	}

	Hexagon(float sidea) {
		this->sidea = sidea;
	}

	~Hexagon() {
		cout << "Constructor destroyed" << endl;
	}

	void setsidea(float sidea) {
		this->sidea = sidea;
	}

	float getsidea() {
		return this->sidea;
	}

	float getarea() {
		return ((3*sqrt(3))/2) * pow(this->sidea, 2);
	}

};

void print_sqrt(Hexagon S) {
	cout << "Sidea: " << S.getsidea() << " area: " << S.getarea() << endl;
}

int main() {
	float sidea;

	cout << "Write sidea of Hexagon: ";
	cin >> sidea;

	Hexagon a = Hexagon(sidea);
	print_sqrt(a);
}
