#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Produs {
private:
	char* nume;
	float pret;
	int cantitate;
	class DataExpirare {
	private:
		int zi;
		int luna;
		int an;
	public:
		DataExpirare(int z, int l, int a) {
			this->zi = z;
			this->luna = l;
			this->an = a;
		}
	};
	DataExpirare data;
public:
	Produs(const char* n, float p, int c, int z, int l, int a) : data(z, l, a) {
		this->nume = new char[strlen(n) + 1];
		strcpy(this->nume, n);
		this->pret = p;
		this->cantitate = c;	
	}
	Produs(const Produs& p) : data(p.data){
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->pret = p.pret;
		this->cantitate = p.cantitate;
	}
	~Produs() {
		delete[] nume;
	}
	Produs& operator=(const Produs& p){
		if (this != &p) {
			delete[] this->nume;
			this->nume = new char[strlen(p.nume) + 1];
			strcpy(this->nume, p.nume);
			this->pret = p.pret;
			this->cantitate = p.cantitate;
			this->data = p.data;
		}
		return *this;
	}
	int operator+(const Produs& p) {
		return this->cantitate + p.cantitate;
	}
	bool operator==(const Produs& p) const{
		if (strcmp(this->nume, p.nume) == 0 && (this->pret == p.pret))
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& out, const Produs& p) {
		out << "Nume: " << p.nume << ", Pret: " << p.pret;
		return out;
	}
	friend void afiseazaPret(const Produs& p) {
		cout << p.pret;
	}
};

int main() {
	Produs p1("Laptop", 2500, 3, 10, 12, 2027);
	Produs p2("Laptop", 2500, 5, 15, 1, 2028);
	Produs p3(p1);
	cout << p1 << endl;
	afiseazaPret(p1);
	cout << endl;
	cout << "Cantitate totala: " << p1 + p2 << endl;
	if (p1 == p2)
		cout << "Produsele au acelasi nume si pret" << endl;
	else
		cout << "Produsele sunt diferite" << endl;
	p3 = p2;
	cout << p3 << endl;
	return 0;
}
