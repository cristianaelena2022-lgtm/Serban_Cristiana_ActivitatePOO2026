#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Angajat {
private:
	char* nume;
	float salariu;
public:
	Angajat(const char* numeNou, float salariuNou) {
		if (numeNou != nullptr) {
			this->nume = new char[strlen(numeNou) + 1];
			strcpy(this->nume, numeNou);
		}
		else {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		this->salariu = (salariuNou > 0) ? salariuNou : 0;
	}
	virtual ~Angajat() {
		delete[] this->nume;
	}
	virtual float calculVenit() {
		return this->salariu;
	}
	virtual void afisare() {
		cout << "Numele este: " << this->nume << endl;
		cout << "Salariul acestuia este: " << this->salariu << endl;
	}
};

class Manager : public Angajat {
private:
	float bonus;
public:
	Manager(const char* numeNou, float salariuNou, float bonusNou) : Angajat(numeNou, salariuNou) {
		this->bonus = (bonusNou > 0) ? bonusNou : 0;
	}
	float calculVenit() override {
		float suma = Angajat::calculVenit();
		return suma + this->bonus;
	}
	void afisare() override {
		Angajat::afisare();
		cout << "Bonusul adaugat la salariu este in valoare de: " << this->bonus << endl;
	}
};

class Programator : public Angajat {
private:
	int oreSuplimentare;
	float tarifOra;
public:
	Programator(const char* numeNou, float salariuNou, int ore, float tarif) : Angajat(numeNou, salariuNou) {
		this->oreSuplimentare = (ore > 0) ? ore : 0;
		this->tarifOra = (tarif > 0) ? tarif : 0;
	}
	float calculVenit() override {
		return (Angajat::calculVenit() + (this->oreSuplimentare * this->tarifOra));
	}
	void afisare() override {
		Angajat::afisare();
		cout << "Ore suplimentare muncite: " << this->oreSuplimentare << endl;
		cout << "Tariful pe ora este in suma de: " << this->tarifOra << endl;
	}
};

class Director : public Manager {
private:
	float bonusPerformanta;
public:
	Director(const char* numeNou, float salariuNou, float bonusNou, float performanta) : Manager(numeNou, salariuNou, bonusNou) {
		this->bonusPerformanta = (performanta > 0) ? performanta : 0;
	}
	float calculVenit() override {
		return Manager::calculVenit() + this->bonusPerformanta;
	}
	void afisare() override {
		Manager::afisare();
		cout << "Bonusul de performanta e in valoare de: " << this->bonusPerformanta << endl;
	}
};

int main() {
	Angajat** p = new Angajat * [4];
	p[0] = new Angajat("Popescu", 1000);
	p[1] = new Manager("Ciobanu", 2000, 300);
	p[2] = new Programator("Gigel", 3000, 20, 300);
	p[3] = new Director("Cristiana", 4000, 1000, 350);
	for (int i = 0; i < 4; i++) {
		p[i]->afisare();
		cout << "Venitul este: " << p[i]->calculVenit() << endl;
		cout << endl;
	}
	for (int i = 0; i < 4; i++)
		delete p[i];
	delete[] p;
}
