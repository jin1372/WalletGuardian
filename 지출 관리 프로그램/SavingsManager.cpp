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

void SavingsManager::addSavings() noexcept
{
	auto& manager = Manager::getInstance();
	std::string date;
	int savingAmount;

	cin.ignore();
	system( "cls" );
	cout << "[ ## 저금 추가 ## ]" << endl;
	cout << "날짜를 입력하십시오." << endl;
	cout << "입력 = ";
	getline( cin, date );

	cout << "저금할 금액을 입력하십시오." << endl;
	cout << "입력 = "; cin >> savingAmount;

	if ( savingAmount <= manager.mAsset - manager.mTotalSavings )
	{
		manager.mAsset = manager.mAsset - savingAmount;
		manager.mTotalSavings = manager.mTotalSavings + savingAmount;
		manager.mRecords.insert( unordered_map<string, int>::value_type( date, savingAmount ) );
		cout << date << ", " << savingAmount << "원을 저금했습니다." << endl;
	}
	else
	{
		cout << "## 저금 추가 실패 ##" << endl;
		cout << "보유한 자산보다 큰 금액을 입력했습니다." << endl;
	}
	system( "pause" );
}

void SavingsManager::removeSavings() noexcept
{
	auto& manager = Manager::getInstance();
	std::string date;
	cin.ignore();
	system( "cls" );
	cout << "[ ## 저금 제거 ## ]" << endl;
	cout << "날짜를 입력하십시오." << endl;
	cout << "입력 = ";
	getline( cin, date );

	if ( manager.mSavingsList.find( date ) != manager.mSavingsList.end() )
	{
		int savingAmount = 0;
		savingAmount = manager.mSavingsList[date];

		manager.mAsset += savingAmount;
		manager.mTotalSavings -= savingAmount;

		manager.mSavingsList.erase( date );
		cout << date << ", " << savingAmount << "원을 저금 내역에서 제거했습니다." << endl;
	}
	else
	{
		cout << "해당 날짜에 저금한 내역이 없습니다." << endl;
	}
	system( "pause" );
}

void SavingsManager::showSavings() const noexcept
{
	auto& manager = Manager::getInstance();
	system( "cls" );
	cout << "[ ## 저금 내역 ## ]" << endl;
	cout << "# 총 저금액: " << manager.mTotalSavings << "원" << endl;
	if ( manager.mSavingsList.size() )
	{
		for ( const auto& o : manager.mSavingsList )
		{
			cout << o.first << " : " << o.second << "원" << endl;
		}
	}
	else
	{
		cout << "저금 내역이 없습니다." << endl;
	}
	system( "pause" );
}

