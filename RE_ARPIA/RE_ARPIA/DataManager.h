#pragma once
#include <string>
#include <fstream>
#define DataMgr DataManager::instance()
using namespace std;
class DataField {
public :
	//Global
	int currentScene = 0; //���� ���� �ε��� 0 : gameScene

	//GenderSetting
	bool isMale = false; //true�̸� ���� false�̸� ����
	bool isSettingGender = false; //������ ���� �Ǿ��ִ��� Ȯ���ϴ� ����

	//NameSetting
	char name[20]; //�̸�
	bool isSettingName = false; //�̸��� ������ �ִ��� Ȯ���ϴ� ����

	//GameScene
	int currentFloor = 0; //������ ���� �ÿ� �ִ� ��
	float gameS_posX = 0, gameS_posY = 0; //������ ���� �ÿ� �ִ� ��ġ

	DataField& operator=(DataField &ref) { //���� ������ ������
		currentScene = ref.currentScene;

		isMale = ref.isMale;
		isSettingGender = ref.isSettingGender;

		strcpy(name, ref.name);
		isSettingName = ref.isSettingName;

		currentFloor = ref.currentFloor;
		gameS_posX = ref.gameS_posX;
		gameS_posY = ref.gameS_posY;

		return *this;
	}
};
class DataManager
{
public:
	DataManager();
	~DataManager();
	DataField data;
	string s_name;
	void Save();
	void Load();
	void ChangeNameToString();
	void Reset();
	static DataManager* instance();
};