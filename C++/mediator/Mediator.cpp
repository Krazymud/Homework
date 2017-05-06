#include "Mediator.hpp"

Mediator* Mediator::Ins = NULL;
void Mediator::RegisterHandler(User * u) {
	users.push_back(u);
}
void Mediator::ChatHandler(const int & to, const string & msg) {
	list<User*>::iterator itor = users.begin();
	while (itor != users.end()) {
		if ((*itor)->getId() == to)
			break;
		itor++;
	}
	(*itor)->GetMessage(msg);
}
pair<int, string> Mediator::TradeHandler(const int & to, const int & pay,
	const string & dressName) {
	list<User*>::iterator itor = users.begin();
	list<User*>::iterator itor_to = users.begin();
	int re = 0;
	while (itor != users.end()) {
		if ((*itor)->getId() == to) {
			re = 1;
			itor_to = itor;
		}
		itor++;
	}
	if (re == 1)
		return (*itor_to)->SellBeautifulDress(pay, dressName);
	else {
		cout << "There is no Such a guy!" << endl;
		pair<int, string>temp = std::make_pair(0, "stupid");
		return temp;
	}
}
void Mediator::DressInfoHandler(const int & to) {
	list<User*>::iterator itor = users.begin();
	while (itor != users.end()) {
		if ((*itor)->getId() == to)
			break;
		itor++;
	}
	(*itor)->ShowMyCuteDresses();
}