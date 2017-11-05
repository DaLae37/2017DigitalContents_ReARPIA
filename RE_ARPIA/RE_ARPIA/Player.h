#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroAnimation.h"
#include "ZeroInputManager.h"
enum class PlayerStatues
{
	IDLE,
	LEFT_MOVE,
	RIGHT_MOVE,
	JUMP,
	ATTACK,
};
class Player : public ZeroIScene
{
private:
	float gravity;
	bool isJump;
	bool isWalk;
public:
	Player();
	~Player();
	void Update(float eTime);
	void Render();

	void Move(float eTime);//�̵����� �Լ�
	void Physics(float eTime); //�߷� �� ���� ���� �Լ�
	void SetObjectPos(); //��������Ʈ�� ��ġ�� Ŭ������ ���� ������

	PlayerStatues statue;

	std::list<ZeroIScene *> resourceList;
	ZeroSprite *playerStop;	
	ZeroAnimation *playerWalk;
	ZeroSprite *playerJump;
};