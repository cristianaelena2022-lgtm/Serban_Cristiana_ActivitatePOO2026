#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class ProdusComandat {
private:
	char* denumire;
	int cantitate;
	float pretUnitar;
	friend class Comanda;
public:
	ProdusComandat() {
		this->denumire = new char[strlen("Laptop") + 1];
		strcpy(this->denumire, "Laptop");
		this->cantitate = 1;
		this->pretUnitar = 1000;
	}
	ProdusComandat(const char* numeNou, int cantitateNoua, float pretUnitarNou) {
		this->denumire = new char[strlen(numeNou) + 1];
		strcpy(this->denumire, numeNou);
		this->cantitate = cantitateNoua;
		this->pretUnitar = pretUnitarNou;
	}
	ProdusComandat(const ProdusComandat& pc) {
		this->denumire = new char[strlen(pc.denumire) + 1];
		strcpy(this->denumire, pc.denumire);
		this->cantitate = pc.cantitate;
		this->pretUnitar = pc.pretUnitar;
	}
	~ProdusComandat() {
		delete[] this->denumire;
	}
	void setDenumireNoua(const char* nume) {
		char* copie = new char[strlen(nume) + 1];
		strcpy(copie, nume);
		delete[] this->denumire;
		this->denumire = copie;
	}
	void setCantitateNoua(int cantitateNoua) {
		this->cantitate = cantitateNoua;
	}
	void setPretUnitarNou(float pretUnitarNou) {
		this->pretUnitar = pretUnitarNou;
	}
	const char* getDenumire() const {
		return this->denumire;
	}
	int getCantitate() const{
		return this->cantitate;
	}
	float getPretUnitar() const {
		return this->pretUnitar;
	}
	float calculValoare() const{
		return this->cantitate * this->pretUnitar;
	}
	friend ostream& operator<<(ostream& out, const ProdusComandat& pc) {
		out << "Numele produsului este: " << pc.denumire << endl;
		out << "Cantitatea produsului este: " << pc.cantitate << endl;
		out << "Pretul unitar al produsului este: " << pc.pretUnitar << endl;
		return out;
	}
	ProdusComandat& operator=(const ProdusComandat& pc) {
		if (this != &pc) {
			char* copie = new char[strlen(pc.denumire) + 1];
			strcpy(copie, pc.denumire);
			delete[] this->denumire;
			this->denumire = copie;
			this->cantitate = pc.cantitate;
			this->pretUnitar = pc.pretUnitar;
		}
		return *this;
	}
};

class Comanda {
private:
	const int idComanda;
	char* numeClient;
	int nrProduse;
	ProdusComandat* produse;
	static int contor;
public:
	Comanda() : idComanda(contor++) {
		this->numeClient = new char[strlen("Cristiana") + 1];
		strcpy(this->numeClient, "Cristiana");
		this->nrProduse = 3;
		this->produse = new ProdusComandat[this->nrProduse];
		this->produse[0].denumire = new char[strlen("Oglinda") + 1];
		strcpy(this->produse[0].denumire, "Oglinda");
		this->produse[0].cantitate = 1;
		this->produse[0].pretUnitar = 30;
		this->produse[1].denumire = new char[strlen("Suc") + 1];
		strcpy(this->produse[1].denumire, "Suc");
		this->produse[1].cantitate = 4;
		this->produse[1].pretUnitar = 12;
		this->produse[2].denumire = new char[strlen("Scaun") + 1];
		strcpy(this->produse[2].denumire, "Scaun");
		this->produse[2].cantitate = 5;
		this->produse[2].pretUnitar = 65;
	}
	Comanda(const char* nume, int numar) : idComanda(contor++) {
		this->numeClient = new char[strlen(nume) + 1];
		strcpy(this->numeClient, nume);
		this->nrProduse = (numar > 0) ? numar : 0;
		this->produse = new ProdusComandat[this->nrProduse];
	}
	Comanda(const Comanda& c) : idComanda(contor++) {
		this->numeClient = new char[strlen(c.numeClient) + 1];
		strcpy(this->numeClient, c.numeClient);
		this->nrProduse = c.nrProduse;
		this->produse = new ProdusComandat[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
			this->produse[i] = c.produse[i];
	}
	~Comanda() {
		delete[] this->numeClient;
		delete[] this->produse;
	}
	void setNumeClientNou(const char* numeNou) {
		char* copie = new char[strlen(numeNou) + 1];
		strcpy(copie, numeNou);
		delete[] this->numeClient;
		this->numeClient = copie;
	}
	void setProdusNou(int index, const ProdusComandat& pc) {
		if (index >= 0 && index < this->nrProduse)
			this->produse[index] = pc;
	}
	int getIDComanda() const{
		return this->idComanda;
	}
	static int getNumarComenzi() {
		return contor;
	}
	const char* getNumeClient() const{
		return this->numeClient;
	}
	int getNrProduse() const{
		return this->nrProduse;
	}
	const ProdusComandat* getProduse() const{
		return this->produse;
	}
	float calculTotal() const{
		float suma = 0;
		for (int i = 0; i < this->nrProduse; i++)
			suma += this->produse[i].calculValoare();
		return suma;
	}
	void afisare() {
		cout << "Numele clientului sub care a fost data comanda este: " << this->numeClient << endl;
		cout << "Id-ul comenzii este: " << this->getIDComanda() << endl;
		cout << "Clientul a comandat un numar de: " << this->nrProduse << " produse " << endl;
		for (int i = 0; i < this->nrProduse; i++) {
			cout << "Produsul " << i + 1 << " este " << this->produse[i].getDenumire() << endl;
			cout << "Cantitatea acestui produs este: " << this->produse[i].getCantitate() << endl;
			cout << "Pretul unitar al acestui produs este: " << this->produse[i].getPretUnitar() << endl;
			cout << "Valoarea totala a acestui produs este: " << this->produse[i].calculValoare() << endl;
		}
		cout << "Total comanda: " << this->calculTotal() << endl;
	}
	Comanda& operator=(const Comanda& c) {
		if (this != &c) {
			char* copie = new char[strlen(c.numeClient) + 1];
			strcpy(copie, c.numeClient);
			ProdusComandat* copieProd = new ProdusComandat[c.nrProduse];
			for (int i = 0; i < c.nrProduse; i++) {
				copieProd[i] = c.produse[i];
			}
			delete[] this->numeClient;
			delete[] this->produse;
			this->numeClient = copie;
			this->produse = copieProd;
			this->nrProduse = c.nrProduse;
		}
		return *this;
	}
	bool operator==(const Comanda& c) const {
		return (this->idComanda == c.idComanda);
	}
	Comanda& operator+=(const ProdusComandat& pc) {
		ProdusComandat* copie = new ProdusComandat[this->nrProduse + 1];
		for (int i = 0; i < this->nrProduse; i++)
			copie[i] = this->produse[i];
		copie[this->nrProduse] = pc;
		delete[] this->produse;
		this->produse = copie;
		this->nrProduse++;
		return (*this);
	}
	bool operator!() const {
		return (this->nrProduse == 0);
	}
	friend ostream& operator<<(ostream& out, const Comanda& c) {
		out << "Numele clientului: " << c.numeClient << endl;
		out << "ID comanda: " << c.idComanda << endl;
		out << "Numar produse: " << c.nrProduse << endl;
        for (int i = 0; i < c.nrProduse; i++) {
			out << c.produse[i] << endl;
		}
        out << "Total comanda: " << c.calculTotal() << endl;
        return out;
	}
};
int Comanda::contor = 0;

int main() {
	cout << "===== TESTARE PRODUS COMANDAT =====\n";
	ProdusComandat p1("Laptop", 2, 3500);
	ProdusComandat p2("Mouse", 3, 100);
	cout << p1 << endl;
	cout << p2 << endl;
	cout << "Valoare produs 1: " << p1.calculValoare() << endl;
	ProdusComandat p3 = p1; // Constructor de copiere
	cout << "\nCopie produs:\n" << p3 << endl;
	p3.setCantitateNoua(5);
	cout << "Produs original:\n" << p1 << endl;
	cout << "Produs modificat:\n" << p3 << endl;
	cout << "\n===== TESTARE COMANDA =====\n";
	Comanda c1("Criss", 2);
	c1.setProdusNou(0, p1);
	c1.setProdusNou(1, p2);
	cout << "\nComanda initiala:\n" << c1 << endl;
	cout << "Total comanda: " << c1.calculTotal() << endl;
	cout << "\n===== TESTARE OPERATOR += =====\n";
	ProdusComandat p4("Tastatura", 1, 250);
	c1 += p4;
	cout << c1 << endl;
	cout << "\n===== TESTARE OPERATOR ! =====\n";
	Comanda c2;
	if (!c2) {
		cout << "Comanda este goala.\n";
	}
	else {
		cout << "Comanda contine produse.\n";
	}
	cout << "\n===== TESTARE OPERATOR == =====\n";
	Comanda c3 = c1;
	if (c1 == c3) {
		cout << "Comenzile au acelasi ID.\n";
	}
	cout << "\n===== TESTARE OPERATOR = =====\n";
	Comanda c4;
	c4 = c1;
	cout << "Comanda copiata prin operatorul =:\n";
	cout << c4 << endl;
	cout << "\n===== TESTARE DEEP COPY =====\n";
	c4 += ProdusComandat("Monitor", 2, 800);
	cout << "Comanda originala:\n" << c1 << endl;
	cout << "Comanda modificata:\n" << c4 << endl;
	cout << "\n===== NUMAR COMENZI CREATE =====\n";
	cout << Comanda::getNumarComenzi() << endl;
	return 0;
}
