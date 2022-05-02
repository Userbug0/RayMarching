#include "RayMarcher.h"
#include "Settings.h"


RayMarcher::RayMarcher(float speed, const Vector2& position, const Vector2& sightDir)
	: MovAble(speed, position), m_sightDir(sightDir)
{
	m_sightDir.normalize();
}


void RayMarcher::Draw(sf::RenderWindow* window)
{
	drawRay(window);

	MovAble::Draw(window);
}


void RayMarcher::drawRay(sf::RenderWindow* window)
{
	Vector2 start = GetPosition();
	float rayLength = 0;
	rayLength = std::max(Vector2::Distance(start, { 0, 0 }), rayLength);
	rayLength = std::max(Vector2::Distance(start, { WINDOW_WIDTH, 0 }), rayLength);
	rayLength = std::max(Vector2::Distance(start, { WINDOW_WIDTH, WINDOW_HEIGHT }), rayLength);
	rayLength = std::max(Vector2::Distance(start, { 0, WINDOW_HEIGHT }), rayLength);

	Vector2 end = start + m_sightDir * rayLength;

	sf::Vertex line[] = { sf::Vertex(start), sf::Vertex(end) };
	window->draw(line, 2, sf::Lines);
}


void RayMarcher::LookAt(const Vector2& direction)
{
	m_sightDir = direction - GetPosition();
	m_sightDir.normalize();
}
