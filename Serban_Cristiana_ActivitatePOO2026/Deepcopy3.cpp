#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class ContBancar {
private:
	char* titular;
	double sold;
public:
	ContBancar(const char* nume, double suma) {
		sold = suma;
		titular = new char[strlen(nume) + 1];
		strcpy(titular, nume);
	}
	~ContBancar() {
		delete[] titular;
	}
	ContBancar(const ContBancar& b) {
		sold = b.sold;
		titular = new char[strlen(b.titular) + 1];
		strcpy(titular, b.titular);
	}
	void depunere(double suma) {
		if (suma > 0)
			sold += suma;
	}
	void retragere(double suma) {
		if (suma > 0 && suma <= sold)
			sold -= suma;
	}
	void afisare() {
		cout << "Titularul este: " << titular << ", " << "Sold: " << sold << endl;
	}
};

int main() {
	ContBancar c1("Ana", 1000);
	c1.depunere(500);
	c1.retragere(200);
	ContBancar c2(c1);
	c2.depunere(300);
	c1.afisare();
	c2.afisare();
}
