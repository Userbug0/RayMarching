#pragma once

#include "Object.h"


class Rect: public Object
{
public:
	Rect(const Vector2& position, float width, float height);

	void Draw(sf::RenderWindow* window) const override;
	float GetSignedDistance(const Vector2& point) const override;

private:
	sf::RectangleShape m_shape;
	/// <summary>
	/// Left upper corner
	/// </summary>
	Vector2 m_position;
};
