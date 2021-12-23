#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	std::vector<ASpell*>::iterator it = _spell.begin();
	std::vector<ASpell*>::iterator it2 = _spell.end();
	for (; it != it2; ++it) {
		delete *it;
	}
	_spell.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
	if (spell) {
		std::vector<ASpell*>::iterator it = _spell.begin();
		std::vector<ASpell*>::iterator it2 = _spell.end();
		for (; it != it2; ++it) {
			if ((*it)->getName() == spell->getName())
				return ;
		}
		_spell.push_back(spell->clone());
	}
}

void SpellBook::forgetSpell(std::string const & spellName) {
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

ASpell* SpellBook::createSpell(std::string const & spellName) {
	std::vector<ASpell*>::iterator it = _spell.begin();
	std::vector<ASpell*>::iterator it2 = _spell.end();
	for (; it != it2; ++it) {
		if ((*it)->getName() == spellName)
			return *it;
	}
	return nullptr;
}

