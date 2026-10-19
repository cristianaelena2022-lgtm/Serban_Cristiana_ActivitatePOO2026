#include <iostream>
#include <string>
using namespace std;

class Elev {
public:
	string nume;
	double medie;
	int clasa;
	Elev() : nume("Necunoscut"), medie(0), clasa(0) {

	}
	Elev(const string& nume1, double medie1, int clasa1) : nume(nume1), medie(medie1), clasa(clasa1) {

	}
	Elev(const Elev& e) : nume(e.nume), medie(e.medie), clasa(e.clasa) {

	}
};

int main()
{
	Elev e1("Maria", 9.75, 12);
	Elev e2(e1);
	cout << "Elev 1: " << e1.nume << " " << e1.medie << " " << e1.clasa << endl;
	cout << "Elev 2: " << e2.nume << " " << e2.medie << " " << e2.clasa;
}
