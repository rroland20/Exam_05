#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
	std::string _name;
	std::string _effects;
public:
	ASpell();
	ASpell(const std::string& name, const std::string& effects);
	virtual ~ASpell();
	ASpell(const ASpell& copy);
	ASpell& operator=(const ASpell& other);

	const std::string& getName() const { return _name; }
	const std::string& getEffects() const { return _effects; }
	virtual ASpell* clone() const = 0;
	void launch(const ATarget& target) const;
};