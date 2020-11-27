#include "Bullet.h"
#include "TextureManager.h"

Bullet::Bullet() {
	
	TextureManager::Instance()->load("../Assets/textures/bullet.png", "enemy");

	auto size = TextureManager::Instance()->getTextureSize("enemy");
	setWidth(size.x);
	setHeight(size.y);
	setType(ENEMY);
	Reset();
}

Bullet::~Bullet()
= default;

void Bullet::draw() {
	// alias for x and y
	if (active) {
		const auto x = getTransform()->position.x;
		const auto y = getTransform()->position.y;

		TextureManager::Instance()->draw("enemy", x, y, 0, 255, true);
	}
}

void Bullet::update() {
	if (active) {
		float deltatime = 1.0f / 60.0f;
		getRigidBody()->velocity = getRigidBody()->velocity + (getRigidBody()->acceleration * deltatime);
		getTransform()->position = getTransform()->position + getRigidBody()->velocity * deltatime;

	
	}
}

void Bullet::clean() {

}
void Bullet::Reset() {
	active = false;
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0, 9.8);
	getRigidBody()->isColliding = false;
}
