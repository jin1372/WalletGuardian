#pragma once
#include "Factory.h"

class SavingsManager final : public Factory
{
protected:
	enum Menu {
		MENU_SELECT,		// 메뉴 선택창
		MENU_ADD,			// 지출 추가
		MENU_REMOVE,		// 지출 제거
		MENU_LIST,          // 지출 리스트 출력
		MENU_END,           // 뒤로 가기
	};

public:
	virtual void Render() const final;
	virtual void Update( bool* isRun ) final;

private:
	//// 저금 관련 인터페이스
	void addSavings() noexcept;          // 저금을 추가하는 함수
	void removeSavings() noexcept;       // 저금을 제거하는 함수
	void showSavings() const noexcept;   // 저금 내역을 표시하는 함수

private:
	Menu mCurrSequence = MENU_SELECT;
};

