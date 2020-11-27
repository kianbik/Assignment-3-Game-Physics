#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();
	TextureManager::Instance()->load("../Assets/textures/background.png", "background2");
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	TextureManager::Instance()->draw("background2", 400, 300, 0, 255, true);
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	const SDL_Color blue = { 0, 0, 255, 255 };
	const SDL_Color red = { 250, 0, 0, 255 };
	m_pAssignmentLabel = new Label("Assignment 3", "Consolas", 40, red, glm::vec2(400.0f, 75.0f));
	m_pAssignmentLabel->setParent(this);
	addChild(m_pAssignmentLabel);

	m_pNestorLabel = new Label("Nestor Plata 101282246", "Consolas", 40, blue, glm::vec2(400.0f, 125.0f));
	m_pNestorLabel->setParent(this);
	addChild(m_pNestorLabel);

	m_pKianLabel = new Label("Kian Badieikhorsand", "Consolas", 40, blue, glm::vec2(400.0f, 175.0f));
	m_pKianLabel->setParent(this);
	addChild(m_pKianLabel);

	m_pKianLabel2 = new Label("101282433", "Consolas", 40, blue, glm::vec2(400.0f, 225.0f));
	m_pKianLabel2->setParent(this);
	addChild(m_pKianLabel2);

	

	// Start Button
	
	m_pStartButton = new Button("../Assets/textures/SceneOneButton.png", "PlaySceneOne", START_BUTTON);
	m_pStartButton->getTransform()->position = glm::vec2(300.0f, 450.0f); 

	m_pStartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pStartButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	});
	
	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pStartButton->setAlpha(128);
	});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pStartButton->setAlpha(255);
	});
	addChild(m_pStartButton);

	

// Start Button
	m_pSceneTwoButton = new Button("../Assets/textures/SceneTwoButton.png", "PlaySceneTwo", START_BUTTON);
m_pSceneTwoButton->getTransform()->position = glm::vec2(500.0f, 450.0f);

m_pSceneTwoButton->addEventListener(CLICK, [&]()-> void
	{
		m_pSceneTwoButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE_TWO);
	});

m_pSceneTwoButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pSceneTwoButton->setAlpha(128);
	});

m_pSceneTwoButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pSceneTwoButton->setAlpha(255);
	});
addChild(m_pSceneTwoButton);


}


