#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	std::vector<ATarget*>::iterator it = _target.begin();
	std::vector<ATarget*>::iterator it2 = _target.end();
	for (; it != it2; ++it) {
		delete *it;
	}
	_target.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
	if (target) {
		std::vector<ATarget*>::iterator it = _target.begin();
		std::vector<ATarget*>::iterator it2 = _target.end();
		for (; it != it2; ++it) {
			if ((*it)->getType() == target->getType())
				return ;
		}
		_target.push_back(target->clone());
	}
}

void TargetGenerator::forgetTargetType(std::string const & targetName) {
	std::vector<ATarget*>::iterator it = _target.begin();
	std::vector<ATarget*>::iterator it2 = _target.end();
	for (; it != it2; ++it) {
		if ((*it)->getType() == targetName) {
			delete *it;
			_target.erase(it);
			return ;
		}
	}
}

ATarget* TargetGenerator::createTarget(std::string const & targetName) {
	std::vector<ATarget*>::iterator it = _target.begin();
	std::vector<ATarget*>::iterator it2 = _target.end();
	for (; it != it2; ++it) {
		if ((*it)->getType() == targetName) {
			return *it;
		}
	}
	return nullptr;
}
