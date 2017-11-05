#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "ZeroCameraManager.h"

#include "Player.h"
class gameScene : public ZeroIScene //�÷��̾ ù ���� �Ǵ� ����
{
public:
	gameScene();
	~gameScene();

	void Update(float eTime);
	void Render();

	ZeroSprite *floor[4];

	list<ZeroSprite*> backgroundList;
	int currentFloor; //���� ���� �˷���

	Player *player;
};

