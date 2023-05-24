#include "SavingsManager.h"
#include "Manager.h"

void SavingsManager::Render() const
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
			cout << "4. �ڷ� ����" << endl;
			cout << "�Է� = ";
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
			cout << "�߸��� �Է��Դϴ�. �ʱ�ȭ������ ���ư��ϴ�." << endl;
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
	cout << "[ ## ���� �߰� ## ]" << endl;
	cout << "��¥�� �Է��Ͻʽÿ�." << endl;
	cout << "�Է� = ";
	getline( cin, date );

	cout << "������ �ݾ��� �Է��Ͻʽÿ�." << endl;
	cout << "�Է� = "; cin >> savingAmount;

	if ( savingAmount <= manager.mAsset - manager.mTotalSavings )
	{
		manager.mAsset = manager.mAsset - savingAmount;
		manager.mTotalSavings = manager.mTotalSavings + savingAmount;
		manager.mRecords.insert( unordered_map<string, int>::value_type( date, savingAmount ) );
		cout << date << ", " << savingAmount << "���� �����߽��ϴ�." << endl;
	}
	else
	{
		cout << "## ���� �߰� ���� ##" << endl;
		cout << "������ �ڻ꺸�� ū �ݾ��� �Է��߽��ϴ�." << endl;
	}
	system( "pause" );
}

void SavingsManager::removeSavings() noexcept
{
	auto& manager = Manager::getInstance();
	std::string date;
	cin.ignore();
	system( "cls" );
	cout << "[ ## ���� ���� ## ]" << endl;
	cout << "��¥�� �Է��Ͻʽÿ�." << endl;
	cout << "�Է� = ";
	getline( cin, date );

	if ( manager.mSavingsList.find( date ) != manager.mSavingsList.end() )
	{
		int savingAmount = 0;
		savingAmount = manager.mSavingsList[date];

		manager.mAsset += savingAmount;
		manager.mTotalSavings -= savingAmount;

		manager.mSavingsList.erase( date );
		cout << date << ", " << savingAmount << "���� ���� �������� �����߽��ϴ�." << endl;
	}
	else
	{
		cout << "�ش� ��¥�� ������ ������ �����ϴ�." << endl;
	}
	system( "pause" );
}

void SavingsManager::showSavings() const noexcept
{
	auto& manager = Manager::getInstance();
	system( "cls" );
	cout << "[ ## ���� ���� ## ]" << endl;
	cout << "# �� ���ݾ�: " << manager.mTotalSavings << "��" << endl;
	if ( manager.mSavingsList.size() )
	{
		for ( const auto& o : manager.mSavingsList )
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

