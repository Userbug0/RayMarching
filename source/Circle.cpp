#include "Circle.h"


Circle::Circle(const Vector2& position, float radius)
	: m_position(position)
{
	m_shape.setPointCount(75);
	m_shape.setPosition(position - Vector2{ radius, radius });
	m_shape.setRadius(radius);
	m_shape.setFillColor(sf::Color::Black);
}


void Circle::Draw(sf::RenderWindow* window) const
{
	window->draw(m_shape);
}


float Circle::GetSignedDistance(const Vector2& point) const
{
	return Vector2::Distance(point, m_position) - m_shape.getRadius();
}

