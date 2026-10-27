#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Comanda {
private:
	int id;
	float valoare;
	class AdresaLivrare {
	private:
		char* oras;
		int codPostal;
	public:
		AdresaLivrare(const char* nume, int cod) {
			this->oras = new char[strlen(nume) + 1];
			strcpy(this->oras, nume);
			this->codPostal = cod;
		}
		~AdresaLivrare() {
			delete[] this->oras;
		}
		AdresaLivrare(const AdresaLivrare& a) {
			this->oras = new char[strlen(a.oras) + 1];
			strcpy(this->oras, a.oras);
			this->codPostal = a.codPostal;
		}
		AdresaLivrare& operator=(const AdresaLivrare& a) {
			if (this != &a) {
				delete[] this->oras;
				this->oras = new char[strlen(a.oras) + 1];
				strcpy(this->oras, a.oras);
				this->codPostal = a.codPostal;
			}
			return *this;
		}
	};
	AdresaLivrare adresa;
public:
	Comanda(int id1, float valoare1, const char* nume1, int cod1) : adresa(nume1, cod1) {
		this->id = id1;
		this->valoare = valoare1;
	}
	Comanda(const Comanda& c) : adresa(c.adresa) {
		this->id = c.id;
		this->valoare = c.valoare;
	}
	~Comanda() {

	}
	Comanda& operator=(const Comanda& c) {
		if (this != &c) {
			this->id = c.id;
			this->valoare = c.valoare;
			this->adresa = c.adresa;
		}
		return *this;
	}
	float operator+(const Comanda& c) {
		return this->valoare + c.valoare;
	}
	bool operator==(const Comanda& c) const {
		return (this->id == c.id);
	}
	friend ostream& operator<<(ostream& out, const Comanda& c) {
		out << "Id-ul comenzii este: " << c.id << endl << "Valoarea comenzii este: " << c.valoare << endl;
		return out;
	}
	friend bool comandaMare(const Comanda& c) {
		if (c.valoare > 500)
			return true;
		else
			return false;
	}
};

int main() {
	Comanda c1(101, 350, "Bucuresti", 110101);
	Comanda c2(102, 700, "Cluj", 400001);
	cout << c1;
	cout << c2;
	Comanda c3(c1);
	c2 = c3;
	cout << c3;
	if (c3 == c2)
		cout << "Este aceeasi comanda!";
	else
		cout << "Sunt comenzi diferite!";
	cout << c1 + c2 << endl;
	Comanda c4(101, 900, "Iasi", 700001);
	if(c4 == c1)
		cout << "Este aceeasi comanda!";
	else
		cout << "Sunt comenzi diferite!";
	comandaMare(c1);
	comandaMare(c2);
	c1 = c1;
	cout << c1;
	return 0;
}
