#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void Warlock::learnSpell(ASpell* spell) {
	book.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName) {
	book.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget& target) {
	ASpell *spell = book.createSpell(spellName);
	if (spell)
		spell->launch(target);
}
