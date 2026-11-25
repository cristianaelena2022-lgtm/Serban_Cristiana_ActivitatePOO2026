#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Vehicul {
private:
	char* marca;
	int viteza;
public:
	Vehicul(const char* marcaNoua, int vitezaNoua) {
		if (marcaNoua != nullptr) {
			this->marca = new char[strlen(marcaNoua) + 1];
			strcpy(this->marca, marcaNoua);
		}
		else {
			this->marca = new char[strlen("Necunoscuta") + 1];
			strcpy(this->marca, "Necunoscuta");
		}
		this->viteza = (vitezaNoua > 0) ? vitezaNoua : 0;
	}
	virtual ~Vehicul(){
		delete[] this->marca;
	}
	virtual void afisare() {
		cout << "Marca vehiculului este: " << this->marca << endl;
		cout << "Viteza vehiculului este: " << this->viteza << endl;
	}
};

class Masina : public Vehicul {
private:
	int nrUsi;
public:
	Masina(const char* marcaNoua, int vitezaNoua, int numar) : Vehicul(marcaNoua, vitezaNoua) {
		this->nrUsi = (numar > 0) ? numar : 0;
	}
	void afisare() override {
		Vehicul::afisare();
		cout << "Numarul de usi ale masinii este: " << this->nrUsi << endl;
	}
};

class Motocicleta : public Vehicul {
private:
	bool areAtas;
public:
	Motocicleta(const char* marcaNoua, int vitezaNoua, bool variabila) : Vehicul(marcaNoua, vitezaNoua) {
		this->areAtas = variabila;
	}
	void afisare() override {
		Vehicul::afisare();
		cout << "Are atas? (0/1): " << this->areAtas << endl;
	}
};

class MasinaElectrica : public Masina {
private:
	float autonomie;
public:
	MasinaElectrica(const char* marcaNoua, int vitezaNoua, int numarNou, float valoare) : Masina(marcaNoua, vitezaNoua, numarNou) {
		this->autonomie = (valoare > 0) ? valoare : 0;
	}
	void afisare() override {
		Masina::afisare();
		cout << "Autonomia masinii este in numar de: " << this->autonomie << endl;
	}
};

int main() {
	Vehicul** p = new Vehicul*[3];
	p[0] = new Masina("BMW", 11000, 4);
	p[1] = new Motocicleta("Audi", 12000, 1);
	p[2] = new MasinaElectrica("Lamborghini", 14000, 2, 45);
	for (int i = 0; i < 3; i++) {
		cout << "----------Vehiculul " << i + 1 << "---------------" << endl;
		p[i]->afisare();
		cout << "------------------------------------";
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
		delete p[i];
	delete[] p;
}
