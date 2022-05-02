#include "MovAble.h"


MovAble::MovAble(float speed, const Vector2& position)
	: m_radius(6), m_direction(0, 0), m_position(position), m_speed(speed)
{
	m_toDraw.setRadius(m_radius);
	m_toDraw.setFillColor(sf::Color::White);
	m_toDraw.setPosition({ m_position.x - m_radius, m_position.y - m_radius });
}


void MovAble::Draw(sf::RenderWindow* window)
{
	m_toDraw.setPosition({ m_position.x - m_radius, m_position.y - m_radius });

	window->draw(m_toDraw);
}


Vector2 MovAble::GetPosition() const
{
	return m_position;
}


void MovAble::Move(float frameTime)
{
	m_position += m_direction * m_speed * frameTime;
}


void MovAble::OnKeyPressed(const sf::Keyboard::Key& keycode)
{
	if (keycode == sf::Keyboard::A)
		m_direction = { -1, 0 };

	else if (keycode == sf::Keyboard::W)
		m_direction = { 0, -1 };

	else if (keycode == sf::Keyboard::D)
		m_direction = { 1, 0 };

	else if (keycode == sf::Keyboard::S)
		m_direction = { 0, 1 };
}


void MovAble::OnKeyReleased(const sf::Keyboard::Key& keycode)
{
	if (keycode == sf::Keyboard::A || keycode == sf::Keyboard::W || 
		keycode == sf::Keyboard::D || keycode == sf::Keyboard::S)
		m_direction = { 0, 0 };
}
