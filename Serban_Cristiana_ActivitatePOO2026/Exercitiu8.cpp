#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Carte {
private:
	char* titlu;
	int numarPagini;
public:
	Carte(const char* nume, int pagini) {
		this->numarPagini = pagini;
		this->titlu = new char[strlen(nume) + 1];
		strcpy(this->titlu, nume);
	}
	~Carte() {
		delete[] titlu;
	}
	Carte(const Carte& c) {
		this->numarPagini = c.numarPagini;
		this->titlu = new char[strlen(c.titlu) + 1];
		strcpy(this->titlu, c.titlu);
	}
	void setTitlu(const char* titlu) {
		char* copie = new char[strlen(titlu) + 1];
		strcpy(copie, titlu);
		delete[] this->titlu;
		this->titlu = copie;
	}
	void setNumarPagini(int numarPagini) {
		this->numarPagini = numarPagini;
	}
	string getTitlu() {
		return this->titlu;
	}
	int getNumarPagini() {
		return this->numarPagini;
	}
	void afisare() {
		cout << this->titlu << ", " << "Numar Pagini: " << this->numarPagini << endl;
	}
};

int main() {
	Carte c1("Baltagul", 180);
	Carte c2(c1);
	c2.setTitlu("Ion");
	c2.setNumarPagini(250);
	cout << "Cartea 1: ";
	c1.afisare();
	cout << "Cartea 2: ";
	c2.afisare();
	return 0;
}
