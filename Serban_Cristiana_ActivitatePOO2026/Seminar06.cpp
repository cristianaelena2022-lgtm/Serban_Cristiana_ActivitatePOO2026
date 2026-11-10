//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//using namespace std;
//
//class Prajitura {
//private:
//	char* denumire;
//	float pret;
//	int cantitate;
//	bool dePost;
//	int nrIngrediente;
//	string* ingrediente;
//	const int id;
//	static int contor;
//public:
//#pragma region Constructori
//	friend class Student;
//	Prajitura():id(contor++) {
//		this->denumire = new char[strlen("Tiramisu")+1];
//		strcpy(denumire, "Tiramisu");
//		this->pret = 15;
//		this->cantitate = 250;
//		this->dePost = true;
//		this->nrIngrediente = 3;
//		this->ingrediente = new string[this->nrIngrediente];
//		this->ingrediente[0] = "piscoturi";
//		this->ingrediente[1] = "vanilie";
//		this->ingrediente[2] = "cafea";
//	}
//	Prajitura(const char*denumire,float pret):id(contor++) {
//		this->denumire = new char[strlen(denumire) + 1];
//		strcpy(this->denumire, denumire);
//		this->pret = pret;
//		this->cantitate = 250;
//		this->dePost = true;
//		this->nrIngrediente = 3;
//		this->ingrediente = new string[this->nrIngrediente];
//		this->ingrediente[0] = "piscoturi";
//		this->ingrediente[1] = "vanilie";
//		this->ingrediente[2] = "cafea";
//	}
//	
//	Prajitura(const Prajitura& p):id(contor++) {
//		this->denumire = new char[strlen(p.denumire) + 1];
//		strcpy(this->denumire, p.denumire);
//
//		this->pret = p.pret;
//		this->cantitate = p.cantitate;
//		this->dePost = p.dePost;
//		this->nrIngrediente = p.nrIngrediente;
//
//		this->ingrediente = new string[this->nrIngrediente];
//		for (int i = 0; i < this->nrIngrediente; i++) {
//			this->ingrediente[i] = p.ingrediente[i];
//		}
//	}
//	~Prajitura();//declarare destructor
//	Prajitura& operator=(const Prajitura& P1) {
//		if (this != &P1) {
//
//			this->cantitate = P1.cantitate;
//			if (this->denumire != NULL)
//				delete[]this->denumire;
//			this->denumire = new char[strlen(P1.denumire) + 1];
//			strcpy(this->denumire, P1.denumire);
//			this->dePost = P1.dePost;
//			this->pret = P1.pret;
//			this->nrIngrediente = P1.nrIngrediente;
//			if (this->ingrediente != NULL)
//				delete[]this->ingrediente;
//			this->ingrediente = new string[this->nrIngrediente];
//			for (int i = 0;i < P1.nrIngrediente; i++)
//				this->ingrediente[i] = P1.ingrediente[i];
//		}
//
//		return *this;
//	}
//
//#pragma endregion
//
//#pragma region geteri si seteri
//	int getCantitate() {
//		return this->cantitate;
//	}
//	int getNrIngrediente() {
//		return this->nrIngrediente;
//	}
//	float getPret() {
//		return this->pret;
//	}
//	static int getContor() {
//		return contor;
//	}
//
//#pragma endregion
//#pragma region operatori
//	Prajitura operator+(const Prajitura& p) {
//		Prajitura result = *this;
//		result.pret = this->pret + p.pret;
//		result.cantitate = this->cantitate + p.cantitate;
//		return result;
//	}
//	string& operator[](int pozitie)
//	{
//		if (pozitie >= 0 && pozitie < this->nrIngrediente)
//			return this->ingrediente[pozitie];
//	}
//	explicit operator float()
//	{
//		return this->pret;
//	}
//	explicit operator int()
//	{
//		return this->cantitate;
//	}
//	float operator()()
//	{
//		return this->costMediuGram();
//	}
//	float operator()(float TVA)
//	{
//		return (this->pret + (TVA * this->pret))/this->cantitate;
//	}
//	float operator()(int discount)
//	{
//		return (this->pret - (discount / 100.0)* this->pret)/this->cantitate;
//	}
//	bool operator==(Prajitura prajitura)
//	{
//		if (strcmp(this->denumire, prajitura.denumire) != 0)
//			return false;
//		if (this->cantitate != prajitura.cantitate)
//			return false;
//		if (this->dePost != prajitura.dePost)
//			return false;
//		if (this->nrIngrediente != prajitura.nrIngrediente)
//			return false;
//		return true;
//	}
//	Prajitura &operator-=(const Prajitura &p) {
//		if (this->pret > p.pret) {
//			this->pret = this->pret - p.pret;
//		}
//		else {
//			this->pret = 0;
//		}
//		return *this;
//	}
//
//	Prajitura operator+=(string ingredient) {
//		string* aux = new string[this->nrIngrediente + 1];
//		for (int i = 0;i < this->nrIngrediente;i++) {
//			aux[i] = this->ingrediente[i];
//		}
//		aux[this->nrIngrediente] = ingredient;
//		delete[] this->ingrediente;
//		this->ingrediente = aux;
//		this->nrIngrediente++;
//		return *this;
//	}
//
//
//#pragma endregion
//	void afisare()
//	{
//		cout << "Denumire: " << this->denumire << endl;
//		cout << "Pret: " << this->pret << endl;
//		cout << "Cantitate: " << this->cantitate<< endl;
//		cout << "De Post: " << (this->dePost ? "DA" : "NU") << endl;
//		cout << "Nr ingrediente: " << this->nrIngrediente << endl;
//		cout << "Ingredientele sunt: ";
//		for (int i = 0;i < this->nrIngrediente;i++)
//		{
//			cout << this->ingrediente[i] << "; ";
//		}
//		cout << endl;
//
//	}
//	float costMediuGram() {
//		if (this->cantitate == 0) {
//			return 0;
//		}
//		else {
//			return this->pret / this->cantitate;
//		}
//	}
//
//	void modificaDenumire(const char* denumire) {
//		delete this->denumire;
//
//		this->denumire = new char[strlen(denumire) + 1];
//		strcpy(this->denumire, denumire);
//	}
//
//
//};
//
//int Prajitura::contor = 100;
//
//Prajitura::~Prajitura() {//implementare destructor
//	delete[] this->denumire;
//	delete[] this->ingrediente;
//}
//float calculeazaCantitateTotala(Prajitura* prajituri, int nr_prajituri) {
//	float greutate = 0;
//
//	for (int p = 0; p < nr_prajituri; p++)
//		greutate += prajituri[p].getCantitate();
//	
//	return greutate;
//}
//
//float calculeazaPretPerIngredient(Prajitura p) {
//	if (p.getNrIngrediente() != 0)
//		return p.getPret() / p.getNrIngrediente();
//
//	return 0;
//}
//
//
//class Student {
//private:
//	string nume;
//	Prajitura prajitura;
//public:
//	Student() {
//		this->nume = "Andrei";
//	}
//	Student(string nume, Prajitura p) {
//		this->nume = nume;
//		this->prajitura = p;
//	}
//	string getNume() {
//		return this->nume;
//	}
//	Prajitura getPrajitura() {
//		return this->prajitura;
//	}
//	void setNume(string nume) {
//		this->nume = nume;
//	}
//	void setPrajitura(Prajitura p) {
//		this->prajitura = p;
//	}
//	float calculeazaNrTotalCalorii(float caloriiPerGram) {
//		float nrTotal = caloriiPerGram * this->prajitura.getCantitate();
//		return nrTotal;
//	}
//	void afiseazaMasa() {
//		cout << this->nume << " mananca prajitura " << this->prajitura.denumire << endl;
//	}
//};
//
//
//void main() {
//	Prajitura p;
//	p.afisare();
//	Prajitura::getContor();
//	Prajitura P1("amandina", 20.6);
//	Student s1("Cristian", P1);
//
//	cout << p[1] << endl;
//	p[1] = "Frisca";
//	cout << p[1] << endl;
//	float pret;
//	pret = (float)P1;
//	cout << "Pret= " << pret << endl;
//	int cantitate;
//	cantitate = (int)P1;
//	cout << "Cantitate= " << cantitate << endl;
//	cout << "Pret per gram: " << P1() << endl;
//	cout << "Pret cu TVA per gram: " << P1(0.21f) << endl;
//	cout << "Pret cu discount per gram: " << P1(10) << endl;
//	if (p == P1)
//		cout << "Prajituri egale";
//	else cout << "Prajiturile sunt diferite\n";
//	p -= P1;
//	cout << p.getPret();
//	p += "Faina";
//	cout << p[3];
//}
