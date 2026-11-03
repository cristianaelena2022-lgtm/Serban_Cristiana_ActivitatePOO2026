#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class Portofel {
private:
	char* proprietar;
	float sold;
	int nrTranzactii;
	float* tranzactii;
	const int idPortofel;
	static int contor;
public:
	Portofel() : idPortofel(contor++) {
		this->proprietar = new char[strlen("Serban Cristiana-Elena") + 1];
		strcpy(this->proprietar, "Serban Cristiana-Elena");
		this->sold = 10000;
		this->nrTranzactii = 4;
		this->tranzactii = new float[this->nrTranzactii];
		for (int i = 0; i < this->nrTranzactii; i++)
			this->tranzactii[i] = 20;
	}
	Portofel(const char* nume, float soldNou, int tranzactie) : idPortofel(contor++){
		this->proprietar = new char[strlen(nume) + 1];
		strcpy(this->proprietar, nume);
		this->sold = soldNou;
		this->nrTranzactii = tranzactie;
		this->tranzactii = new float[this->nrTranzactii];
		for (int i = 0; i < this->nrTranzactii; i++)
			this->tranzactii[i] = 0;
	}
	Portofel(const Portofel& p) : idPortofel(contor++) {
		this->proprietar = new char[strlen(p.proprietar) + 1];
		strcpy(this->proprietar, p.proprietar);
		this->sold = p.sold;
		this->nrTranzactii = p.nrTranzactii;
		this->tranzactii = new float[this->nrTranzactii];
		for (int i = 0; i < this->nrTranzactii; i++)
			this->tranzactii[i] = p.tranzactii[i];
	}
	~Portofel() {
		delete[] this->proprietar;
		delete[] this->tranzactii;
	}
	float operator+(float valoare) {
		return this->sold + valoare;
	}
	float operator+(const Portofel& p) const{
		return this->sold + p.sold;
	}
	float operator-(float valoare) {
		if (this->sold > valoare)
			return this->sold - valoare;
		else
			return 0;
	}
	float operator-(const Portofel& p) const{
		if (this->sold > p.sold)
			return this->sold - p.sold;
		else
			return 0;
	}
	Portofel& operator+=(float valoare) {
		this->sold += valoare;
		return *this;
	}
	Portofel& operator-=(float valoare) {
		if (this->sold > valoare) 
			this->sold -= valoare;
		return *this;
	}
	Portofel& operator++() {
		this->sold = this->sold + 1;
		return *this;
	}
	Portofel operator++(int) {
		Portofel p = (*this);
		this->sold = this->sold + 1;
		return p;
	}
	Portofel& operator--() {
		this->sold = this->sold - 1;
		return *this;
	}
	Portofel operator--(int) {
		Portofel p = (*this);
		this->sold = this->sold - 1;
		return p;
	}
	bool operator==(const Portofel& p) const {
		return (this->sold == p.sold);
	}
	bool operator>(const Portofel& p) const {
		return (this->sold > p.sold);
	}
	bool operator<(const Portofel& p) const {
		return (this->sold < p.sold);
	}
	bool operator!() const {
		return (this->sold == 0);
	}
	friend ostream& operator<<(ostream& out, const Portofel& p) {
		out << "Numele proprietarului este: " << p.proprietar << endl;
		out << "Soldul portofelului este: " << p.sold << endl;
		out << "Numarul tranzactiilor este: " << p.nrTranzactii << endl;
		return out;
	}
	Portofel& operator=(const Portofel& p) {
		if (this != &p) {
			char* copie = new char[strlen(p.proprietar) + 1];
			strcpy(copie, p.proprietar);
			delete[] this->proprietar;
			this->proprietar = copie;
			this->sold = p.sold;
			this->nrTranzactii = p.nrTranzactii;
			float* copieTranz = new float[this->nrTranzactii];
			for (int i = 0; i < this->nrTranzactii; i++)
				copieTranz[i] = p.tranzactii[i];
			delete[] this->tranzactii;
			this->tranzactii = copieTranz;
		}
		return *this;
	}
	bool operator!=(const Portofel& p) const {
		return !(*this == p);
	}
	float& operator[](int index) {
		if (index >= 0 && index < this->nrTranzactii)
			return this->tranzactii[index];
		throw out_of_range("Index invald!");
	}
	float operator[](int index) const {
		if (index >= 0 && index < this->nrTranzactii)
			return this->tranzactii[index];
		throw out_of_range("Index invald!");
	}
	bool operator()(float suma) {
		if (this->sold >= suma && suma > 0) {
			this->sold -= suma;
			return true;
		}
		else
			return false;
	}
	friend istream& operator>>(istream& in, Portofel& p) {
		string nume;
		in >> nume;
		char* copie = new char[nume.size() + 1];
		strcpy(copie, nume.c_str());
		delete[] p.proprietar;
		p.proprietar = copie;
		in >> p.sold;
		return in;
	}
};
