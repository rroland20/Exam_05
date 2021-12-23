#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
private:
	std::vector<ASpell*> _spell;
	std::string _name;
	std::string _title;
	Warlock();
	Warlock(const Warlock& copy);
	Warlock& operator=(const Warlock& other);
public:
	Warlock(const std::string& name, const std::string& title);
	virtual ~Warlock();

	const std::string& getName() const { return _name; }
	const std::string& getTitle() const { return _title; }
	void setTitle(const std::string& title) { _title = title; }
	void introduce() const;

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, const ATarget& target);
};