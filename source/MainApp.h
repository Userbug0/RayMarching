#pragma once

#include <SFML/Graphics.hpp>
#include "RayMarcher.h"


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

	sf::RenderWindow* m_Window;
	RayMarcher m_Player;

	sf::Color m_backgroundColor;
	bool m_running;
};

