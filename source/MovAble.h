#pragma once

#include <SFML/Graphics.hpp>

#include "Vector2.h"
#include "Settings.h"


class MovAble
{
public:
	MovAble(float speed, const Vector2& position);

	void Move(float frameTime);
	void Draw(sf::RenderWindow* window);

	void OnKeyPressed(const sf::Keyboard::Key& keycode);
	void OnKeyReleased(const sf::Keyboard::Key& keycode);

	Vector2 GetPosition() const;

private:
	sf::CircleShape m_toDraw;
	float m_radius;

	Vector2 m_position;
	Vector2 m_direction;
	float m_speed;
};
