#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroAnimation.h"
#include "ZeroInputManager.h"
#define player Player::instance()
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
	int speed;
	bool isJump;
	bool isWalk;
	bool isGround;
	float groundPosY;
	float gravity;
public:
	static Player *instance();

	Player();
	~Player();
	void Update(float eTime);
	void Render();

	void Move(float eTime);//�̵����� �Լ�
	void Physics(float eTime); //�߷� �� ���� ���� �Լ�
	void SetObjectPos(); //��������Ʈ�� ��ġ�� Ŭ������ ���� ������
	void SetGround(float posY); //ĳ������ �׶��� ��ġ�� ���� ��) ���� �ٲ� ��
	float GetGround(); //ĳ������ �׶��� ��ġ�� ������
	void SetIsGround(bool _isGround);
	bool GetIsGround();

	PlayerStatues statue;

	std::list<ZeroIScene *> resourceList;
	ZeroSprite *playerStop;	
	ZeroAnimation *playerWalk;
	ZeroSprite *playerJump;
};