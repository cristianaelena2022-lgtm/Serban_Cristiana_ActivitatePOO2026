#include <iostream>
using namespace std;

class Vector {
private:
	int* elemente;
	int dimensiune;
public:
	Vector(int dimensiune1) {
		dimensiune = dimensiune1;
		elemente = new int[dimensiune] {};
	}
	~Vector() {
		delete[] elemente;
	}
	Vector(const Vector& v) {
		dimensiune = v.dimensiune;
		elemente = new int[dimensiune] {};
		for (int i = 0; i < dimensiune; i++) {
			elemente[i] = v.elemente[i];
		}
	}
	void setElement(int index, int valoare) {
		elemente[index] = valoare;
	}
	int getElement(int index) {
		return elemente[index];
	}
	int getDimensiune() {
		return dimensiune;
	}
	void afisare() {
		for (int i = 0; i < dimensiune; i++) {
			cout << elemente[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Vector v1(4);
	v1.setElement(0, 10);
	v1.setElement(1, 20);
	v1.setElement(2, 30);
	v1.setElement(3, 40);
	Vector v2(v1);
	v2.setElement(0, 99);
	cout << "Primul vector v1 este: " << endl;
	v1.afisare();
	cout << "Al doilea vector v2 este: " << endl;
	v2.afisare();
}
