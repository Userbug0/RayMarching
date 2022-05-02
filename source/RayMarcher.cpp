#include "RayMarcher.h"
#include "Settings.h"


RayMarcher::RayMarcher(float speed, const Vector2& position, const Vector2& sightDir)
	: MovAble(speed, position), m_sightDir(sightDir), m_rayLength(0)
{
	m_sightDir.normalize();
}


void RayMarcher::Draw(sf::RenderWindow* window, const std::vector<Object*>& m_objects)
{
	drawRay(window);

	marching(window, m_objects);

	MovAble::Draw(window);
}


void RayMarcher::marching(sf::RenderWindow* window, const std::vector<Object*>& m_objects)
{
	float minDistance = WINDOW_WIDTH;
	float signedDistance;
	Vector2 point = GetPosition();

	sf::CircleShape visualized;
	visualized.setPointCount(75);
	visualized.setFillColor({50, 50, 50, 128});
	visualized.setOutlineThickness(1.f);

	while (Vector2::Distance(point, GetPosition()) < m_rayLength)
	{
		for (auto& object : m_objects)
		{
			signedDistance = object->GetSignedDistance(point);
			if (minDistance > signedDistance)
				minDistance = signedDistance;
		}

		if (minDistance >= 1)
		{
			visualized.setRadius(minDistance);
			visualized.setPosition(point - Vector2(minDistance, minDistance));
			window->draw(visualized);;

			point += m_sightDir * minDistance;
			minDistance = WINDOW_WIDTH;
		}
		else
		{
			visualized.setRadius(3);
			visualized.setFillColor({ 255, 255, 255 });
			visualized.setPosition(point - Vector2(3, 3));
			window->draw(visualized);
			break;
		}
	}
}


void RayMarcher::drawRay(sf::RenderWindow* window)
{
	Vector2 start = GetPosition();
	m_rayLength = std::max(Vector2::Distance(start, { 0, 0 }), m_rayLength);
	m_rayLength = std::max(Vector2::Distance(start, { WINDOW_WIDTH, 0 }), m_rayLength);
	m_rayLength = std::max(Vector2::Distance(start, { WINDOW_WIDTH, WINDOW_HEIGHT }), m_rayLength);
	m_rayLength = std::max(Vector2::Distance(start, { 0, WINDOW_HEIGHT }), m_rayLength);

	Vector2 end = start + m_sightDir * m_rayLength;

	sf::Vertex line[] = { sf::Vertex(start, {200, 200, 200}), sf::Vertex(end, {150, 150, 150}) };
	window->draw(line, 2, sf::Lines);
}


void RayMarcher::LookAt(const Vector2& direction)
{
	m_sightDir = direction - GetPosition();
	m_sightDir.normalize();
}
