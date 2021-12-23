#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
class ASpell;

class SpellBook {
private:
	std::vector<ASpell*> _spell;
	SpellBook(const SpellBook& copy);
	SpellBook& operator=(const SpellBook& other);
public:
	SpellBook();
	virtual ~SpellBook();

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string const & spellName);
	ASpell* createSpell(std::string const & spellName);
};