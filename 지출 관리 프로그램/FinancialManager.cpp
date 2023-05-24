#include "FinancialManager.h"
#include "Manager.h"

void FinancialManager::Render() const
{
	system( "cls" );
	cout << "[ ## ���� �Ŵ��� ## ]" << endl;
	switch ( mCurrSequence )
	{
		case MENU_SELECT:
			cout << "������ �޴��� �����Ͻʽÿ�." << endl;
			cout << endl;
			cout << "1. ���� �߰�" << endl;
			cout << "2. ���� ����" << endl;
			cout << "3. ���� ����" << endl;
			cout << "4. ��õ ���ⷮ ���" << endl;
			cout << "5. �ڷ� ����" << endl;
			cout << "�Է� = ";
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
			cout << "�߸��� �Է��Դϴ�. �ʱ�ȭ������ ���ư��ϴ�." << endl;
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
	cout << "[ ## ���� �߰� ## ]" << endl;
	cout << "��¥�� �Է��Ͻʽÿ�." << endl;
	cout << "�Է� = "; 
	getline( cin, date );

	cout << "���� �ݾ��� �Է��Ͻʽÿ�." << endl;
	cout << "�Է� = "; cin >> expenseAmount; 
	
	if ( expenseAmount <= manager.mAsset )
	{
		manager.mAsset = manager.mAsset - expenseAmount;
		manager.mRecords.insert( unordered_map<string, int>::value_type( date, expenseAmount ) );
	} 
	else
	{
		cout << "## ���� �߰� ���� ##" << endl;
		cout << "������ �ڻ꺸�� ū �ݾ��� �Է��߽��ϴ�." << endl;
	}

}

void FinancialManager::removeExpense()
{
	auto& manager = Manager::getInstance();
	std::string date;
	cin.ignore();
	system( "cls" );
	cout << "[ ## ���� ���� ## ]" << endl;
	cout << "��¥�� �Է��Ͻʽÿ�." << endl;
	cout << "�Է� = ";
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
	cout << "[ ## ���� ���� ## ]" << endl;
	if ( manager.mRecords.size() )
	{
		for ( const auto& o : manager.mRecords )
		{
			cout << o.first << " : " << o.second << "��" << endl;
		}
	} 
	else
	{
		cout << "���� ������ �����ϴ�." << endl;
	}
	system( "pause" );
}

void FinancialManager::recommendedExpense()
{

}


