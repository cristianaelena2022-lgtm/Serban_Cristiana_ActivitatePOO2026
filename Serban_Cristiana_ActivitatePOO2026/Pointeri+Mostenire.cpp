#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Carte {
private:
	char* titlu;
	char* autor;
	int nrPagini;
	float pret;
public:
	Carte() {
		this->titlu = new char[strlen("Necunoscut") + 1];
		strcpy(this->titlu, "Necunoscut");
		this->autor = new char[strlen("Necunoscut") + 1];
		strcpy(this->autor, "Necunoscut");
		this->nrPagini = 0;
		this->pret = 0;
	}
	Carte(const char* titlu1, const char* nume, int numar, float suma) {
		if (titlu1 != nullptr) {
			this->titlu = new char[strlen(titlu1) + 1];
			strcpy(this->titlu, titlu1);
		}
		else {
			this->titlu = new char[strlen("Necunoscut") + 1];
			strcpy(this->titlu, "Necunoscut");
		}
		if (nume != nullptr) {
			this->autor = new char[strlen(nume) + 1];
			strcpy(this->autor, nume);
		}
		else {
			this->autor = new char[strlen("Necunoscut") + 1];
			strcpy(this->autor, "Necunoscut");
		}
		this->nrPagini = (numar > 0) ? numar : 0;
		this->pret = (suma > 0) ? suma : 0;
	}
	Carte(const Carte& c) {
		this->titlu = new char[strlen(c.titlu) + 1];
		strcpy(this->titlu, c.titlu);
		this->autor = new char[strlen(c.autor) + 1];
		strcpy(this->autor, c.autor);
		this->nrPagini = c.nrPagini;
		this->pret = c.pret;
	}
	virtual ~Carte() {
		delete[] this->titlu;
		delete[] this->autor;
 	}
	char* getTitlu() const{
		return this->titlu;
	}
	char* getAutor() const {
		return this->autor;
	}
	int getNrPagini() const {
		return this->nrPagini;
	}
	float getPret() const {
		return this->pret;
	}
	virtual void afisare() const {
		cout << "Titlu: " << this->titlu << endl;
		cout << "Autor: " << this->autor << endl;
		cout << "Nr pagini: " << this->nrPagini << endl;
		cout << "Pret: " << this->pret << endl;
	}
	Carte& operator=(const Carte& c) {
		if (this != &c) {
			if(this->titlu != nullptr)
				delete[] this->titlu;
			char* copieTitlu = new char[strlen(c.titlu) + 1];
			strcpy(copieTitlu, c.titlu);
			this->titlu = copieTitlu;
			if(this->autor != nullptr)
				delete[] this->autor;
			char* copieAutor = new char[strlen(c.autor) + 1];
			strcpy(copieAutor, c.autor);
			this->autor = copieAutor;
			this->nrPagini = (c.nrPagini > 0) ? c.nrPagini : 0;
			this->pret = (c.pret > 0) ? c.pret : 0;
		}
		return *this;
	}
	Carte& operator+=(float valoare) {
		if (valoare >= 0) {
			this->pret += valoare;
		}
		return *this;
	}
	bool operator==(const Carte& c) const {
		if (strcmp(this->titlu, c.titlu) != 0)
			return 0;
		if (strcmp(this->autor, c.autor) != 0)
			return 0;
		if (this->nrPagini != c.nrPagini)
			return 0;
		if (this->pret != c.pret)
			return 0;
		return 1;
	}
	void setTitlu(const char* nume) {
		if (this->titlu != nullptr) {
			char* copieTitlu = new char[strlen(nume) + 1];
			strcpy(copieTitlu, nume);
			delete[] this->titlu;
			this->titlu = copieTitlu;
		}
	}
};

class CarteDigitala : public Carte{
private:
	char* format;
	float dimensiuneMB;
	bool areProtectie;
public:
	CarteDigitala() : Carte() {
		this->format = new char[strlen("Necunoscut") + 1];
		strcpy(this->format, "Necunoscut");
		this->dimensiuneMB = 0;
		this->areProtectie = true;
	}
	CarteDigitala(const char* formatNou, float dimensiuneNoua, bool protectie, const char* titluNou, const char* autorNou, int numar, float suma) : Carte(titluNou, autorNou, numar, suma) {
		if (formatNou != nullptr) {
			this->format = new char[strlen(formatNou) + 1];
			strcpy(this->format, formatNou);
		}
		else {
			this->format = new char[strlen("Necunoscut") + 1];
			strcpy(this->format, "Necunoscut");
		}
		this->dimensiuneMB = (dimensiuneNoua > 0) ? dimensiuneNoua : 0;
		this->areProtectie = protectie;
	}
	CarteDigitala(const CarteDigitala& cd) : Carte(cd) {
		this->format = new char[strlen(cd.format) + 1];
		strcpy(this->format, cd.format);
		this->dimensiuneMB = cd.dimensiuneMB;
		this->areProtectie = cd.areProtectie;
	}
	~CarteDigitala() {
		delete[] this->format;
	}
	char* getFormat() const {
		return this->format;
	}
	float getDimensiune() const {
		return this->dimensiuneMB;
	}
	bool getProtectie() const{
		return this->areProtectie;
	}
	void afisare() const override {
		cout << "---------------------------------" << endl;
		cout << "Titlu: " << getTitlu() << endl;
		cout << "Autor: " << getAutor() << endl;
		cout << "Nr pagini: " << getNrPagini() << endl;
		cout << "Pret: " << getPret() << endl;
		cout << "Format: " << this->format << endl;
		cout << "Dimensiune: " << this->dimensiuneMB << endl;
		cout << "Protectie: " << this->areProtectie << endl;
		cout << "---------------------------------" << endl;
	}
	CarteDigitala& operator=(const CarteDigitala& cd) {
		if (this != &cd) {
			Carte::operator=(cd);
			if(this->format != nullptr)
				delete[] this->format;
			char* copieFormat = new char[strlen(cd.format) + 1];
			strcpy(copieFormat, cd.format);
			this->format = copieFormat;
			this->dimensiuneMB = cd.dimensiuneMB;
			this->areProtectie = cd.areProtectie;
		}
		return *this;
	}
	CarteDigitala& operator+=(float valoare) {
		if (valoare >= 0) {
			this->dimensiuneMB += valoare;
		}
		return *this;
	}
};

int main() {
	Carte c1("Enigma Otiliei", "George Calinescu", 456, 35);
	Carte c2(c1);
	CarteDigitala cd1("Pixeli", 51, true, "Vrajitorul din Oz", "Poki", 567, 46);
	CarteDigitala cd2("Hartie", 32, false, "Ion", "Liviu Rebreanu", 346, 39);
	CarteDigitala cd3(cd1);
	CarteDigitala cd4 = cd2;
	c1.afisare();
	cd1.afisare();
	//cd2.afisare();
	//cd3.afisare();
	//cd4.afisare();
	c1 += 100;
	cd1 += 57;
	c1.afisare();
	cd1.afisare();
	c2.setTitlu("Bombonica");
	if (c1 == c2)
		cout << "Cartile sunt identice!" << endl;
	else
		cout << "Cartile sunt diferite!" << endl;
	Carte* c = new CarteDigitala("PDF", 12.5, true, "POO", "Autor", 300, 75);
	c->afisare();
	delete c;
}
