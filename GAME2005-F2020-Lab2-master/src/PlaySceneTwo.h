#pragma once
#ifndef __PLAY_SCENE_TWO__
#define __PLAY_SCENE_TWO__

#include "Scene.h"
#include "Plane.h"
#include "Player.h"
#include "Button.h"
#include "Bullet.h"
#include "BulletPool.h"



class PlaySceneTwo : public Scene
{
public:
	PlaySceneTwo();
	~PlaySceneTwo();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
private:
	const float bulletSpawntimerDuration = 3000.0f;
	float bulletSpawntimerStart;
	glm::vec2 m_mousePosition;

	BulletPool* m_pPool;

	Plane* m_pPlaneSprite;
	Player* m_pPlayer;


	Button* m_pBackButton;
	Button* m_pNextButton;
	void SpawnBullet();
};

#endif /* defined (__PLAY_SCENE__) */