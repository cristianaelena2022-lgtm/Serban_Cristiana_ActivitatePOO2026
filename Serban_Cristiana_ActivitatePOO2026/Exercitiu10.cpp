#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Biblioteca {
private:
	char* nume;
	int* pagini;
	int nrCarti;
	static int nrBiblioteci;
public:
	Biblioteca(const char* n, const int* p, int nr) {
		this->nume = new char[strlen(n) + 1];
		strcpy(this->nume, n);
		this->nrCarti = nr;
		this->pagini = new int[nr];
		for (int i = 0; i < nrCarti; i++) {
			this->pagini[i] = p[i];
		}
		Biblioteca::nrBiblioteci++;
	}
	~Biblioteca() {
		delete[] this->nume;
		delete[] this->pagini;
		Biblioteca::nrBiblioteci--;
	}
	Biblioteca(const Biblioteca& b) {
		this->nume = new char[strlen(b.nume) + 1];
		strcpy(this->nume, b.nume);
		this->nrCarti = b.nrCarti;
		this->pagini = new int[this->nrCarti];
		for (int i = 0; i < this->nrCarti; i++) {
			this->pagini[i] = b.pagini[i];
		}
		Biblioteca::nrBiblioteci++;
	}
	void setNume(const char* denumire) {
		char* copie = new char[strlen(denumire) + 1];
		strcpy(copie, denumire);
		delete[] this->nume;
		this->nume = copie;
	}
	void setPagini(int pozitie, int nrPagini) {
		if (pozitie >= 0 && pozitie <= this->nrCarti - 1)
			this->pagini[pozitie] = nrPagini;
	}
	int getPagini(int pozitie) {
		if (pozitie >= 0 && pozitie <= this->nrCarti - 1)
			return this->pagini[pozitie];
		return -1;
	}
	int getTotalPagini() {
		int suma = 0;
		for (int i = 0; i < nrCarti; i++)
			suma += this->pagini[i];
		return suma;
	}
	void afisare() {
		cout << "Numele bibliotecii: " << this->nume << endl;
		for (int i = 0; i < nrCarti; i++)
			cout << "Pagina cartii " << i + 1 << " " << "este " << this->pagini[i] << endl;
		cout << "Totalul de pagini este: " << getTotalPagini() << endl;
	}
	static int getNrBiblioteci() {
		return Biblioteca::nrBiblioteci;
	}
};

int Biblioteca::nrBiblioteci = 0;

int main() {
	int pagini[] = { 250, 320, 180 };
	Biblioteca b1("Cartile mele", pagini, 3);
	Biblioteca b2(b1);
	b2.setNume("Biblioteca de studiu");
	b2.setPagini(1, 400);
	b1.afisare();
	b2.afisare();
	cout << Biblioteca::getNrBiblioteci();
}
