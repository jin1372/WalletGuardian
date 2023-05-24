#pragma once
#include "Factory.h"
#include <unordered_map>
#include <string>

class FinancialManager final : public Factory
{
protected:
	enum Menu {
		MENU_SELECT,		// 메뉴 선택창
		MENU_ADD,			// 지출 추가
		MENU_REMOVE,		// 지출 제거
		MENU_LIST,          // 지출 리스트 출력
		MENU_REC,			// 추천 지출량 등록
		MENU_END,           // 뒤로 가기
	};

public:
	virtual void Render() const final;
	virtual void Update( bool* isRun ) final;

private:
	// 지출 관련 인터페이스
	void addExpense() noexcept;          // 지출을 추가하는 함수
	void removeExpense() noexcept;       // 지출을 제거하는 함수
	void expenseList() const noexcept;   // 지출 내역
	void recommendedExpense() noexcept;  // 적절한 추천 지출량을 표시하는 변수

private:
	Menu mCurrSequence = MENU_SELECT;
};