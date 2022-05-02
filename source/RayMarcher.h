#pragma once

#include "MovAble.h"
#include "Circle.h"


class RayMarcher: public MovAble
{
public:
	RayMarcher(float speed, const Vector2& position, const Vector2& sightDir);

	void Draw(sf::RenderWindow* window, const std::vector<Circle>& circles);
	void LookAt(const Vector2& direction);

private:
	void drawRay(sf::RenderWindow* window);
	void marching(sf::RenderWindow* window, const std::vector<Circle>& circles);

	Vector2 m_sightDir;
	float m_rayLength;
};
