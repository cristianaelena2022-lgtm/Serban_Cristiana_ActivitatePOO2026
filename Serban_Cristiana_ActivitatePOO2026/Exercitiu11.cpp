#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Magazin {
private:
	char* denumire;
	double* preturi;
	int nrProduse;
	static int nrMagazine;
public:
	Magazin(const char* nume, const double* p, int nr) {
		this->denumire = new char[strlen(nume) + 1];
		strcpy(this->denumire, nume);
		this->nrProduse = nr;
		this->preturi = new double[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
			this->preturi[i] = p[i];
		Magazin::nrMagazine++;
	}
	~Magazin() {
		delete[] denumire;
		delete[] preturi;
		Magazin::nrMagazine--;
	}
	Magazin(const Magazin& m) {
		this->denumire = new char[strlen(m.denumire) + 1];
		strcpy(this->denumire, m.denumire);
		this->nrProduse = m.nrProduse;
		this->preturi = new double[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
			this->preturi[i] = m.preturi[i];
		Magazin::nrMagazine++;
	}
	void setDenumire(const char* nume) {
		char* copie = new char[strlen(nume) + 1];
		strcpy(copie, nume);
		delete[] this->denumire;
		this->denumire = copie;
	}
	void setPret(int pozitie, double pret) {
		if (pozitie >= 0 && pozitie < this->nrProduse)
			this->preturi[pozitie] = pret;
	}
	double getPret(int pozitie) {
		if (pozitie >= 0 && pozitie < this->nrProduse)
			return preturi[pozitie];
		return -1;
	}
	double getValoareTotala() {
		double suma = 0;
		for (int i = 0; i < nrProduse; i++)
			suma += this->preturi[i];
		return suma;
	}
	void afisare() {
		cout << "Magazin: " << this->denumire << ", " << "preturi: ";
		for (int i = 0; i < this->nrProduse; i++)
			cout << this->preturi[i] << ", ";
		cout << "Suma totala: " << getValoareTotala() << endl;
	}
	static int getNrMagazine() {
		return Magazin::nrMagazine;
	}
};

int Magazin::nrMagazine = 0;

int main() {
	double preturi[] = { 15.5, 30, 24.5 };
	Magazin m1("Fresh Market", preturi, 3);
	Magazin m2(m1);
	m2.setDenumire("Mini Market");
	m2.setPret(0, 20);
	m1.afisare();
	m2.afisare();
	cout << Magazin::getNrMagazine();
}
