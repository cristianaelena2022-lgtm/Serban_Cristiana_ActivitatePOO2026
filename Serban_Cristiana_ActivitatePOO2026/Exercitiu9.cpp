#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Playlist {
private: 
	char* nume;
	int* durate;
	int nrMelodii;
	static int nrPlaylisturi;
public:
	Playlist(const char* n, const int* d, int nr) {
		this->nume = new char[strlen(n) + 1];
		strcpy(this->nume, n);
		this->durate = new int[nr];
		this->nrMelodii = nr;
		for (int i = 0; i < this->nrMelodii; i++) {
			this->durate[i] = d[i];
		}
		Playlist::nrPlaylisturi++;
	}
	~Playlist() {
		delete[] nume;
		delete[] durate;
	    Playlist::nrPlaylisturi--;
	}
	Playlist(const Playlist& p) {
		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->nrMelodii = p.nrMelodii;
		this->durate = new int[this->nrMelodii];
		for (int i = 0; i < this->nrMelodii; i++) {
			this->durate[i] = p.durate[i];
		}
		Playlist::nrPlaylisturi++;
	}
	void setNume(const char* denumire) {
		char* copie = new char[strlen(denumire) + 1];
		strcpy(copie, denumire);
		delete[] this->nume;
		this->nume = copie;
	}
	void setDurata(int pozitie, int durata) {
		if (pozitie >= 0 && pozitie <= this->nrMelodii - 1)
			this->durate[pozitie] = durata;
	}
	int getDurata(int pozitie) {
		if (pozitie >= 0 && pozitie <= this->nrMelodii - 1)
			return this->durate[pozitie];
		return -1;
	}
	int getDurataTotala() {
		int suma = 0;
		for (int i = 0; i < this->nrMelodii; i++) {
			suma += this->durate[i];
		}
		return suma;
	}
	void afisare() {
		cout << "Numele playlistului este: " << this->nume << endl;
		for (int i = 0; i < nrMelodii; i++) {
			cout << "Durata melodiei " << i + 1 << " " << "este: " << this->durate[i] << endl;
		}
		cout << "Durata totala este: " << getDurataTotala() << endl;
	}
	static int getNrPlaylisturi() {
		return Playlist::nrPlaylisturi;
	}
};

int Playlist::nrPlaylisturi = 0;

int main() {
	int durate[] = { 180, 240, 200 };
	Playlist p1("Gym Mix", durate, 3);
	Playlist p2(p1);
	p2.setNume("Chill Mix");
	p2.setDurata(0, 300);
	p1.afisare();
	p2.afisare();
	cout << "Playlisturi existente: " << Playlist::getNrPlaylisturi() << endl;
	return 0;
}
