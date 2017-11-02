#include "stdafx.h"
#include "tutorialScene.h"

tutorialScene::tutorialScene()
{
	GenderPanel = new SettingGenderPanel();
	NamePanel = new SettingNamePanel();
}


tutorialScene::~tutorialScene()
{

}

void tutorialScene::Update(float eTime) {
	ZeroIScene::Update(eTime);
	if (!DataMgr->data->isSettingGender) {
		GenderPanel->Update(eTime);
	}
	if (DataMgr->data->isSettingGender && !DataMgr->data->isSettingName) {
		NamePanel->Update(eTime);
	}
}

void tutorialScene::Render() {
	ZeroIScene::Render();
	if (!DataMgr->data->isSettingGender) {
		GenderPanel->Render();
	}
	if (DataMgr->data->isSettingGender && !DataMgr->data->isSettingName) {
		NamePanel->Render();
	}
}

SettingGenderPanel::SettingGenderPanel() {
	male = new ZeroSprite("Resource/Player/male.png");
	female = new ZeroSprite("Resource/Player/female.png");
	female->SetPosX(500);
	isPopUp = false;
	isMale = false;
}

SettingGenderPanel::~SettingGenderPanel() {

}

void SettingGenderPanel::Update(float eTime) {
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP && !isPopUp) {
		if (male->IsOverlapped(ZeroInputMgr->GetClientPoint())) {
			isPopUp = true;
			isMale = true;
		}
		else if (female->IsOverlapped(ZeroInputMgr->GetClientPoint())) {
			isPopUp = true;
			isMale = false;
		}
	}
	if (isPopUp) { //�˾��� �������� ��
		PoPUPMgr->Update(eTime);
		if (PoPUPMgr->isSelected) {
			if (PoPUPMgr->isYes) {
				DataMgr->data->isMale = isMale;
				DataMgr->data->isSettingGender = true;
				DataMgr->Save();
				//Yes�� ���õǾ����� �����͸� �����Ű�� �ʱ�ȭ
			}
			if (!PoPUPMgr->isYes) {
				isPopUp = false;
				//No�� ���õǾ����� â�� �ݰ� �ʱ�ȭ
			}
			PoPUPMgr->isSelected = false;
			PoPUPMgr->isYes = false;
		}
	}
}

void SettingGenderPanel::Render() {
	ZeroIScene::Render();
	male->Render();
	female->Render();
	if (isPopUp) {
		PoPUPMgr->Render();
	}
}

SettingNamePanel::SettingNamePanel() {

}

SettingNamePanel::~SettingNamePanel() {

}

void SettingNamePanel::Update(float eTime) {
	ZeroIScene::Update(eTime);
	cout << "rhr";
}

void SettingNamePanel::Render() {
	ZeroIScene::Render();
}