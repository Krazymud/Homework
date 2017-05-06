#include "User.hpp"
#include "Mediator.hpp"
#include <string>
int User::Count = 0;
User::User(const string & name, const int & money, 
	const vector<pair<string, int> > & dresses) {
	this->name = name;
	this->money = money;
	id = Count++;
	for (int n = 0; n < dresses.size(); n++) {
		Dress temp(dresses[n].first, dresses[n].second);
		this->dresses.push_back(temp);
	}
}
void User::BuyBeautifulDress(const int & id, const int & pay,
	const string & name) {
	if (pay > money) {
		cout << this->name << " : " << "Forget to Check Wallet!" << endl;
		return;
	}
	Mediator* p = Mediator::getInstance();
	pair<int, string>temp = p->TradeHandler(id, pay, name);
	if(temp.second == "fuck")
		cout << this->name << " : " << "OMG! Why it is so Expensive!" << endl;
	else if(temp.second == "suck")
		cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
	else {
		money -= pay;
		cout << this->name << " : " << "So happy to get new Dress!" << endl;
		Dress temp_(temp.second, temp.first);
		dresses.push_back(temp_);
	}
}
void User::GetDressInfo(const int & id) {
	Mediator* p = Mediator::getInstance();
	cout << this->name << " : " << "I wanna see your beautiful suits!" << endl;
	p->DressInfoHandler(id);
}
pair<int, string> User::SellBeautifulDress(const int & pay, 
	const string & dname) {
	pair<int, string>temp;
	for (int n = 0; n < dresses.size(); n++){
		if (dname == dresses[n].getName()) {
			if (dresses[n].getPrice() > pay) {
				cout << this->name << " : " << "No monry then no talking" << endl;
				temp = std::make_pair(pay, "fuck");
				return temp;
			}
			else {
				cout << this->name << " : " << "What a good taste you have !" << endl;
				temp = std::make_pair(dresses[n].getPrice(), dname);
				dresses.erase(dresses.begin() + n);
				return temp;
			}
		}
	}
	cout << this->name << " : " << "I never have this Dress stupid!" << endl;
	temp = std::make_pair(pay, "suck");
	return temp;
}
void User::SendMessage(const int & to, const string & msg) {
	Mediator* p = Mediator::getInstance();
	p->ChatHandler(to, msg);
}
void User::GetMessage(const string & msg) {
	cout << this->name << " : I got a Msg - " << msg << endl;
}
void User::ShowMyCuteDresses() {
	cout << this->name << " : ok,these are all I have : " << endl;
	for (int i = 0; i < dresses.size(); i++)
		cout << dresses[i].getName() << "-" << dresses[i].getPrice() << endl;
}