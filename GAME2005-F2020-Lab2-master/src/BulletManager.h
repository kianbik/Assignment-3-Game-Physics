#pragma once
#include "Bullet.h"
#include "BulletPool.h"
#include "PlayScene.h"

class BulletManager
{


private:
	BulletPool* m_pPool;
	PlayScene* m_pScene;
	void spawnBullet();
	

	float spawnTime; 
	float timer;

public:
	BulletManager(PlayScene*);
	void update();


};

