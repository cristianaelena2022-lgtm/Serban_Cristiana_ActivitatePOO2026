#include <iostream>
using namespace std;

class Dreptunghi {
public:
	double lungime;
	double latime;
	Dreptunghi() : lungime(1), latime(1) {

	}
	Dreptunghi(double lungime1, double latime1) : lungime(lungime1), latime(latime1) {

	}
	double calcul_arie() {
		double arie = latime * lungime;
		return arie;
	}
	double calcul_perimetru() {
		double perimetru = 2 * (lungime + latime);
		return perimetru;
	}
};

int main()
{
	Dreptunghi d(5, 3);
	cout << "Aria: " << d.calcul_arie() << endl;
	cout << "Perimetru: " << d.calcul_perimetru();
}
