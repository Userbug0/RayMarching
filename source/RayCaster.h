#pragma once

#include "MovAble.h"


class RayCaster: public MovAble
{
public:
	RayCaster(float speed, const Vector2& position, const Vector2& sightDir);

	void Draw(sf::RenderWindow* window);
	void LookAt(const Vector2& direction);

private:
	Vector2 m_sightDir;
};
