#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Telefon {
private:
	float rezolutie;
	float memorie;
	string model;
	char* producator;
	float pret;
	int nrAplicatii;
	float* memorieAplicatii;
	const int id;
	static int contor;
public:
	Telefon(float rezolutie, float memorie, string model, const char* producator,
		float pret, int nrAplicatii, const float* memorieAplicatii) :id(contor++) {
		this->rezolutie = rezolutie;
		this->memorie = memorie;
		this->model = model;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		this->pret = pret;
		this->nrAplicatii = nrAplicatii;
		this->memorieAplicatii = new float[nrAplicatii];
		for (int i = 0;i < this->nrAplicatii;i++)
			this->memorieAplicatii[i] = memorieAplicatii[i];
	}
	Telefon() : id(contor++)
	{
		this->rezolutie = 5.3;
		this->memorie = 128;
		this->model = "Iphone 17";
		this->producator = new char[strlen("Apple") + 1];
		strcpy_s(producator, strlen("Apple") + 1, "Apple");
		this->pret = 4000;
		this->nrAplicatii = 5;
		this->memorieAplicatii = new float[this->nrAplicatii];
		this->memorieAplicatii[0] = 2;
		this->memorieAplicatii[1] = 3;
		this->memorieAplicatii[2] = 1.4;
		this->memorieAplicatii[3] = 1.6;
		this->memorieAplicatii[4] = 2.4;


	}

	Telefon(float rezolutie, float memorie) : id(contor++)
	{
		this->rezolutie = rezolutie;
		this->memorie = memorie;
		this->model = "Iphone 17";
		this->producator = new char[strlen("Apple") + 1];
		strcpy_s(producator, strlen("Apple") + 1, "Apple");
		this->pret = 4000;
		this->nrAplicatii = 5;
		this->memorieAplicatii = new float[this->nrAplicatii];
		this->memorieAplicatii[0] = 2;
		this->memorieAplicatii[1] = 3;
		this->memorieAplicatii[2] = 1.4;
		this->memorieAplicatii[3] = 1.6;
		this->memorieAplicatii[4] = 2.4;


	}

	Telefon(const Telefon& t) : id(contor++)
	{
		this->rezolutie = t.rezolutie;
		this->memorie = t.memorie;
		this->model = t.model;
		this->producator = new char[strlen(t.producator) + 1];
		strcpy_s(producator, strlen(t.producator) + 1, t.producator);
		this->pret = t.pret;
		this->nrAplicatii = t.nrAplicatii;
		this->memorieAplicatii = new float[this->nrAplicatii];
		for (int i = 0;i < this->nrAplicatii;i++)
		{
			this->memorieAplicatii[i] = t.memorieAplicatii[i];
		}

	}

	~Telefon()
	{
		delete[] producator;
		delete[] memorieAplicatii;
	}

	Telefon& operator=(const Telefon& t) {
		if (this != &t) {
			this->rezolutie = t.rezolutie;
			this->memorie = t.memorie;
			this->model = t.model;
			if (this->producator != NULL)
				delete[] this->producator;
			this->producator = new char[strlen(t.producator) + 1];
			strcpy_s(producator, strlen(t.producator) + 1, t.producator);
			this->pret = t.pret;
			this->nrAplicatii = t.nrAplicatii;
			if (this->memorieAplicatii != NULL)
				delete[] memorieAplicatii;
			this->memorieAplicatii = new float[this->nrAplicatii];
			for (int i = 0;i < this->nrAplicatii;i++)
			{
				this->memorieAplicatii[i] = t.memorieAplicatii[i];
			}
		}
		return *this;
	}

	float getPret()
	{
		return this->pret;
	}
	void setPret(float pret);


	int getNrAplicatii()
	{
		return this->nrAplicatii;
	}

	char* getProducator()
	{
		return this->producator;
	}
	void setProducator(const char* producator)
	{
		delete[] this->producator;
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}

	Telefon operator+(const Telefon& t) {
		Telefon result = *this;
		result.pret = this->pret + t.pret;
		return result;
	}

	Telefon operator+(float crestere) const {
		Telefon result = *this;
		result.pret = this->pret + crestere;
		return result;
	}
	friend Telefon operator+(float crestere, Telefon t) {
		Telefon result = t;
		t.setPret(t.getPret() + crestere);
		return result;
	}
	explicit operator float()
	{
		float suma = 0;
		if (this->nrAplicatii > 0)
		{
			for (int i = 0;i < this->nrAplicatii;i++)
			{
				suma += this->memorieAplicatii[i];

			}
			return suma / this->nrAplicatii;
		}
		else { return 0; }

	}
	explicit operator int()
	{
		return this->nrAplicatii;
	}
	//post decrementare
	Telefon operator--(int)
	{
		Telefon copie = *this;
		this->pret--;
		return copie;
	}
	//pre decrementare
	Telefon& operator--()
	{
		this->pret--;
		return *this;
	}

	//operatorul <<

	friend ostream& operator<<(ostream& out, const Telefon& actual)
	{
		out << "Id: " << actual.id << endl;
		out << "Producator: " << actual.producator << endl;
		out << "Pret: " << actual.pret << endl;
		out << "Memorie: " << actual.memorie << endl;
		out << "Nr de aplicatii: " << actual.nrAplicatii << endl;
		out << "Memorie aplicatii: ";
		for (int i = 0;i < actual.nrAplicatii - 1;i++)
			out << actual.memorieAplicatii[i] << ", ";
		out << actual.memorieAplicatii[actual.nrAplicatii - 1] << ".";
		out << endl;
		return out;
	}
	//operator >>
	friend istream& operator>>(istream& in, Telefon& actual)
	{
		cout << "Producator = ";
		char buffer[100];
		in >> buffer;
		if (actual.producator)
			delete[] actual.producator;
		actual.producator = new char[strlen(buffer) + 1];
		strcpy_s(actual.producator, strlen(buffer) + 1, buffer);
		cout << "Pret= ";
		in >> actual.pret;
		cout << "memorie= ";
		in >> actual.memorie;
		cout << "nr aplicatii= ";
		in >> actual.nrAplicatii;
		if (actual.memorieAplicatii)
			delete[] actual.memorieAplicatii;
		actual.memorieAplicatii = new float[actual.nrAplicatii];
		cout << "Memorie fiecare aplicatie: ";
		for (int i = 0;i < actual.nrAplicatii;i++)
			in >> actual.memorieAplicatii[i];
		return in;
	}

	//operator functie
	float operator()()
	{
		if (this->nrAplicatii > 0)
			return this->pret / this->nrAplicatii;
		else
			return 0;
	}

	float operator()(float tva)
	{
		if (this->nrAplicatii > 0)
			return (this->pret + this->pret * tva) / this->nrAplicatii;
		else
			return 0;
	}

	float operator()(int discount)
	{
		if (this->nrAplicatii > 0)
			return (this->pret - (discount / 100.0 * this->pret)) / this->nrAplicatii;
		else
			return 0;
	}

	bool operator==(Telefon t) {
		if (strcmp(this->producator, t.producator) != 0) {
			return false;
		}
		if (this->rezolutie != t.rezolutie) {
			return false;
		}
		if (this->memorie != t.memorie) {
			return false;
		}
		if (this->model != t.model) {
			return false;
		}

		return true;
	}



	void afisare() {
		cout << "Rezolutie: " << this->rezolutie << "\n";
		cout << "Memorie: " << this->memorie << "\n";
		cout << "Model: " << this->model << "\n";
		cout << "Producator: " << this->producator << "\n";
		cout << "Pret: " << this->pret << "\n";
		cout << "Numar aplicatii: " << this->nrAplicatii << "\n";
		cout << "Memorie ocupata: ";
		for (int i = 0; i < this->nrAplicatii; i++)
			cout << this->memorieAplicatii[i] << "; ";
		cout << endl;
	}

	float calculeazaMemorieOcupata() {
		float sumaMemorie = 0;
		for (int i = 0; i < this->nrAplicatii; i++)
			sumaMemorie += memorieAplicatii[i];
		return sumaMemorie;
	}

	float calculeazaMemorieLibera() {
		return memorie - calculeazaMemorieOcupata();
	}

	void modificaProducator(const char* producatorNou) {
		delete[]this->producator;
		producator = new char[strlen(producatorNou) + 1];
		strcpy_s(producator, strlen(producatorNou) + 1, producatorNou);
	}
	friend class Student;
};

int Telefon::contor = 1000;



float calcularePretTotal(Telefon* v, int nrTelefoane)
{
	float suma = 0;
	for (int i = 0;i < nrTelefoane;i++)
		suma += v[i].getPret();
	return suma;
}
float calculeazaMemorieDisponibila(Telefon* g, int nrTelefoane)
{
	float suma = 0;
	for (int i = 0;i < nrTelefoane;i++)
		suma += g[i].calculeazaMemorieLibera();
	return suma;

}

float calculeazaPretPerAplicatie(Telefon x)
{
	if (x.getNrAplicatii() == 0)
	{
		return 0;
	}
	else
	{
		return x.getPret() / x.getNrAplicatii();
	}
}

void Telefon::setPret(float pret)
{
	this->pret = pret;
}

class Student {
	string nume;
	Telefon telefon;
public:
	Student() {
		nume = "Popescu";
	}
	Student(string nume, Telefon telefon) {
		this->nume = nume;
		this->telefon = telefon;
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	Telefon getTelefon() {
		return this->telefon;
	}

	void setTelefon(const Telefon& t) {
		this->telefon = t;
	}

	bool poateInstalaAplicatia(float memorieNecesara) {
		return (memorieNecesara <= this->telefon.calculeazaMemorieLibera());
	}

	void afisareInformatii() {
		cout << "\n" << this->nume << " are un telefon cu " << this->telefon.memorie << " Giga memorie" << endl;
	}
	friend ostream& operator<<(ostream& out, const Student& s)
	{
		out << "Nume: " << s.nume << endl;
		out << "Telefon: " << s.telefon << endl;
		return out;
	}

};

class TelefonPliabil : public Telefon {
	int nrPlieri;
	float dimensiuneRedusa;
public:
	TelefonPliabil() :Telefon() {
		this->nrPlieri = 2;
		this->dimensiuneRedusa = 4;
	}
	TelefonPliabil(int nrPlieri, float dimensiuneRedusa) :Telefon(1080, 256) {
		this->nrPlieri = nrPlieri;
		this->dimensiuneRedusa = dimensiuneRedusa;
	}
	TelefonPliabil(int nrPlieri, float dimensiuneRedusa, float rezolutie,
		float memorie, string model, const char* producator,
		float pret, int nrAplicatii, const float* memorieAplicatii) : Telefon(rezolutie,memorie,
			model,producator,pret,nrAplicatii,memorieAplicatii){
		this->nrPlieri = nrPlieri;
		this->dimensiuneRedusa = dimensiuneRedusa;
	}
	TelefonPliabil(const TelefonPliabil& tp) :Telefon(tp){
		this->nrPlieri = tp.nrPlieri;
		this->dimensiuneRedusa = tp.dimensiuneRedusa;
	}
	TelefonPliabil& operator=(const TelefonPliabil& tp) {
		if (this != &tp) {
			(Telefon)*this = (Telefon)tp;
			this->nrPlieri = tp.nrPlieri;
			this->dimensiuneRedusa = tp.dimensiuneRedusa;
		}
		return *this;
	}
	~TelefonPliabil() {

	}
	friend ostream& operator<<(ostream& out, const TelefonPliabil& tp)
	{
		out << (Telefon)tp;
		out << "Nr plieri: " << tp.nrPlieri << endl;
		out << "Dimensiune: " << tp.dimensiuneRedusa << endl;
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, TelefonPliabil& tp)
	{
		cout << "Telefon: ";
		in >> (Telefon&)tp;
		cout << "Nr plieri: ";
		in >> tp.nrPlieri;
		cout << "Dimensiune: ";
		in >> tp.dimensiuneRedusa;
		return in;

	}
	int getNrPlieri()
	{
		return this->nrPlieri;
	}
	void setNrPlieri(int nrPlieri)
	{
		if (nrPlieri >= 0)
			this->nrPlieri = nrPlieri;
		else this->nrPlieri = 0;
	}
	 operator int()
	{
		return this->nrPlieri;
	}
	
	 float calculeazaDimensiuneExtinsa()
	 {
		 return this->dimensiuneRedusa * (this->nrPlieri + 1);
	 }
	 bool operator>=(const TelefonPliabil& tp)
	 {
		
		 return (this->nrPlieri >= tp.nrPlieri);
	 }

};
void main() {

//	Telefon t;
//	Telefon t2(6.3, 512);
//	Telefon t3 = t;
//	float a = 6.3;
//	int b = (int)a;
//	float memorieMedie;
//	memorieMedie = (float)t;//cast explicit
//	t3 = t--;
//	t3 = --t;
//	/*cin >> t;*/
//	cout << t;
//	cout << "Pret per aplicatii: " << t3() << endl;
//	cout << " Pret cu tva per aplicatie: " << t3(0.21f) << endl;
//	cout << " Pret cu discount per aplicatie: " << t3(21);
//
//	if (t == t2) {
//		cout << endl << "Telefoane asemanatoare." << endl;
//	}
//	else {
//		cout << endl << "Telefoane diferite." << endl;
//	}
	TelefonPliabil tp1;
	TelefonPliabil tp2(1, 6);
	TelefonPliabil tp3 = tp1;
	tp3 = tp1;
	cout << tp2;
	TelefonPliabil tp4;
	/*cin >> tp4;
	cout << tp4<<endl;*/
	int nr = (int)tp1;
	cout << nr;
	Student s1("Alex",tp2);
	cout << s1 << endl;
	cout << "Dimensiune Extinsa: " << tp2.calculeazaDimensiuneExtinsa()<<endl;
	tp1.setNrPlieri(0);
	if (tp1 >= tp2)
		cout << "Tp1 mai mare" << endl;
	else cout << "tp2 este mai mare" << endl;
}
