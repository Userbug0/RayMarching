#include "Rect.h"
#include "Settings.h"


Rect::Rect(const Vector2& position, float width, float height)
	: m_position(position), m_shape({ width, height })
{
	m_shape.setFillColor(sf::Color::Black);
	m_shape.setPosition(m_position);
}


float Rect::GetSignedDistance(const Vector2& point) const
{
	float dx = std::max({ m_position.x - point.x, 0.f, point.x - m_position.x - m_shape.getSize().x });
	float dy = std::max({ m_position.y - point.y, 0.f, point.y - m_position.y - m_shape.getSize().y });
	return std:: sqrt(dx * dx + dy * dy);
}


void Rect::Draw(sf::RenderWindow* window) const
{
	window->draw(m_shape);
}

