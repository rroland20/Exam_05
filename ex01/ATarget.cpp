#include "ATarget.hpp"

ATarget::ATarget() : _type() {}

ATarget::ATarget(const std::string& type) : _type(type) {}

ATarget::~ATarget() {}

ATarget::ATarget(const ATarget& copy) { *this = copy; }

ATarget& ATarget::operator=(const ATarget& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

void ATarget::getHitBySpell(const ASpell& spell) const {
	std::cout << _type << " has been " << spell.getEffects() << "!\n";
}
