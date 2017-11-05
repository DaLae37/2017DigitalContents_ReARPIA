#pragma once
#include <string>
#include <fstream>
#define DataMgr DataManager::instance()
using namespace std;
class DataField {
public :
	//Global
	int currentScene; //���� ���� �ε��� 0 : gameScene

	//GenderSetting
	bool isMale = false; //true�̸� ���� false�̸� ����
	bool isSettingGender = false; //������ ���� �Ǿ��ִ��� Ȯ���ϴ� ����

	//NameSetting
	string name = ""; //�̸�
	bool isSettingName = false; //�̸��� ������ �ִ��� Ȯ���ϴ� ����

	//GameScene
	int currentFloor; //������ ���� �ÿ� �ִ� ��
	float gameS_posX, gameS_posY; //������ ���� �ÿ� �ִ� ��ġ

	DataField& operator=(DataField &ref) { //���� ������ ������
		currentScene = ref.currentScene;

		isMale = ref.isMale;
		isSettingGender = ref.isSettingGender;

		name = ref.name;
		isSettingName = ref.isSettingName;

		currentFloor = ref.currentFloor;
		gameS_posX = ref.gameS_posX;
		gameS_posY = ref.gameS_posY;
		return *this;
	}
};
class DataManager
{
private :
	DataManager();
public:

	~DataManager();
	DataField *data = new DataField;
	void Save();
	void Load();
	void Reset();
	static DataManager* instance();
};