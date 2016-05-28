#ifndef lazy_string
#define lazy_string

#include <iostream>
#include <string>

class lazy_string {
	private:
		struct shell {
			std::string data;
			int links;

			shell() {
				data = std::string();
				links = 1;
			}

			shell(std::string s) {
				data = s;
				links = 1;
			}
		};
		shell *sh;
		int len, shift;

		void detach();
	public:
		lazy_string();
		~lazy_string();

		lazy_string(const std:: string &);
		lazy_string(const lazy_string &);

		int size() const;

		int length() const;

		char at(conts int) const;

		char &operator[](const int i); //change
        char operator[](const int i) const; //at position

        lazy_string substr(const int, const int);

        friend std::ostream &operator << (std::ostream &, lazy_string &);
        friend std::istream &operator >> (std::istream &, lazy_string &);
};
#endif

			
			
