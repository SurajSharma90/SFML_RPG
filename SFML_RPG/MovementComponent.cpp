#include "stdafx.h"
#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, 
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite),
	m_maxVelocity(maxVelocity), m_acceleration(acceleration), m_deceleration(deceleration)
{
	
}

MovementComponent::~MovementComponent()
{

}

//Accessors
const float & MovementComponent::getMaxVelocity() const
{
	return this->m_maxVelocity;
}

const sf::Vector2f & MovementComponent::getVelocity() const
{
	return this->m_velocity;
}

//Functions
const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state)
	{
	case IDLE:

		if (this->m_velocity.x == 0.f && this->m_velocity.y == 0.f)
			return true;

		break;

	case MOVING:

		if (this->m_velocity.x != 0.f || this->m_velocity.y != 0.f)
			return true;

		break;

	case MOVING_LEFT:

		if (this->m_velocity.x < 0.f)
			return true;

		break;

	case MOVING_RIGHT:

		if (this->m_velocity.x > 0.f)
			return true;

		break;

	case MOVING_UP:

		if (this->m_velocity.y < 0.f)
			return true;

		break;

	case MOVING_DOWN:

		if (this->m_velocity.y > 0.f)
			return true;

		break;
	}

	return false;
}

void MovementComponent::stopVelocity()
{
	/* Resets the m_velocity to 0.*/

	this->m_velocity.x = 0.f;
	this->m_velocity.y = 0.f;
}

void MovementComponent::stopVelocityX()
{
	/* Resets the m_velocity x to 0.*/

	this->m_velocity.x = 0.f;
}

void MovementComponent::stopVelocityY()
{
	/* Resets the m_velocity y to 0.*/

	this->m_velocity.y = 0.f;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	/* Accelerating a sprite until it reaches the max m_velocity. */
	acceleration(dir_x, dir_y, dt);
}

void MovementComponent::update(const float & dt)
{
	/*
	Decelerates the sprite and controls the maximum m_velocity.
	Moves the sprite.
	*/
	maxVelocityCheck();
	deceleration(dt);

	//Final move
	this->sprite.move(this->m_velocity * dt); //Uses m_velocity
}

inline void MovementComponent::acceleration(const float dir_x, const float dir_y, const float& dt)
{
	this->m_velocity.x += this->m_acceleration * dir_x * dt;
	this->m_velocity.y += this->m_acceleration * dir_y * dt;
}
inline void MovementComponent::deceleration(const float& dt)
{
	if (this->m_velocity.x > 0.f) //Check for positive x
	{
		//Deceleration
		this->m_velocity.x -= m_deceleration * dt;
		if (this->m_velocity.x < 0.f)
			this->m_velocity.x = 0.f;
	}
	else if (this->m_velocity.x < 0.f) //Check for negative x
	{
		//Deceleration
		this->m_velocity.x += m_deceleration * dt;
		if (this->m_velocity.x > 0.f)
			this->m_velocity.x = 0.f;
	}

	if (this->m_velocity.y > 0.f) //Check for positive y
	{
		//Deceleration
		this->m_velocity.y -= m_deceleration * dt;
		if (this->m_velocity.y < 0.f)
			this->m_velocity.y = 0.f;
	}
	else if (this->m_velocity.y < 0.f) //Check for negative y
	{
		//Deceleration
		this->m_velocity.y += m_deceleration * dt;
		if (this->m_velocity.y > 0.f)
			this->m_velocity.y = 0.f;
	}
}

inline void MovementComponent::maxVelocityCheck()
{
	// X
	if (this->m_velocity.x > 0.f) //Check for positive x
	{
		if (this->m_velocity.x > this->m_maxVelocity)
			this->m_velocity.x = this->m_maxVelocity;
	}
	else if (this->m_velocity.x < 0.f) //Check for negative x
	{
		if (abs(this->m_velocity.x) > this->m_maxVelocity)
			this->m_velocity.x = -this->m_maxVelocity;
	}

	// Y
	if (this->m_velocity.y > 0.f) //Check for positive y
	{
		if (this->m_velocity.y > this->m_maxVelocity)
			this->m_velocity.y = this->m_maxVelocity;
	}
	else if (this->m_velocity.y < 0.f) //Check for negative y
	{
		if (abs(this->m_velocity.y) > this->m_maxVelocity)
			this->m_velocity.y = -this->m_maxVelocity;
	}
}