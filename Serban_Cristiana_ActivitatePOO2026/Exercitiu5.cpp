#include <iostream>
#include <string>
using namespace std;

class ContBancar {
public:
	string titular;
	double sold;
	int numarCont;
	ContBancar() : titular("Necunoscut"), sold(0), numarCont(0) {

	}
	ContBancar(const string& titular1, double sold1, int numarCont1) : titular(titular1), sold(sold1), numarCont(numarCont1) {

	}
	ContBancar(const ContBancar& c) : titular(c.titular), sold(c.sold), numarCont(c.numarCont) {

	}
	void depunere(double suma)
	{
		if (suma > 0)
			sold += suma;
		else
			cout << "Fonduri insuficiente!" << endl;
	}
	void retragere(double suma)
	{
		if (suma > 0 && suma < sold)
			sold -= suma;
		else
			cout << "Fonduri insuficiente!" << endl;
	}
	void afisare()
	{
		cout << "Titular: " << titular << endl;
		cout << "Numar cont: " << numarCont << endl;
		cout << "Sold: " << sold;
	}
};

int main()
{
	ContBancar c1("Maria", 1000, 1234);

	c1.afisare();
	cout << endl;

	c1.depunere(500);
	cout << "Sold dupa depunere: " << c1.sold << endl;

	c1.retragere(200);
	cout << "Sold dupa retragere: " << c1.sold << endl;

	c1.retragere(2000);

	ContBancar c2(c1);
	c2.depunere(100);

	cout << "\nContul 1:" << endl;
	c1.afisare();

	cout << "\n\nContul 2:" << endl;
	c2.afisare();

	return 0;
}
