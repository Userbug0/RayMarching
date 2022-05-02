#pragma once

#include <SFML/Graphics.hpp>
#include "RayMarcher.h"
#include "Circle.h"


class MainApp
{
public:
	MainApp();
	~MainApp();

	void Start();

private:
	void gameLoop();
	void handleEvents();
	void render();
	void update(const sf::Time& frameTime);

	void initObjects();

	RayMarcher m_Player;
	std::vector<Circle> m_circles;

	sf::RenderWindow* m_Window;
	sf::Color m_backgroundColor;
	bool m_running;
};

