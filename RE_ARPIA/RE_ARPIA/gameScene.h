#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "ZeroCameraManager.h"
#include "ZeroSceneManager.h"

#include "gameScene_class1.h"
#include "gameScene_class2.h"
#include "gameScene_class3.h"
#include "gameScene_maleToilet1.h"
#include "gameScene_maleToilet2.h"
#include "gameScene_maleToilet3.h"
#include "gameScene_femaleToilet1.h"
#include "gameScene_femaleToilet2.h"
#include "gameScene_femaleToilet3.h"
#include "gameScene_office.h"

#include "Player.h"
class gameScene : public ZeroIScene //�÷��̾ ù ���� �Ǵ� ����
{
private:
	bool office = false, maleToilet = false, femaleToilet = false, _classPortal = false;
	unsigned long oColorB, mColorB, fColorB, cColorB;
public:
	gameScene();
	~gameScene();

	void Update(float eTime);
	void Render();
	void SetCameraPos();
	void PlayerUpdate(float eTime);
	void SetResource();
	void TakePortal();
	void PortalEffect();

	ZeroSprite *floor[4];

	ZeroSprite *classPortal[6];
	ZeroSprite *femaleToiletPortal[3];
	ZeroSprite *maleToiletPortal[3];
	ZeroSprite *officePortal[1];

	list<ZeroSprite*> backgroundList;
	list<ZeroSprite*> portalList;
	int currentFloor; //���� ���� �˷���
};

