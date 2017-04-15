#include "Account.h"   
int Account::_total_account = 0;
Account::Account() {
	_id = 0;
	_balance = 0;
	_valid = false;
	_total_account++;
}
Account::~Account() {
	_total_account--;
}
int Account::id() const {
	return _id;
}
double Account::balance() const {
	return _balance;
}
bool Account::valid() const {
	return _valid;
}
std::string Account::profile() const {
	std::string output;
	char temp[51];
	snprintf(temp, 50, "ID:%d\nBALANCE:%.6lf\nVALID:N\n", _id, _balance);
	output = temp;
	return output;
}
void Account::reset() {
	_balance = 0;
}
bool Account::deposit(const double &num) {
	_balance += num;
	return true;
}
bool Account::draw(const double &num) {
	if (_balance - num >= 0.01) {
		_balance -= num;
		return true;;
	}
	return false;
}
int Account::get_total_account() {
	return _total_account;
}
