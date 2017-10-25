#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include <list>
class Player : public ZeroIScene
{
private:
	float gravity;
	bool isJump;
public:
	Player();
	~Player();
	void Update(float eTime);
	void Render();

	void Move(float eTime);//�̵����� �Լ�
	void Physics(float eTime); //�߷� �� ���� ���� �Լ�
	void SetObjectPos(); //��������Ʈ�� ��ġ�� Ŭ������ ���� ������

	std::list<ZeroSprite*> spriteList;
	ZeroSprite *player;	
};