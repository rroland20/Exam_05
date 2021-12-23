#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
	std::string _type;
public:
	ATarget();
	ATarget(const std::string& type);
	virtual ~ATarget();
	ATarget(const ATarget& copy);
	ATarget& operator=(const ATarget& other);
	void getHitBySpell(const ASpell& spell) const;

	const std::string& getType() const { return _type; }
	virtual ATarget* clone() const = 0;
};