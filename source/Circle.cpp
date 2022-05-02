#include "Circle.h"


Circle::Circle(const Vector2& position, float radius)
	: m_position(position)
{
	m_toDraw.setPosition(position - Vector2{ radius, radius });
	m_toDraw.setRadius(radius);
	m_toDraw.setFillColor(sf::Color::Black);
}


void Circle::Draw(sf::RenderWindow* window)
{
	window->draw(m_toDraw);
}


float Circle::GetRadius() const
{
	return m_toDraw.getRadius();
}


Vector2 Circle::GetPosition() const
{
	return m_position;
}
