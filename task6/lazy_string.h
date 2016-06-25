#ifndef LAZY_STRING_H
#define LAZY_STRING_H


#include <iostream>
#include <string>

class lazy_string {
private:
	struct shell {
		std::string data; //array of chars
		int links; //numbver of outcoming links

		shell() {
			data = std::string();
			links = 1;
		}

		shell(const std::string s) {
			data = s;
			links = 1;
		}
	};
	shell *sh;
	int len, shift;

	void detach();
public:
	lazy_string(); // make new empty lazy_string
	~lazy_string(); //delete lazy_string

	lazy_string(const std::string &); //make new lazy_string from std::string
	lazy_string(const lazy_string &); //make new lazy_string from lazy_string

	int size() const; //return size of lazy_string

	int length() const; //return length of lazy_string

	char at(const int) const; //return char at given position

	char &operator[](const int i); //return link of a char at position i
	char operator[](const int i) const; //return char at poistion i

	lazy_string substr(const int, const int); //return substring of lazy_string [ind, ind + shift)

	friend std::ostream &operator << (std::ostream &, lazy_string &); //print lazy_string from output stream
	friend std::istream &operator >> (std::istream &, lazy_string &); //take lazy_string from input stream
};
#endif