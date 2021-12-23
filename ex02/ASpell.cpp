#include "ASpell.hpp"

ASpell::ASpell() : _name(), _effects() {}

ASpell::ASpell(const std::string& name, const std::string& effects): _name(name), _effects(effects) {}

ASpell::~ASpell() {}

ASpell::ASpell(const ASpell& copy) { *this = copy; }

ASpell& ASpell::operator=(const ASpell& other) {
	if (this != &other) {
		_name = other._name;
		_effects = other._effects;
	}
	return *this;
}

void ASpell::launch(const ATarget& target) const {
	target.getHitBySpell(*this);
}
