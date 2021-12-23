#pragma once

#include <vector>
#include "ATarget.hpp"
class ATarget;

class TargetGenerator {
private:
	std::vector<ATarget*> _target;
	TargetGenerator(const TargetGenerator& copy);
	TargetGenerator& operator=(const TargetGenerator& other);
public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget* target);
	void forgetTargetType(std::string const & targetName);
	ATarget* createTarget(std::string const & targetName);
};