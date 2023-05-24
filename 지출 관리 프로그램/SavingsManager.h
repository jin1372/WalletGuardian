#pragma once
#include "Factory.h"

class SavingsManager final : public Factory
{
public:
	virtual void Render() const final;
	virtual void Update( bool* isRun ) final;

private:
	//// 저금 관련 인터페이스
	void savingsList();   // 저금 목록을 표시하는 변수
	void showSavings();   // 저금 내역을 표시하는 함수
	void addSavings();    // 저금을 추가하는 함수
	void removeSavings(); // 저금을 제거하는 함수
};

