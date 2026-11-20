#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Laptop {
private:
	char* marca;
	float pret;
	int ram;
public:
	Laptop() {
		this->marca = new char[strlen("Samsung") + 1];
		strcpy(this->marca, "Samsung");
		this->pret = 15000;
		this->ram = 12;
	}
	Laptop(const char* denumire, float pretNou, int RAM) {
		if (denumire != nullptr) {
			this->marca = new char[strlen(denumire) + 1];
			strcpy(this->marca, denumire);
		}
		else {
			this->marca = new char[strlen("Necunoscuta") + 1];
			strcpy(this->marca, "Necunoscuta");
		}
		this->pret = (pretNou > 0) ? pretNou : 0;
		this->ram = (RAM > 0) ? RAM : 0;
	}
	Laptop(const Laptop& l) {
		this->marca = l.marca;
		this->pret = l.pret;
		this->ram = l.ram;
	}
	~Laptop() {
		delete[] this->marca;
	}
	void afisare() const {
		cout << "Marca: " << this->marca << endl;
		cout << "Pretul: " << this->pret << endl;
		cout << "Ram: " << this->ram << endl;
	}
};

int main() {
	Laptop* p_laptop = new Laptop[3];
	for (int i = 0; i < 3; i++) {
		p_laptop[i].afisare();
		cout << endl;
	}
	delete[] p_laptop;
	p_laptop = nullptr;
	Laptop** pp_laptop = new Laptop*[2];
	for (int i = 0; i < 2; i++)
		pp_laptop[i] = new Laptop("Huawei", 10000, 4);
	for (int i = 0; i < 2; i++) {
		pp_laptop[i]->afisare();
		cout << endl;
	}
	for (int i = 0; i < 2; i++)
		delete[] pp_laptop[i];
	delete[] pp_laptop;
	pp_laptop = nullptr;
}
