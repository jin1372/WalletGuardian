#pragma once
#include "Factory.h"
#include <unordered_map>
#include <string>

class FinancialManager final : public Factory
{
protected:
	enum Menu {
		MENU_SELECT,		// �޴� ����â
		MENU_ADD,			// ���� �߰�
		MENU_REMOVE,		// ���� ����
		MENU_LIST,          // ���� ����Ʈ ���
		MENU_REC,			// ��õ ���ⷮ ���
		MENU_END,           // �ڷ� ����
	};

public:
	virtual void Render() const final;
	virtual void Update( bool* isRun ) final;

private:
	// ���� ���� �������̽�
	void addExpense();          // ������ �߰��ϴ� �Լ�
	void removeExpense();       // ������ �����ϴ� �Լ�
	void expenseList();         // ���� ����
	void recommendedExpense();  // ������ ��õ ���ⷮ�� ǥ���ϴ� ����

private:
	Menu mCurrSequence = MENU_SELECT;
};