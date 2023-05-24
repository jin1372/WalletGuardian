#pragma once
#include "Factory.h"

class SavingsManager final : public Factory
{
protected:
	enum Menu {
		MENU_SELECT,		// �޴� ����â
		MENU_ADD,			// ���� �߰�
		MENU_REMOVE,		// ���� ����
		MENU_LIST,          // ���� ����Ʈ ���
		MENU_END,           // �ڷ� ����
	};

public:
	virtual void Render() const final;
	virtual void Update( bool* isRun ) final;

private:
	//// ���� ���� �������̽�
	void addSavings() noexcept;          // ������ �߰��ϴ� �Լ�
	void removeSavings() noexcept;       // ������ �����ϴ� �Լ�
	void showSavings() const noexcept;   // ���� ������ ǥ���ϴ� �Լ�

private:
	Menu mCurrSequence = MENU_SELECT;
};

