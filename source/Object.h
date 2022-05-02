#pragma once

#include <SFML/Graphics.hpp>

#include "Vector2.h"


class Object
{
public:
	virtual void Draw(sf::RenderWindow* window) const = 0;
	virtual float GetSignedDistance(const Vector2& point) const = 0;
};
