#include "rational.h"
#include <algorithm>

rational::rational() {}
rational::rational(int num) : num(num), denom(1) {};
rational::rational(int num, int denom) {
	int g = gcd(num, denom);
	this->num = num / g;
	this->denom = denom / g;
};

int rational::getNum() const {
	return num;
}

int rational::getDenom() const {
	return denom;
}

rational rational::operator + (rational const &q) const {
	int lcm = denom / gcd(denom, q.denom) * q.denom;
	int first = num * (lcm / denom);
	int second = q.num * (lcm / q.denom);
	return normal(rational(first + second, lcm));
}

rational rational::operator - (rational const &q) const {
	int lcm = denom / gcd(denom, q.denom) * q.denom;
	int first = num * (lcm / denom);
	int second = q.num * (lcm / q.denom);
	return normal(rational(first - second, lcm));
}

rational rational::operator * (rational const &q) const {
	return normal(rational(num * q.num, denom * q.denom));
}

rational rational::operator / (rational const &q) const {
	return normal(rational(num * q.denom, denom * q.num));
}


int rational::gcd(int a, int b) const {
	a = std::abs(a);
	b = std::abs(b);
	while (a > 0) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

rational rational::normal(rational &a) const {
	int g = gcd(a.num, a.denom);
	return rational(a.num / g, a.denom / g);
}


rational::~rational() {
}
