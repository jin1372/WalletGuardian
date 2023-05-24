#include "SavingsManager.h"
#include "Manager.h"

void SavingsManager::Render() const
{
	system( "cls" );
	cout << "[ ## 지출 매니저 ## ]" << endl;
	switch ( mCurrSequence )
	{
		case MENU_SELECT:
			cout << "조작할 메뉴를 선택하십시오." << endl;
			cout << endl;
			cout << "1. 저금 추가" << endl;
			cout << "2. 저금 제거" << endl;
			cout << "3. 저금 내역" << endl;
			cout << "4. 뒤로 가기" << endl;
			cout << "입력 = ";
			break;
	}
}
void SavingsManager::Update( bool* isRun )
{
	int select;
	switch ( mCurrSequence )
	{
		case MENU_SELECT:
			cin >> select;
			mCurrSequence = static_cast<Menu>( select );
			break;
		case MENU_ADD:
			addSavings();
			mCurrSequence = MENU_SELECT;
			break;
		case MENU_REMOVE:
			removeSavings();
			mCurrSequence = MENU_SELECT;
			break;
		case MENU_LIST:
			showSavings();
			mCurrSequence = MENU_SELECT;
			break;
		case MENU_END:
			*isRun = false;
			break;
		default:
			cout << "잘못된 입력입니다. 초기화면으로 돌아갑니다." << endl;
			*isRun = false;

	}
}

void SavingsManager::showSavings()
{

}

void SavingsManager::addSavings()
{

}

void SavingsManager::removeSavings()
{

}
