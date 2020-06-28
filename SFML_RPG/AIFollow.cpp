#include "stdafx.h"
#include "AIFollow.h"a

AIFollow::AIFollow(Entity& self, Entity& entity)
	: AIOption(self, entity)
{

}

AIFollow::~AIFollow()
{

}

void AIFollow::update(const float& dt)
{
	sf::Vector2f moveVec;
	moveVec.x = self.getPosition().x - entity.getPosition().x;
	moveVec.y = self.getPosition().y - entity.getPosition().y;
	float vecLength = sqrt(pow(moveVec.x, 2) + pow(moveVec.y, 2));
	moveVec /= vecLength;

	if (self.getPosition().x != entity.getPosition().x)
		self.move(moveVec.x, moveVec.y, dt);
}
