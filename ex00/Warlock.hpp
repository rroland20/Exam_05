#pragma once

#include <iostream>
#include <string>

class Warlock {
private:
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
};