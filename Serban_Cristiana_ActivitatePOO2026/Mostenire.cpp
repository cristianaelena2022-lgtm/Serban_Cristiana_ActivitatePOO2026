#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Angajat {
private:
	char* nume;
	int varsta;
	float salariu;
public:
	Angajat() {
		this->nume = new char[strlen("Popica") + 1];
		strcpy(this->nume, "Popica");
		this->varsta = 45;
		this->salariu = 10000;
	}
	Angajat(const char* numeNou, int varstaNoua, float salariuNou) {
		if (numeNou != nullptr) {
			this->nume = new char[strlen(numeNou) + 1];
			strcpy(this->nume, numeNou);
		}
		else {
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		this->varsta = (varstaNoua > 0) ? varstaNoua : 0;
		this->salariu = (salariuNou > 0) ? salariuNou : 0;
	}
	Angajat(const Angajat& a) {
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
		this->varsta = a.varsta;
		this->salariu = a.salariu;
	}
	~Angajat() {
		delete[] this->nume;
	}
	char* getNume() const{
		return this->nume;
	}
	int getVarsta() const {
		return this->varsta;
	}
	float getSalariu() {
		return this->salariu;
	}
	void afisare() const {
		cout << "Numele angajatului este: " << this->nume << endl;
		cout << "Varsta angajatului este: " << this->varsta << endl;
		cout << "Salariul angajatului este: " << this->salariu << endl;
	}
	Angajat& operator=(const Angajat& a) {
		if (this != &a) {
			delete[] this->nume;
			char* copieNume = new char[strlen(a.nume) + 1];
			strcpy(copieNume, a.nume);
			this->nume = copieNume;
			this->varsta = a.varsta;
			this->salariu = a.salariu;
		}
		return *this;
	}
};

class Manager : public Angajat {
private: 
	char* departament;
	int nrSubordonati;
public:
	Manager() : Angajat(){
		this->departament = new char[strlen("Departamentul 1:") + 1];
		strcpy(this->departament, "Departamentul 1");
		this->nrSubordonati = 100;
	}
	Manager(const char* departamenteNoi, int numere, const char* numeNou, int varstaNou, float suma) : Angajat(numeNou, varstaNou, suma) {
		if (departamenteNoi != nullptr) {
			this->departament = new char[strlen(departamenteNoi) + 1];
			strcpy(this->departament, departamenteNoi);
		}
		else {
			this->departament = new char[strlen("Necunoscut") + 1];
			strcpy(this->departament, "Necunoscut");
		}
		this->nrSubordonati = (numere > 0) ? numere : 0;
	}
	Manager(const Manager& m) : Angajat(m) {
		this->departament = new char[strlen(m.departament) + 1];
		strcpy(this->departament, m.departament);
		this->nrSubordonati = m.nrSubordonati;
	}
	~Manager(){
		delete[] this->departament;
	}
	char* getDepartament() const {
		return this->departament;
	}
	int getNrSubordonati() const {
		return this->nrSubordonati;
	}
	void afisare(){
		cout << "Numele: " << getNume() << endl;
		cout << "Varsta: " << getVarsta() << endl;
		cout << "Salariul: " << getSalariu() << endl;
		cout << "Departament: " << getDepartament() << endl;
		cout << "Subordonati: " << getNrSubordonati() << endl;
	}
	Manager& operator=(const Manager& m) {
		if (this != &m) {
			Angajat::operator=(m);
			delete[] this->departament;
			char* copieDepartamente = new char[strlen(m.departament) + 1];
			strcpy(copieDepartamente, m.departament);
			this->departament = copieDepartamente;
			this->nrSubordonati = m.nrSubordonati;
		}
		return *this;
	}
};

int main() {
	Angajat a1("Bibilica", 23, 4500);
	Manager m1("Departament 2", 34, "Ionica", 37, 12000);
	a1.afisare();
	m1.afisare();
	Manager m2(m1);
	Manager m3("Departament 3", 35, "Anabanana", 41, 8000);
	Manager m4 = m3;
	m2.afisare();
	m3.afisare();
	m4.afisare();
}
