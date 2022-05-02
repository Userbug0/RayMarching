#include "MainApp.h"
#include "Settings.h"


MainApp::MainApp()
	: m_running(false), m_backgroundColor({ 30, 30, 30 }),
	  m_Player(150, { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}, {1, 0})
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	m_Window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "DDA-3D", sf::Style::Close, settings);
	m_Window->setFramerateLimit(FPS);
}


void MainApp::Start()
{
	m_running = true;
	gameLoop();
}


void MainApp::gameLoop()
{
	sf::Clock clock;

	while (m_running)
	{
		handleEvents();
		render();
		update(clock.getElapsedTime());

		clock.restart();
	}
}


void MainApp::handleEvents()
{
	sf::Event event;

	while (m_Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_running = false;

		else if (event.type == sf::Event::KeyPressed)
			m_Player.OnKeyPressed(event.key.code);

		else if (event.type == sf::Event::KeyReleased)
			m_Player.OnKeyReleased(event.key.code);

		else if (event.type == sf::Event::MouseMoved)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(*m_Window);
			m_Player.LookAt({(float)mousePos.x, (float)mousePos.y});
		}
	}
}


void MainApp::render()
{
	m_Window->clear(m_backgroundColor);

	m_Player.Draw(m_Window);

	m_Window->display();
}


void MainApp::update(const sf::Time& frameTime)
{
	m_Player.Move(frameTime.asSeconds());
}


MainApp::~MainApp()
{
	delete m_Window;
}
