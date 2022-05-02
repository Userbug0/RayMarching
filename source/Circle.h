#pragma once

#include <SFML/Graphics.hpp>

#include "Vector2.h"


class Circle
{
public:
	Circle(const Vector2& position, float radius);

	void Draw(sf::RenderWindow* window) const;

	float GetSignedDistance(const Vector2& point) const;

private:
	sf::CircleShape m_toDraw;
	Vector2 m_position;
};
