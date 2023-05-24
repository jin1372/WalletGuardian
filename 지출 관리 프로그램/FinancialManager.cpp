#include "FinancialManager.h"
#include "Manager.h"

void FinancialManager::Render() const
{
	system( "cls" );
	cout << "[ ## 지출 매니저 ## ]" << endl;
	switch ( mCurrSequence )
	{
		case MENU_SELECT:
			cout << "조작할 메뉴를 선택하십시오." << endl;
			cout << endl;
			cout << "1. 지출 추가" << endl;
			cout << "2. 지출 제거" << endl;
			cout << "3. 지출 내역" << endl;
			cout << "4. 추천 지출량 등록" << endl;
			cout << "5. 뒤로 가기" << endl;
			cout << "입력 = ";
			break;
	}
}

void FinancialManager::Update( bool* isRun )
{
	int select;
	switch ( mCurrSequence )
	{
		case MENU_SELECT:
			cin >> select;
			mCurrSequence = static_cast<Menu>( select );
			break;
		case MENU_ADD:
			addExpense();
			mCurrSequence = MENU_SELECT;
			break;
		case MENU_REMOVE:
			removeExpense();
			mCurrSequence = MENU_SELECT;
			break;
		case MENU_LIST:
			expenseList();
			mCurrSequence = MENU_SELECT;
			break;
		case MENU_REC:
			recommendedExpense();
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

void FinancialManager::addExpense()
{
	auto& manager = Manager::getInstance();
	std::string date;
	int expenseAmount;

	cin.ignore();
	system( "cls" );
	cout << "[ ## 지출 추가 ## ]" << endl;
	cout << "날짜를 입력하십시오." << endl;
	cout << "입력 = "; 
	getline( cin, date );

	cout << "지출 금액을 입력하십시오." << endl;
	cout << "입력 = "; cin >> expenseAmount; 
	
	if ( expenseAmount <= manager.mAsset )
	{
		manager.mAsset = manager.mAsset - expenseAmount;
		manager.mRecords.insert( unordered_map<string, int>::value_type( date, expenseAmount ) );
	} 
	else
	{
		cout << "## 지출 추가 실패 ##" << endl;
		cout << "보유한 자산보다 큰 금액을 입력했습니다." << endl;
	}

}

void FinancialManager::removeExpense()
{
	auto& manager = Manager::getInstance();
	std::string date;
	cin.ignore();
	system( "cls" );
	cout << "[ ## 지출 제거 ## ]" << endl;
	cout << "날짜를 입력하십시오." << endl;
	cout << "입력 = ";
	getline( cin, date );

	int amount = 0;
	amount = manager.mRecords[date];

	manager.mAsset += amount;

	manager.mRecords.erase( date );
}

void FinancialManager::expenseList()
{
	auto& manager = Manager::getInstance();
	system( "cls" );
	cout << "[ ## 지출 내역 ## ]" << endl;
	if ( manager.mRecords.size() )
	{
		for ( const auto& o : manager.mRecords )
		{
			cout << o.first << " : " << o.second << "원" << endl;
		}
	} 
	else
	{
		cout << "지출 내역이 없습니다." << endl;
	}
	system( "pause" );
}

void FinancialManager::recommendedExpense()
{

}


