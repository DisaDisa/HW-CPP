#include "lazy_string.h"
#include <string>

void lazy_string::detach() {
	if (sh->links == 1) return;
	shell *now = new shell((sh->data).substr(shift, len));
	(sh->links)--;
	sh = now;
	shift = 0;
}

lazy_string::lazy_string() {
	sh = new shell();
	shift = 0;
	len = 0;
}

lazy_string::lazy_string(const std::string &s) {
	sh = new shell(s);
	shift = 0;
	len = s.size();
}

lazy_string::lazy_string(const lazy_string &s) {
	sh = s.sh;
	(sh->links)++;
	shift = s.shift;
	len = s.len;
}

lazy_string::~lazy_string() {
	(sh->links)--;
	if (sh->links == 0)
		delete sh;
}

int lazy_string::size() const{
	return len;
}

int lazy_string::length() const{
	return len;
}

char lazy_string::at(const int ind) const {
	return sh->data[shift + ind];
}

lazy_string::my_char lazy_string::operator[](const int pos) {
    return my_char(this, pos);
}

char lazy_string::operator[](const int pos) const {
    return sh -> data[shift + pos];
}

lazy_string lazy_string::substr(const int ind, const int cnt) {
	lazy_string *tmp = new lazy_string();
	tmp->sh = sh;
	tmp->shift = shift + ind;
	tmp->len = cnt;
	(sh->links)++;
	return *tmp;
}

std::ostream &operator << (std::ostream &out, lazy_string &s) {
	for (int i = s.shift; i < s.shift + s.len; i++) {
		out << (s.sh->data[i]);
	}
	return out;
}

std::istream &operator >> (std::istream &in, lazy_string &s) {
	s.detach();
	std::string now;
	in >> now;
	s.sh->data = now;
	s.shift = 0;
	s.len = now.size();
	return in;
}


int main() {
	return 0;
}