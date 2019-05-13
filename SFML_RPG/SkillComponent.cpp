#include "stdafx.h"
#include "SkillComponent.h"

SkillComponent::SkillComponent()
{
	this->skills["health"];
	this->skills["endurance"];
	this->skills["melee"];
	this->skills["ranged"];
	this->skills["accuracy"];
	this->skills["defence"];

	this->skills["mining"];
	this->skills["woodcutting"];
}

SkillComponent::~SkillComponent()
{

}

const int SkillComponent::getSkill(const std::string key) const
{
	if (this->skills.count(key))
		return this->skills.at(key).getLevel();
	else
		throw("ERROR::SKILLCOMPONENT::SKILL DOES NOT EXIST: " + key);
}
