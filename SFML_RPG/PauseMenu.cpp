#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow& window)
{
	//Init background
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x), 
			static_cast<float>(window.getSize().y)
		)
	);
	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	//Init container
	this->container.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x) / 4.f,
			static_cast<float>(window.getSize().y) - 60.f
		)
	);
	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition(
		static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f,
		30.f
	);
}

PauseMenu::~PauseMenu()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

//Functions
void PauseMenu::update()
{

}

void PauseMenu::render(sf::RenderTarget & target)
{
	target.draw(background);
	target.draw(container);

	for (auto &i : this->buttons)
	{
		i.second->render(target);
	}
}