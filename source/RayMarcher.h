#pragma once

#include "MovAble.h"


class RayMarcher: public MovAble
{
public:
	RayMarcher(float speed, const Vector2& position, const Vector2& sightDir);

	void Draw(sf::RenderWindow* window);
	void LookAt(const Vector2& direction);

private:
	void drawRay(sf::RenderWindow* window);

	Vector2 m_sightDir;
};
