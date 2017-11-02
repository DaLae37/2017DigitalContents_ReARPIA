#pragma once
#include <string>
#include <fstream>
#define DataMgr DataManager::instance()
using namespace std;
class DataField {
public :
	bool isMale = false; //true�̸� ���� false�̸� ����
	bool isSettingGender = false; //������ ���� �Ǿ��ִ��� Ȯ���ϴ� ����

	string name = ""; //�̸�
	bool isSettingName = false; //�̸��� ������ �ִ��� Ȯ���ϴ� ����

	DataField& operator=(DataField &ref) { //���� ������ ������
		isMale = ref.isMale;
		isSettingGender = ref.isSettingGender;

		name = ref.name;
		isSettingName = ref.isSettingName;
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