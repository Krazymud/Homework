#include "Bulider.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
Bulider* Bulider::_instance = NULL;
Bulider* Bulider::getInstance() {
	if (_instance == NULL) {
		_instance = new Bulider();
	}
	return _instance;
}
void Bulider::destroyInstance() {
	if (_instance != NULL)
		delete _instance;
	_instance = NULL;
}
void Bulider::handleOneToken(Token token) {
	if (token.type == "data") {
		if (_tokens.back().content.size() == 0)
			token.depth = _stack.size() - 1;
		else
			token.depth = _stack.size();
		_tokens.push_back(token);
	}
	else {
		if (token.content[0] == '/') {
			string temp;
			for (int i = 1; i < token.content.size(); i++)
				temp += token.content[i];
			if (_stack.empty() || _stack.top().content != temp)
				_error = true;
			else {
				_stack.pop();
			}
		}
		else {
			Token _token;
			_token.type = "tag";
			if (_stack.size() == 0)
				token.depth = 0;
			else 
				token.depth = _stack.size();
			_token.depth = token.depth;
			_token.content = token.content;
			_stack.push(_token);
			_tokens.push_back(token);
		}
	}
}
void Bulider::display() {
	if (_error == true)
		cout << "INVALID INPUT" << endl;
	else
		for (int n = 0; n < _tokens.size(); n++) {
			if (_tokens[n].type == "tag") {
				if (_tokens[n].content.size()) {
					for (int i = 0; i < _tokens[n].depth; i++)
						cout << "  ";
					cout << _tokens[n].content << ":" << endl;
				}
			}
			else {
				for (int i = 0; i < _tokens[n].depth; i++)
					cout << "  ";
				cout << _tokens[n].content << endl;
			}
		}
}