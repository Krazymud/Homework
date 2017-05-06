#include "Dress.hpp"
Dress::Dress(const string & name, const int price) {
	this->name = name;
	this->price = price;
}
Dress::Dress(const Dress & oth) {
	name = oth.name;
	price = oth.price;
}