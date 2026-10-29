#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Restaurant {
private:
	char* denumire;
	float pret;
	int gramaj;
	bool vegetarian;
	int nrIngrediente;
	string* ingrediente;
	const int id;
	static int contor;
	friend class Client;
public:
	Restaurant() : id(contor++) {
		this->denumire = new char[7];
		strcpy(this->denumire, "Andrei");
		this->pret = 100;
		this->gramaj = 50;
		this->vegetarian = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[3];
		this->ingrediente[0] = "Drojdie";
		this->ingrediente[1] = "Apa";
		this->ingrediente[2] = "Faina";
	}
	Restaurant(const char* nume, float pret1) : id(contor++) {
		this->denumire = new char[strlen(nume) + 1];
		strcpy(this->denumire, nume);
		this->pret = pret1;
		this->gramaj = 50;
		this->vegetarian = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[3];
		this->ingrediente[0] = "Drojdie";
		this->ingrediente[1] = "Apa";
		this->ingrediente[2] = "Faina";
	}
	Restaurant(const Restaurant& r) : id(contor++) {
		this->denumire = new char[strlen(r.denumire) + 1];
		strcpy(this->denumire, r.denumire);
		this->pret = r.pret;
		this->gramaj = r.gramaj;
		this->vegetarian = r.vegetarian;
		this->nrIngrediente = r.nrIngrediente;
		this->ingrediente = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++)
			this->ingrediente[i] = r.ingrediente[i];
	}
	~Restaurant() {
		delete[] this->denumire;
		delete[] this->ingrediente;
	}
	Restaurant& operator=(const Restaurant& r) {
		if (this != &r) {
			if (this->denumire != NULL)
				delete[] this->denumire;
			this->denumire = new char[strlen(r.denumire) + 1];
			strcpy(this->denumire, r.denumire);
			this->pret = r.pret;
			this->gramaj = r.gramaj;
			this->vegetarian = r.vegetarian;
			this->nrIngrediente = r.nrIngrediente;
			if (this->ingrediente != NULL)
				delete[] this->ingrediente;
			this->ingrediente = new string[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
				this->ingrediente[i] = r.ingrediente[i];
		}
		return *this;
	}
	//Restaurant operator+(float p) {
	//	Restaurant copie(*this);
	//	copie.pret += p;
	//	return copie;
	//}
	Restaurant operator+(const Restaurant& r) {
		Restaurant copie(*this);
		copie.gramaj = this->gramaj + r.gramaj;
		copie.pret = this->pret + r.pret;
		return copie;
	}
	bool operator==(const Restaurant& copie) const{
		if (strcmp(this->denumire, copie.denumire) != 0)
			return false;
		if ((this->pret != copie.pret || this->gramaj != copie.gramaj) || (this->vegetarian != copie.vegetarian || this->nrIngrediente != copie.nrIngrediente)) 
			return false;
		for (int i = 0; i < this->nrIngrediente; i++)
			if (this->ingrediente[i] != copie.ingrediente[i])
				return false;
		return true;
		
	}
	bool operator!=(const Restaurant& copie) const {
		return !(copie == *this);
	}
    int getId() const{
		return this->id;
	}
    void afisare() const{
		cout << "Numele restaurantului este: " << this->denumire << endl;
		cout << "Pretul unei mese este: " << this->pret << endl;
		cout << "Gramajul este: " << this->gramaj << endl;
		cout << "Este vegetarian- friendly? " << this->vegetarian << endl;
		cout << "Numarul de ingrediente este: " << this->nrIngrediente << endl;
		for (int i = 0; i < this->nrIngrediente; i++) {
			cout << "Ingredientul cu numarul " << i + 1 << " este: " << this->ingrediente[i] << endl;
		}
		cout << "ID-ul restaurantului este: " << getId() << endl;
	}
	float getPret() const{
		return this->pret;
	}
	int getNrIngrediente() const{
		return this->nrIngrediente;
	}
	void modificaDenumire(const char* numeNou) {
		char* copie = new char[strlen(numeNou) + 1];
		strcpy(copie, numeNou);
		delete[] this->denumire;
		this->denumire = copie;
	}
	void adaugaIngredient(const string ingd) {
		this->nrIngrediente++;
		string* copie = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente - 1; i++)
			copie[i] = this->ingrediente[i];
		copie[this->nrIngrediente - 1] = ingd;
		delete[] this->ingrediente;
		this->ingrediente = copie;
	}
	float calculeazaPretPerGram() const{
		return (this->pret / this->gramaj);
	}
	static int getContor() {
		return Restaurant::contor;
	}
};
int Restaurant::contor = 0;

float pretMediu(Restaurant* r, int nr) {
	if (nr > 0) {
		float suma = 0;
		for (int i = 0; i < nr; i++)
			suma += r[i].getPret();
		return suma / nr;
	}
	return -1;
}

class Client {
private:
	string nume;
	Restaurant preparat;
public:
	Client(const string& nume1, const Restaurant& r) : nume(nume1), preparat(r) {

	}
	void afisare() const{
		cout << "Numele clientului este: " << this->nume << endl;
		preparat.afisare();
	}
};

int main() {
	//Restaurant r("Papao", 100);
	//r.afisare();
	//r.modificaDenumire("Baobab");
	//r.afisare();
	//Restaurant r1("LaculVesel", 200);
	//r1.afisare();
	//r1 = r;
	//r1.afisare();
	//r.adaugaIngredient("Merisoare");
	//r.afisare();
	//cout << r1.calculeazaPretPerGram() << endl;
	//Restaurant r2 = r + r1;
	//r2.afisare();
	//cout << r.getPret();
	Restaurant r1("Pizza", 100);
	Restaurant r2(r1);
	if (r1 == r2)
		cout << "Sunt egale!";
	else
		cout << "Sunt diferite!";
  return 0;
}
