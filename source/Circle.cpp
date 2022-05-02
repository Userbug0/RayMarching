#include "Circle.h"


Circle::Circle(const Vector2& position, float radius)
	: m_position(position)
{
	m_toDraw.setPointCount(75);
	m_toDraw.setPosition(position - Vector2{ radius, radius });
	m_toDraw.setRadius(radius);
	m_toDraw.setFillColor(sf::Color::Black);
}


void Circle::Draw(sf::RenderWindow* window) const
{
	window->draw(m_toDraw);
}


float Circle::GetSignedDistance(const Vector2& point) const
{
	return Vector2::Distance(point, m_position) - m_toDraw.getRadius();
}

