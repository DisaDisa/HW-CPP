#pragma once
class rational {
public:
	rational();
	rational(int);
	rational(int, int);
	int getNum() const;
	int getDenom() const;
	rational operator + (rational const &) const;
	rational operator - (rational const &) const;
	rational operator * (rational const &) const;
	rational operator / (rational const &) const;

	~rational();
private:
	int num, denom;
	int gcd(int, int) const;
	rational normal(rational) const;

	
};

