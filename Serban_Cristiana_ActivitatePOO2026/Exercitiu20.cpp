#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Artist {
private:
	char* numeScena;
	char* genMuzical;
	int durataShow;
	float onorariu;
	const int codArtist;
	static int contor;
	friend class Festival;
public:
	Artist() : codArtist(contor++) {
		this->numeScena = new char[strlen("Scena 1") + 1];
		strcpy(this->numeScena, "Scena 1");
		this->genMuzical = new char[strlen("Rock") + 1];
		strcpy(this->genMuzical, "Rock");
		this->durataShow = 160;
		this->onorariu = 20;
	}
	Artist(const char* nume, const char* gen, int durata, float o) : codArtist(contor++) {
		this->numeScena = new char[strlen(nume) + 1];
		strcpy(this->numeScena, nume);
		this->genMuzical = new char[strlen(gen) + 1];
		strcpy(this->genMuzical, gen);
		this->durataShow = durata;
		this->onorariu = o;
	}
	Artist(const Artist& a) : codArtist(contor++){
		this->numeScena = new char[strlen(a.numeScena) + 1];
		strcpy(this->numeScena, a.numeScena);
		this->genMuzical = new char[strlen(a.genMuzical) + 1];
		strcpy(this->genMuzical, a.genMuzical);
		this->durataShow = a.durataShow;
		this->onorariu = a.onorariu;
	}
	~Artist() {
		delete[] this->numeScena;
		delete[] this->genMuzical;
	}
	Artist& operator=(const Artist& a) {
		if (this != &a) {
			char* copieNume = new char[strlen(a.numeScena) + 1];
			strcpy(copieNume, a.numeScena);
			delete[] this->numeScena;
			this->numeScena = copieNume;
			char* copieGen = new char[strlen(a.genMuzical) + 1];
			strcpy(copieGen, a.genMuzical);
			delete[] this->genMuzical;
			this->genMuzical = copieGen;
			this->durataShow = a.durataShow;
			this->onorariu = a.onorariu;
		}
		return *this;
	}
	void setNumeScena(const char* numeNou) {
		char* copie = new char[strlen(numeNou) + 1];
		strcpy(copie, numeNou);
		delete[] this->numeScena;
		this->numeScena = copie;
	}
	void setGenMuzical(const char* gen) {
		char* copie = new char[strlen(gen) + 1];
		strcpy(copie, gen);
		delete[] this->genMuzical;
		this->genMuzical = copie;
	}
	void setDurataShow(int index) {
		this->durataShow = index;
	}
	void setOnorariu(float index) {
		this->onorariu = index;
	}
	const char* getNumeScena() const{
		return this->numeScena;
	}
	const char* getGenMuzical() const{
		return this->genMuzical;
	}
	int getDurataShow() const{
		return this->durataShow;
	}
	float getOnorariu() const {
		return this->onorariu;
	}
	int getCodArtist() const {
		return this->codArtist;
	}
	static int getContor() {
		return contor;
	}
	float calculOnorariuPeMinut() const{
		return this->durataShow / this->onorariu;
	}
	bool operator==(const Artist& a) const {
		return (this->codArtist == a.codArtist);
	}
	friend ostream& operator<<(ostream& out, const Artist& a) {
		out << "Id-ul artistului este: " << a.codArtist << endl;
		out << "Numele scenei este: " << a.numeScena << endl;
		out << "Genul muzical este: " << a.genMuzical << endl;
		out << "Durata show-ului este: " << a.durataShow << endl;
		out << "Onorariul este de: " << a.onorariu << endl;
		out << "Onorariul pe minut este de: " << a.calculOnorariuPeMinut() << endl;
		return out;
	}
};

class Festival {
private:
	char* numeFestival;
	int nrArtist;
	Artist* artisti;
	int durataFestival;
	const int codFestival;
	static int contor;
public:
	Festival() : codFestival(contor++) {
		this->numeFestival = new char[strlen("Festivalul muzicii") + 1];
		strcpy(this->numeFestival, "Festivalul muzicii");
		this->nrArtist = 2;
		this->artisti = new Artist[this->nrArtist];
		Artist a1("Scena 1", "Rock", 160, 10);
		Artist a2("Scena 2", "Trap", 120, 20);
		this->artisti[0] = a1;
		this->artisti[1] = a2;
		this->durataFestival = 2;
	}
	Festival(const char* nume, int numar, int durata) : codFestival(contor++) {
		this->numeFestival = new char[strlen(nume) + 1];
		strcpy(this->numeFestival, nume);
		this->nrArtist = (numar > 0) ? numar : 0;
		this->artisti = new Artist[this->nrArtist];
		this->durataFestival = (durata > 0) ? durata : 0;
	}
	Festival(const Festival& f) : codFestival(contor++) {
		this->numeFestival = new char[strlen(f.numeFestival) + 1];
		strcpy(this->numeFestival, f.numeFestival);
		this->nrArtist = f.nrArtist;
		this->artisti = new Artist[this->nrArtist];
		for (int i = 0; i < this->nrArtist; i++)
			this->artisti[i] = f.artisti[i];
		this->durataFestival = f.durataFestival;
	}
	~Festival() {
		delete[] this->numeFestival;
		delete[] this->artisti;
	}
	Festival& operator=(const Festival& f) {
		if (this != &f) {
			char* copieNumeFestival = new char[strlen(f.numeFestival) + 1];
			strcpy(copieNumeFestival, f.numeFestival);
			delete[] this->numeFestival;
			this->numeFestival = copieNumeFestival;
			this->nrArtist = f.nrArtist;
			Artist* copieArtisti = new Artist[f.nrArtist];
			for (int i = 0; i < f.nrArtist; i++)
				copieArtisti[i] = f.artisti[i];
			delete[] this->artisti;
			this->artisti = copieArtisti;
			this->durataFestival = f.durataFestival;
		}
		return *this;
	}
	void setNumeFestival(const char* numeNou) {
		char* copieNume = new char[strlen(numeNou) + 1];
		strcpy(copieNume, numeNou);
		delete[] this->numeFestival;
		this->numeFestival = copieNume;
	}
	void setDurataFestival(int index) {
		this->durataFestival = index;
	}
	const char* getNumeFestival() const {
		return this->numeFestival;
	}
	int getNrArtisti() const {
		return this->nrArtist;
	}
	int getDurataFestival() const {
		return this->durataFestival;
	}
	int getCodFestival() const {
		return this->codFestival;
	}
	static int getContor() {
		return contor;
	}
	void adaugareArtist(const Artist& a) {
		Artist* copieArtisti = new Artist[this->nrArtist + 1];
		for (int i = 0; i < this->nrArtist; i++)
			copieArtisti[i] = this->artisti[i];
		copieArtisti[this->nrArtist] = a;
		delete[] this->artisti;
		this->artisti = copieArtisti;
		this->nrArtist++;
	}
	float calculOnorariiTotale() const{
		float suma = 0;
		for (int i = 0; i < this->nrArtist; i++)
			suma += this->artisti[i].calculOnorariuPeMinut();
		return suma;
	}
	Festival& operator+=(const Artist& a) {
		Artist* copieArtisti = new Artist[this->nrArtist + 1];
		for (int i = 0; i < this->nrArtist; i++)
			copieArtisti[i] = this->artisti[i];
		copieArtisti[this->nrArtist] = a;
		delete[] this->artisti;
		this->artisti = copieArtisti;
		this->nrArtist++;
		return *this;
	}
	bool operator==(const Festival& f) const {
		return (this->codFestival == f.codFestival);
	}
	bool operator!() const {
		return (this->nrArtist == 0);
	}
	friend ostream& operator<<(ostream& out, const Festival& f) {
		out << "Id-ul festivalului este: " << f.codFestival << endl;
		out << "Numele festivalului este: " << f.numeFestival << endl;
		out << "Numarul Artistilor este: " << f.nrArtist << endl;
		for (int i = 0; i < f.nrArtist; i++) {
			out << "Id-ul artistului este: " << f.artisti[i].getCodArtist() << endl;
			out << "Numele scenei este: " << f.artisti[i].getNumeScena() << endl;
			out << "Genul muzical este: " << f.artisti[i].getGenMuzical() << endl;
			out << "Durata show-ului este: " << f.artisti[i].getDurataShow() << endl;
			out << "Onorariul este de: " << f.artisti[i].getOnorariu() << endl;
			out << "Onorariul pe minut este de: " << f.artisti[i].calculOnorariuPeMinut() << endl;
		}
		out << "Totalul este: " << f.calculOnorariiTotale() << endl;
		out << "Durata festivalului este de " << f.durataFestival << " zile " << endl;
		return out;
	}
};

int Artist::contor = 0;
int Festival::contor = 0;

int main() {
	Artist a1;
	Artist a2("Scena 3", "Pop", 140, 20);
	Artist a3("Scena 4", "Jaz", 150, 30);
	cout << a1 << a2 << a3 << endl;
	cout << "Onorariul pe minut al artistului cu id- ul = 2 este: " << a3.calculOnorariuPeMinut() << endl;
	Artist a4(a2);
	a4.setNumeScena("Scena 5");
	if (a1 == a4)
		cout << "Originalul ramane neschimbat" << endl;
	else
		cout << "Originalul se schimba" << endl;
	Artist a5;
	a5 = a2;
	cout << a5;
	Festival f;
	Festival f1("Festivalul albastru", 2, 2);
	f1.adaugareArtist(a1);
	f1.adaugareArtist(a2);
	cout << f1;
	cout << f1.calculOnorariiTotale();
	f1 += a3;
	if (!f)
		cout << "Festivalul este gol" << endl;
	else
		cout << "Festivalul nu este gol" << endl;
	Festival f2(f1);
	if (f1 == f2)
		cout << "Festivalele sunt identice" << endl;
	else
		cout << "Festivalele sunt diferite" << endl;
	cout << (f1 = f2);
}
