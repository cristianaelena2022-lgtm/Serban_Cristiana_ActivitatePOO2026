#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyArray {
private:
	int* data;
	int size;
public:
	MyArray() {
		this->data = new int[1];
		this->data[0] = 0;
		this->size = 0;
	}
	MyArray(int s) {
		if (s > 0) {
			this->size = s;
			this->data = new int[s];
		}
		else {
			this->data = new int[1];
			this->data[0] = 0;
			this->size = 0;
		}
	}
	MyArray(const MyArray& m) {
		this->size = m.size;
		this->data = new int[this->size];
		for (int i = 0; i < this->size; i++)
			this->data[i] = m.data[i];
	}
	~MyArray() {
		delete[] data;
	}
	MyArray& operator=(const MyArray& other) {
		if (this == &other)
			return *this;
        delete[] this->data;
		this->size = other.size;
		this->data = new int[this->size];
		for (int i = 0; i < this->size; i++)
			this->data[i] = other.data[i];
		return *this;
	}
	void print() {
		if (this->size != 0) {
			cout << "Elementele sunt: ";
			for (int i = 0; i < this->size; i++) {
				cout << this->data[i] << " ";
			}
			cout << endl;
		}
		else
			cout << "Nu exista elemente!" << endl;
	}
	int getSize() {
		return this->size;
	}
	bool isEmpty() {
		if (this->size == 0)
			return true;
		else
			return false;
	}
	int getElement(int index) {
		if (index >= 0 && index < this->size)
			return this->data[index];
		else
			return -1;
	}
	void setElement(int index, int value) {
		if (index >= 0 && index < this->size)
			this->data[index] = value;
		else
			cout << "Indexul nu exista!";
	}
	void fillArray() {
		if (this->size > 0)
			for (int i = 0; i < this->size; i++)
				cin >> this->data[i];
	}
	int findMax() {
		if (this->size == 0)
			return -1;
		else {
			int maxim = this->data[0];
			for (int i = 1; i < this->size; i++)
				if (this->data[i] > maxim)
					maxim = this->data[i];
			return maxim;
		}
	}
	int findMin() {
		if (this->size == 0)
			return -1;
		else {
			int minim = this->data[0];
			for (int i = 1; i < this->size; i++)
				if (this->data[i] < minim)
					minim = this->data[i];
			return minim;
		}
	}
	int search(int value) {
		for (int i = 0; i < this->size; i++)
			if (this->data[i] == value)
				return i;
		return -1;
	}
	bool equals(const MyArray& other) {
		if (this->size != other.size)
			return false;
		else
			for (int i = 0; i < this->size; i++)
				if (this->data[i] != other.data[i])
					return false;
		return true;
	}
};

int main() {
	MyArray a(5);
	cout << "Introdu 5 numere:\n";
	a.fillArray();
	a.print();
	MyArray b(a);
	cout << b.equals(a) << endl;
	b.setElement(0, 100);
	cout << b.equals(a) << endl;
}
