#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
	std::vector<ASpell*>::iterator it = _spell.begin();
	std::vector<ASpell*>::iterator it2 = _spell.end();
	for (; it != it2; ++it) {
		delete *it;
	}
	_spell.clear();
}

void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void Warlock::learnSpell(ASpell* spell) {
	if (spell) {
		std::vector<ASpell*>::iterator it = _spell.begin();
		std::vector<ASpell*>::iterator it2 = _spell.end();
		for (; it != it2; ++it) {
			if ((*it)->getName() == spell->getName()) {
				return ;
			}
		}
		_spell.push_back(spell->clone());
	}
}

void Warlock::forgetSpell(std::string spellName) {
	std::vector<ASpell*>::iterator it = _spell.begin();
	std::vector<ASpell*>::iterator it2 = _spell.end();
	for (; it != it2; ++it) {
		if ((*it)->getName() == spellName) {
			delete *it;
			_spell.erase(it);
			return ;
		}
	}
}

void Warlock::launchSpell(std::string spellName, const ATarget& target) {
	std::vector<ASpell*>::iterator it = _spell.begin();
	std::vector<ASpell*>::iterator it2 = _spell.end();
	for (; it != it2; ++it) {
		if ((*it)->getName() == spellName) {
			(*it)->launch(target);
			return ;
		}
	}
}
