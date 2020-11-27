#include "PlaySceneTwo.h"
#include "Game.h"
#include "EventManager.h"
#include "Util.h"

PlaySceneTwo::PlaySceneTwo()
{
	PlaySceneTwo::start();
	TextureManager::Instance()->load("../Assets/textures/Scene2.png", "background");

}

PlaySceneTwo::~PlaySceneTwo()
= default;

void PlaySceneTwo::draw()
{
	TextureManager::Instance()->draw("background", 400, 300, 0, 255, true);
	drawDisplayList();

}

void PlaySceneTwo::update()
{
	SDL_GetTicks();

	float deltatime = 1.0f / 60.0f;

	updateDisplayList();

	if (SDL_GetTicks() - bulletSpawntimerStart >= bulletSpawntimerDuration) {
		SpawnBullet();
	}

	for (std::vector<Bullet*>::iterator myiter = m_pPool->active.begin(); myiter != m_pPool->active.end(); myiter++) {
		Bullet* bullet = *myiter;
		if (bullet->getTransform()->position.y >= 650) {
			m_pPool->Despawn(bullet);
			return;
		}

	}

}

void PlaySceneTwo::clean()
{
	removeAllChildren();
}

void PlaySceneTwo::handleEvents()
{
	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
	{
		m_pPlayer->moveLeft();
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D))
	{
		m_pPlayer->moveRight();
	}
	else {
		m_pPlayer->stopMovingX();
	}
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_W)) {
		m_pPlayer->moveUp();
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_S)) {
		m_pPlayer->moveDown();
	}
	else {
		m_pPlayer->stopMovingY();
	}


	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}
}

void PlaySceneTwo::start()
{

	// Player Sprite
	m_pPlayer = new Player();
	addChild(m_pPlayer);


	m_pPool = new BulletPool(10);
	bulletSpawntimerStart = SDL_GetTicks();
}
void PlaySceneTwo::SpawnBullet() {

	for (int i = 0; i < 10; i++) {
		Bullet* bullet = m_pPool->Spawn();
		if (bullet) {
			addChild(bullet);
			bullet->getTransform()->position = glm::vec2(0, 0);
		}
	}
	bulletSpawntimerStart = SDL_GetTicks();
}
