#pragma once

#include "MovAble.h"
#include "Object.h"


class RayMarcher: public MovAble
{
public:
	RayMarcher(float speed, const Vector2& position, const Vector2& sightDir);

	void Draw(sf::RenderWindow* window, const std::vector<Object*>& m_objects);
	void LookAt(const Vector2& direction);

private:
	void drawRay(sf::RenderWindow* window);
	void marching(sf::RenderWindow* window, const std::vector<Object*>& m_objects);

	Vector2 m_sightDir;
	float m_rayLength;
};
