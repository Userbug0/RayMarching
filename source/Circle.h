#pragma once

#include <SFML/Graphics.hpp>

#include "Object.h"


class Circle: public Object
{
public:
	Circle(const Vector2& position, float radius);

	void Draw(sf::RenderWindow* window) const override;

	float GetSignedDistance(const Vector2& point) const override;

private:
	sf::CircleShape m_toDraw;
	Vector2 m_position;
};
