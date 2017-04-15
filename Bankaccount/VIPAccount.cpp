#include "VIPAccount.h"
int VIPAccount::_total_vip_account = 0;
int VIPAccount::_acc_id_ptr = 12050000;
VIPAccount::VIPAccount() {
	_id = _acc_id_ptr;
	_balance = 10;
	_valid = true;
	_loan_limit = 1000;
	_loan = 0;
	_total_vip_account++;
	_acc_id_ptr++;
}
VIPAccount::~VIPAccount() {
	_total_vip_account--;
}
bool VIPAccount::loan(const double &num) {
	if (_loan + num <= _loan_limit) {
		_loan += num;
		_balance += num;
		return true;
	}
	return false;
}
bool VIPAccount::repay(const double &num) {
	if (num <= (_balance - 0.01)) {
		_balance -= num;
		_loan -= num;
		return true;
	}
	return false;
}
// override
std::string VIPAccount::profile() const {
	std::string output;
	char temp[100];
	snprintf(temp, 99, "ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:VIP\nLOAN:%.6lf,LIMIT:%.6lf\n", _id, _balance, _loan, _loan_limit);
	output = temp;
	return output;
}
void VIPAccount::reset() {
	_balance = 10;
	_loan = 0;
}
// static
int VIPAccount::get_total_vip_account() {
	return _total_vip_account;
}