#pragma once

#include <SFML/Graphics.hpp>

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

	bool m_running;
	sf::RenderWindow* m_Window;
};

