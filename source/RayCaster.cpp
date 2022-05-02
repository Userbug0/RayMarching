#include "RayCaster.h"


RayCaster::RayCaster(float speed, const Vector2& position, const Vector2& sightDir)
	: MovAble(speed, position), m_sightDir(sightDir)
{
	m_sightDir.normalize();
}


void RayCaster::Draw(sf::RenderWindow* window)
{
	MovAble::Draw(window);
}



void RayCaster::LookAt(const Vector2& direction)
{
	m_sightDir = direction;
	m_sightDir.normalize();
}
