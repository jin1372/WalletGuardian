#pragma once
#include "Factory.h"

class ExpenseManager final : public Factory
{
protected:
	enum Menu {
		MENU_SELECT,		// �޴� ����â
		MENU_INPUT,			// �ڻ� ���
		MENU_CURRENT,		// ���� �ڻ� ����
		MENU_INIT,			// �ڻ� �ʱ�ȭ
		MENU_END,           // �ڷ� ����
	};

public:
	virtual void Render() const final;
	virtual void Update( bool* isRun ) final;

private:
	// �ڻ� ���� �������̽�
	void inputAssets( int amount ) noexcept;
	void currentAssets() const noexcept;
	void initAssets() noexcept;
	
private:
	Menu mCurrSequence = MENU_SELECT;
};