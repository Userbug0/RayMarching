#include "MainApp.h"
#include "Settings.h"


MainApp::MainApp()
	: m_running(false)
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
	}
}


void MainApp::render()
{
	m_Window->clear();

	m_Window->display();
}


void MainApp::update(const sf::Time& frameTime)
{

}


MainApp::~MainApp()
{
	delete m_Window;
}
