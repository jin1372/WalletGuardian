#include "ExpenseManager.h"
#include "Manager.h"
#include <iostream>

using namespace std;

void ExpenseManager::Render() const
{
	system( "cls" );
	cout << "[ ## 자산 매니저 ## ]" << endl;
	switch ( mCurrSequence )
	{
		case MENU_SELECT:
			cout << "조작할 메뉴를 선택하십시오." << endl;
			cout << endl;
			cout << "1. 자산 등록" << endl;
			cout << "2. 현재 자산 보기" << endl;
			cout << "3. 자산 초기화" << endl;
			cout << "4. 뒤로 가기" << endl;
			cout << "입력 = ";
			break;
		case MENU_INPUT:
			cout << "자산을 입력하십시오." << endl;
			cout << "입력 = ";
			break;
		case MENU_CURRENT:
			cout << "현재 보유한 자산" << endl;
			cout << "= ";
			break;
		case MENU_INIT:
			cout << "자산 정보를 초기화 했습니다." << endl;
			system( "pause" );
			break;
	}
}

void ExpenseManager::Update( bool* isRun )
{
	int select = 0;
	switch ( mCurrSequence )
	{
		case MENU_SELECT:
			cin >> select;
			mCurrSequence = static_cast<Menu>( select );
			break;
		case MENU_INPUT:
			cin >> select;
			inputAssets( select );
			mCurrSequence = MENU_SELECT;
			break;
		case MENU_CURRENT: 
			currentAssets();
			mCurrSequence = MENU_SELECT;
			system( "pause" );
			break;
		case MENU_INIT:
			initAssets();
			mCurrSequence = MENU_SELECT;
			system( "pause" );
			break;
		case MENU_END:
			*isRun = false;
			break;
		default:
			cout << "잘못된 입력입니다. 초기화면으로 돌아갑니다." << endl;
			*isRun = false;
			system( "pause" );
	}
	cin.clear();
}

void ExpenseManager::inputAssets( int amount ) noexcept
{	
	auto& m = Manager::getInstance();
	m.mAsset = amount;
}
void ExpenseManager::currentAssets() const noexcept
{
	auto& m = Manager::getInstance();
	system( "cls" );
	cout << "[ ## 자산 매니저 ## ]" << endl;

	cout << "# 총 자산: "   << m.mAsset        << "원" << endl;
	cout << "# 총 지출액: " << m.mTotalExpense << "원" << endl;
	cout << "# 총 저금액: " << m.mTotalSavings << "원" << endl;
}
void ExpenseManager::initAssets() noexcept
{
	auto& m = Manager::getInstance();
	m.mAsset= 0;
}