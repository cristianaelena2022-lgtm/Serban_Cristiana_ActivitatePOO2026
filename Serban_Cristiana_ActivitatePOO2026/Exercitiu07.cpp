#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
	char* nume;
	double medie;
public:
	Student(const char* nume1, double medie1) {
		this->medie = medie1;
		this->nume = new char[strlen(nume1) + 1];
		strcpy(this->nume, nume1);
	}
	~Student() {
		delete[] nume;
	}
	Student(const Student& s) {
		this->medie = s.medie;
		this->nume = new char[strlen(s.nume) + 1];
		strcpy(this->nume, s.nume);
	}
	void setMedie(double medie) {
		this->medie = medie;
	}
	void setNume(const char* n) {
		delete[] this->nume;
		this->nume = new char[strlen(n) + 1];
		strcpy(this->nume, n);
	}
	double getMedie() {
		return this->medie;
	}
	string getNume() {
		return this->nume;
	}
	void afisare() {
		cout << this->nume << ", " << "media: " << this->medie << endl;
	}
};

int main() {
	Student s1("Ana", 9.5);
	Student s2(s1);
	s2.setNume("Maria");
	s2.setMedie(8);
	cout << "Studentul original: ";
	s1.afisare();
	cout << "Studentul copiat: ";
	s2.afisare();
}
