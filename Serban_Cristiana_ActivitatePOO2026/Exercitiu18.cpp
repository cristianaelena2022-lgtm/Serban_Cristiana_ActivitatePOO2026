#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Carte {
private:
	char* titlu;
	int nrPagini;
	friend class Biblioteca;
public:
	Carte(){
		this->titlu = new char[strlen("EnigmaOtiliei") + 1];
		strcpy(this->titlu, "EnigmaOtiliei");
		this->nrPagini = 456;
	}
	Carte(const char* nume, int nr) {
		this->titlu = new char[strlen(nume) + 1];
		strcpy(this->titlu, nume);
		this->nrPagini = nr;
	}
	Carte(const Carte& c) {
		this->titlu = new char[strlen(c.titlu) + 1];
		strcpy(this->titlu, c.titlu);
		this->nrPagini = c.nrPagini;
	}
	~Carte() {
		delete[] this->titlu;
	}
	Carte& operator=(const Carte& c) {
		if (this != &c) {
			if (this->titlu != 0)
				delete[] this->titlu;
			this->titlu = new char[strlen(c.titlu) + 1];
			strcpy(this->titlu, c.titlu);
			this->nrPagini = c.nrPagini;
		}
		return *this;
	}
	bool operator==(const Carte& c) const {
		return (strcmp(this->titlu, c.titlu) == 0 && (this->nrPagini == c.nrPagini));
	}
	bool operator!=(const Carte& c) const {
		return(strcmp(this->titlu, c.titlu) != 0 || (this->nrPagini != c.nrPagini));
	}
	void afisare() const {
		cout << "Titlul cartii este: " << this->titlu << endl;
		cout << "Cartea are un numar de: " << this->nrPagini << " pagini" << endl;
	}
};

class Biblioteca {
private:
	char* denumire;
	int nrCarti;
	Carte* carti;
public:
    class Sectiune {
    private:
	   char* numeSectiune;
	   int codSectiune;
	   friend class Biblioteca;
    public:
	   Sectiune() {
		  this->numeSectiune = new char[strlen("Sectiune") + 1];
		  strcpy(this->numeSectiune, "Sectiune");
		  this->codSectiune = 1;
	   }
	   Sectiune(const char* nume, int nr) {
		  this->numeSectiune = new char[strlen(nume) + 1];
		  strcpy(this->numeSectiune, nume);
		  this->codSectiune = nr;
	   }
	   Sectiune(const Sectiune& s) {
		  this->numeSectiune = new char[strlen(s.numeSectiune) + 1];
		  strcpy(this->numeSectiune, s.numeSectiune);
		  this->codSectiune = s.codSectiune;
	   }
	   ~Sectiune() {
		  delete[] this->numeSectiune;
	   }
	   const char* getNumeSectiune() const {
		  return this->numeSectiune;
	   }
	   int getCodSectiune() const {
		  return this->codSectiune;
	   }
    };
	Biblioteca() {
		this->denumire = new char[strlen("Biblioteca fermecata") + 1];
		strcpy(this->denumire, "Biblioteca fermecata");
		this->nrCarti = 3;
		this->carti = new Carte[this->nrCarti];
		Carte c1("Ion", 256);
		Carte c2("Cei 3 pitici", 301);
		Carte c3("Luceafarul", 167);
		this->carti[0] = c1;
		this->carti[1] = c2;
		this->carti[2] = c3;
	}
	Biblioteca(const char* nume, int nr) {
		this->denumire = new char[strlen(nume) + 1];
		strcpy(this->denumire, nume);
		this->nrCarti = nr;
		this->carti = new Carte[this->nrCarti];
	}
	Biblioteca(const Biblioteca& b) {
		this->denumire = new char[strlen(b.denumire) + 1];
		strcpy(this->denumire, b.denumire);
		this->nrCarti = b.nrCarti;
		this->carti = new Carte[this->nrCarti];
		for (int i = 0; i < this->nrCarti; i++)
			this->carti[i] = b.carti[i];
	}
	~Biblioteca() {
		delete[] this->denumire;
		delete[] this->carti;
	}
	Biblioteca& operator=(const Biblioteca& b) {
		if (this != &b) {
			if (this->denumire != 0)
				delete[] this->denumire;
			this->denumire = new char[strlen(b.denumire) + 1];
			strcpy(this->denumire, b.denumire);
			this->nrCarti = b.nrCarti;
			if (this->carti != 0)
				delete[] this->carti;
			this->carti = new Carte[this->nrCarti];
			for (int i = 0; i < this->nrCarti; i++)
				this->carti[i] = b.carti[i];
		}
		return *this;
	}
	Biblioteca& operator+=(const Carte& c) {
		Carte* copie = new Carte[this->nrCarti + 1];
		for (int i = 0; i < this->nrCarti; i++)
			copie[i] = this->carti[i];
		copie[this->nrCarti] = c;
		delete[] this->carti;
		this->nrCarti++;
		this->carti = copie;
		return *this;
	}
	bool operator==(const Biblioteca& b) const {
		if (strcmp(this->denumire, b.denumire) != 0)
			return false;
		if (this->nrCarti != b.nrCarti)
			return false;
		for (int i = 0; i < this->nrCarti; i++) {
			if(this->carti[i] != b.carti[i])
				return false;
		}
		return true;
	}
	void afiseazaSectiune(const Sectiune& s) const{
		cout << "Sectiunea acestei biblioteci se numeste: " << s.getNumeSectiune() << endl;
		cout << "Codul sectiunii este: " << s.getCodSectiune() << endl;
	}
};

int main() {
	Biblioteca b1;
	Biblioteca b2("Biblioteca Centrala", 2);
	Biblioteca b3(b1);
	Carte d("Fetitele powerpuff", 233);
	b1 += d;
	if (b1 == b3)
		cout << "Bibliotecile sunt identice!" << endl;
	else
		cout << "Bibliotecile sunt diferite!" << endl;
    b2 = b1;
	Carte c("Morometii", 450);
	b1 += c;
	if (b1 == b2)
		cout << "Bibliotecile sunt identice!" << endl;
	else
		cout << "Bibliotecile sunt diferite!" << endl;
	Biblioteca::Sectiune s1("Literatura", 10);
	b1.afiseazaSectiune(s1);
	return 0;
}
