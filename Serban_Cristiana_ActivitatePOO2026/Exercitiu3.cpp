#include <iostream>
#include <string>
using namespace std;

class Produs {
    public:
        string denumire;
        double pret;
        int stoc;
        Produs() : denumire("Necunoscut"), pret(0), stoc(0) {

        }
        Produs(const string& denumire1, double pret1, int stoc1) : denumire(denumire1), pret(pret1), stoc(stoc1) {

        }
        Produs(const Produs& p) : denumire(p.denumire), pret(p.pret), stoc(p.stoc) {

        }
        void modif() {
            stoc = 5;
        }

};

int main()
{
    Produs p1("Laptop", 3500, 10);
    Produs p2(p1);
    p2.modif();
    cout << "Produs 1: " << p1.denumire << " " << p1.pret << " " << p1.stoc << endl;
    cout << "Produs 2: " << p2.denumire << " " << p2.pret << " " << p2.stoc;
}
