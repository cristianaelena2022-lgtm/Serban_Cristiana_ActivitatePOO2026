#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Mystring {
private:
	char* text;
	int length;
public:
	Mystring(){
		this->text = new char[1];
		this->text[0] = '\0';
		this->length = 0;
	}
	Mystring(const char* str) {
		this->text = new char[strlen(str) + 1];
		strcpy(this->text, str);
		this->length = strlen(str);
	}
	Mystring(const Mystring& other) {
		this->text = new char[strlen(other.text) + 1];
		strcpy(this->text, other.text);
		this->length = other.length;
	}
	~Mystring() {
		delete[] text;
	}
	void print() {
		cout << "Textul este: " << this->text << endl;
	}
	int size() {
		return length;
	}
	bool empty() {
		if (this->length == 0)
			return true;
		else
			return false;
	}
	char at(int index) {
		if (index >= 0 && index < length)
			return this->text[index];
		return '\0';
	}
	void setChar(int index, char ch) {
		if (index >= 0 && index < length) {
			this->text[index] = ch;
		}
	}
	bool equals(const Mystring& other) {
		if (strcmp(this->text, other.text) == 0)
			return true;
		else
			return false;
	}
	void append(const Mystring& other) {
		char* tablou = new char[(this->length + other.length) + 1];
		strcpy(tablou, this->text);
		strcat(tablou, other.text);
		delete[] this->text;
		this->text = tablou;
		this->length = strlen(this->text);
	}
	int find(char ch) {
		int i = 0;
		while (i < this->length) {
			if (this->text[i] == ch)
				return i;
			i++;
		}
		return -1;
	}
};

int main() {
	Mystring s1("Hello");
	cout << s1.size() << endl;
	cout << s1.empty() << endl;
	cout << s1.at(1) << endl;
	s1.setChar(0, 'Y');
	s1.print();
	cout << s1.find('l') << endl;
	Mystring s2("World");
	s1.append(s2);
	s1.print();
}
