#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Student {
private: 
	char* nume;
	int* note;
	int nrNote;
	static int nrStudenti;
public:
	Student(const char* n, const int* no, int nr) {
		this->nume = new char[strlen(n) + 1];
		strcpy(this->nume, n);
		this->nrNote = nr;
		this->note = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++)
			this->note[i] = no[i];
		Student::nrStudenti++;
	}
	~Student() {
		delete[] nume;
		delete[] note;
		Student::nrStudenti--;
	}
	Student(const Student& s) {
		this->nume = new char[strlen(s.nume) + 1];
		strcpy(this->nume, s.nume);
		this->nrNote = s.nrNote;
		this->note = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++)
			this->note[i] = s.note[i];
		Student::nrStudenti++;
	}
	void setNume(const char* denumire) {
		char* copie = new char[strlen(denumire) + 1];
		strcpy(copie, denumire);
		delete[] this->nume;
		this->nume = copie;
	}
	void setNota(int pozitie, int valoare) {
		if (pozitie >= 0 && pozitie < this->nrNote)
			this->note[pozitie] = valoare;
	}
	inline int getMedia() {
	    int medie = 0;
		for (int i = 0; i < this->nrNote; i++)
			medie += this->note[i];
		return (medie / this->nrNote);
	}
	inline int getNotaMaxima() {
		int maxim = -1;
		for (int i = 0; i < this->nrNote; i++)
			if (this->note[i] > maxim)
				maxim = this->note[i];
		return maxim;
	}
	void afisare() {
		cout << "Numele studentului: " << this->nume << endl << "Notele studentului sunt: " << endl;
		for (int i = 0; i < this->nrNote; i++)
			cout << "Nota " << i + 1 << ": " << this->note[i] << endl;
		cout << "Media notelor studentului este: " << getMedia() << endl;
		cout << "Nota maxima a elevului este: " << getNotaMaxima() << endl;
	}
	inline static int getNrStudenti() {
		return Student::nrStudenti;
	}
};

int Student::nrStudenti = 0;

int main() {
	int note[] = { 8, 10, 7, 9 };
	Student s1("Ana", note, 4);
	Student s2(s1);
	s2.setNume("Maria");
	s2.setNota(0, 5);
	s2.setNota(1, 6);
	s2.setNota(2, 7);
	s2.setNota(3, 8);
	s1.afisare();
	s2.afisare();
	cout << Student::getNrStudenti();
}
