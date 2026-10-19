#include <iostream>
#include <string>
using namespace std;

class Carte {
   public:
	   string nume;
	   int nrPagini;
	   Carte() : nume("Necunoscuta"), nrPagini(0) {

	   }
	   Carte(const string& nume1, int nrPagini1) : nume(nume1), nrPagini(nrPagini1) {

	   }
};

int main()
{
	Carte c1;
	Carte c2("Ion", 200);
	Carte c3("Baltagul", 150);
	cout << "Cartea 1: " << c1.nume << "," << c1.nrPagini << endl;
	cout << "Cartea 2: " << c2.nume << "," << c2.nrPagini << endl;
	cout << "Cartea 3: " << c3.nume << "," << c3.nrPagini;
}
