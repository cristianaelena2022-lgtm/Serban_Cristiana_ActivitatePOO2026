#include <iostream>
using namespace std;

class Numar {
public:
	int* valoare;
	Numar(int numar) {
		valoare = new int(numar);
	}
	~Numar() {
		delete valoare;
	}
	Numar(const Numar& n) {
		valoare = new int(*n.valoare);
	}
	void setValoare(int v) {
		*valoare = v;
	}
	int getValoare() {
		return *valoare;
	}
};

int main() {
	Numar n1(10);
	Numar n2(n1);
	n2.setValoare(20);
	cout << "Valoare 1: " << n1.getValoare() << endl;
	cout << "Valoarea 2: " << n2.getValoare();
}
