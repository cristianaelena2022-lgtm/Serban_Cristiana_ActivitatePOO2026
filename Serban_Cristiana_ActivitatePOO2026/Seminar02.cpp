#include <iostream>

using namespace std;

struct Ghiozdan {
	float lungime;
	int nrBuzunare;
	bool laptop;
	char* producator;
};

Ghiozdan citireGhiozdan() { // citirea caracteristicilor unui ghiozdan
	char numeProducator[20];
	Ghiozdan g;
	cout << "lungime: "; cin >> g.lungime;
	cout << "nrBuzunare: "; cin >> g.nrBuzunare;
	cout << "Pentru laptop?: (0/1) "; cin >> g.laptop;
	cout << "producator: ";cin >> numeProducator;
	g.producator = new char[strlen(numeProducator) + 1];
	strcpy_s(g.producator, sizeof(strlen(numeProducator) + 1), numeProducator);
	return g;
}
void afisareGhiozdan(Ghiozdan g) {
	cout << "lungime: " << g.lungime << endl;
	cout << "buzunare: " << g.nrBuzunare << endl;
	cout << "laptop: " << g.laptop << endl;
	cout << "producator: " << g.producator << endl;
};
void modificareLungime(Ghiozdan* g, float lungimeNoua) {
	(*g).lungime = lungimeNoua;
};
int sumaBuzunare(Ghiozdan* ghiozdane, int nrGhiozdane) {
	int suma = 0;
	for (int i = 0;i < nrGhiozdane;i++) {
		suma += ghiozdane[i].nrBuzunare;
	}
	return suma;
}

void main() {
	//	Ghiozdan g = citireGhiozdan();
	//	afisareGhiozdan(g);
	//	modificareLungime(&g, 13);
	//	afisareGhiozdan(g);
	int nrGhiozdane = 3;
	Ghiozdan* ghiozdane;
	ghiozdane = new Ghiozdan[3];
	for (int i = 0;i < 3;i++) {
		ghiozdane[i] = citireGhiozdan();
	};
	for (int i = 0;i < 3;i++) {
		afisareGhiozdan(ghiozdane[i]);
	}
	cout << "Suma buzunarelor este: " << sumaBuzunare(ghiozdane, nrGhiozdane);
};