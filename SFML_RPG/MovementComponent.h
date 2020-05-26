#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

enum movement_states { IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float m_maxVelocity;
	float m_acceleration;
	float m_deceleration;

	sf::Vector2f m_velocity;

	//Initializer functions

	//Support functions
	inline void acceleration(const float dir_x, const float dir_y, const float& dt);
	inline void deceleration(const float& dt);

	inline void maxVelocityCheck();

public:
	MovementComponent(sf::Sprite& sprite, 
		float maxVelocity, float acceleration, float deceleration);
	virtual ~MovementComponent();

	//Accessors
	const float& getMaxVelocity() const;
	const sf::Vector2f& getVelocity() const;

	//Functions
	const bool getState(const short unsigned state) const;
	void stopVelocity();
	void stopVelocityX();
	void stopVelocityY();

	void move(const float x, const float y, const float& dt);
	void update(const float& dt);
};

#endif