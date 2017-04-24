#include "State.hpp"
#include "Parser.hpp"
#include "Token.hpp"
#include "Bulider.hpp"
State* DataState::_instance = NULL;
State* TagNameState::_instance = NULL;
State* DataState::getInstance(){
	if (_instance == NULL) {
		_instance = new DataState();
	}
	return _instance;
}
State* TagNameState::getInstance() {
	if (_instance == NULL) {
		_instance = new TagNameState();
	}
	return _instance;
}
void TagNameState::destroyInstance() {
	if(_instance != NULL)
		delete _instance;
	_instance = NULL;
}
void DataState::destroyInstance() {
	if (_instance != NULL)
		delete _instance;
	_instance = NULL;
}
void DataState::handleOneChar(Parser* parser, char ch) {
	if (ch == '<') {
		if (_cache.size() != 0) {
			int first = _cache.find_first_not_of(' ');
			int last = _cache.find_last_not_of(' ');
			if (first != -1) {
				string temp;
				for (int i = first; i <= last; i++)
					temp += _cache[i];
				Token token;
				token.type = "data";
				token.content = temp;
				Bulider* bulider = Bulider::getInstance();
				bulider->handleOneToken(token);
			}
			_cache = "";
		}
		parser->setState(TagNameState::getInstance());
	}
	else {
			_cache += ch;
	}
}
void TagNameState::handleOneChar(Parser* parser, char ch) {

	if (ch == '>') {
		Token token;
		token.type = "tag";
		token.content = _cache;
		Bulider* bulider = Bulider::getInstance();
		bulider->handleOneToken(token);
		_cache = "";
		parser->setState(DataState::getInstance());
	}
	else {
			_cache += ch;
	}
}
