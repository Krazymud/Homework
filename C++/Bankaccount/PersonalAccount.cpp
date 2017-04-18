#include "PersonalAccount.h"
int PersonalAccount::_total_per_account = 0;
int PersonalAccount::_acc_id_ptr = 12010000;
PersonalAccount::PersonalAccount(){
	_id = _acc_id_ptr;
	_balance = 10;
	_valid = true;
	_total_per_account++;
	_acc_id_ptr++;
}
PersonalAccount::~PersonalAccount() {
	_total_per_account--;
}
// override
std::string PersonalAccount::profile() const {
	std::string output;
	char temp[100];
	snprintf(temp, 99, "ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:PERSONAL\n", _id, _balance);
	output = temp;
	return output;
}
void PersonalAccount::reset() {
	_balance = 10;
}
// static
int PersonalAccount::get_total_per_account() {
	return _total_per_account;
}