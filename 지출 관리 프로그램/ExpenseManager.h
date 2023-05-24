#pragma once
#include "Factory.h"

class ExpenseManager final : public Factory
{
protected:
	enum Menu {
		MENU_SELECT,		// 메뉴 선택창
		MENU_INPUT,			// 자산 등록
		MENU_CURRENT,		// 현재 자산 보기
		MENU_INIT,			// 자산 초기화
		MENU_END,           // 뒤로 가기
	};

public:
	virtual void Render() const final;
	virtual void Update( bool* isRun ) final;

private:
	// 자산 관련 인터페이스
	void inputAssets( int amount ) noexcept;
	void currentAssets() const noexcept;
	void initAssets() noexcept;
	
private:
	Menu mCurrSequence = MENU_SELECT;
};