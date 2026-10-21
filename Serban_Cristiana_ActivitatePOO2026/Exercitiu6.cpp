
#include <iostream>
#include <vector>
using namespace std;

class Vector {
public:
    vector<int> v;

    Vector(const vector<int>& v1) : v(v1) {
    
    }

    int maxim() {
        int m = v[0];

        for (int i = 1; i < v.size(); i++)
            if (v[i] > m)
                m = v[i];

        return m;
    }

    int numerePare() {
        int contor = 0;

        for (int i = 0; i < v.size(); i++)
            if (v[i] % 2 == 0)
                contor++;

        return contor;
    }

    bool crescator() {
        for (int i = 0; i < v.size() - 1; i++)
            if (v[i] > v[i + 1])
                return false;

        return true;
    }

    void eliminareDuplicate() {
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size();) {
                if (v[i] == v[j])
                    v.erase(v.begin() + j);
                else
                    j++;
            }
        }
    }

    void afis() {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";

        cout << endl;
    }

    int suma() {
        int s = 0;

        for (int i = 0; i < v.size(); i++)
            s += v[i];

        return s;
    }
};

int main() {
    vector<int> valori = { 4, 2, 4, 7, 2, 8 };
    Vector x(valori);
    cout << "Maximul este: " << x.maxim() << endl;
    cout << "Numerele pare sunt: " << x.numerePare() << endl;
    cout << "Crescator?: " << x.crescator() << endl;
    cout << "Eliminare duplicate:" << endl;
    x.eliminareDuplicate();
    x.afis();
    cout << "Suma elementelor este: " << x.suma() << endl;
    return 0;
}
