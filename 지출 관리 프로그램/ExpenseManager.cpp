#include "ExpenseManager.h"
#include "Manager.h"
#include <iostream>

using namespace std;

void ExpenseManager::Render() const
{
	system( "cls" );
	cout << "[ ## �ڻ� �Ŵ��� ## ]" << endl;
	switch ( mCurrSequence )
	{
		case MENU_SELECT:
			cout << "������ �޴��� �����Ͻʽÿ�." << endl;
			cout << endl;
			cout << "1. �ڻ� ���" << endl;
			cout << "2. ���� �ڻ� ����" << endl;
			cout << "3. �ڻ� �ʱ�ȭ" << endl;
			cout << "4. �ڷ� ����" << endl;
			break;
		case MENU_INPUT:
			cout << "�ڻ��� �Է��Ͻʽÿ�." << endl;
			cout << "�Է� = ";
			break;
		case MENU_CURRENT:
			cout << "���� ������ �ڻ�" << endl;
			cout << "= ";
			break;
		case MENU_INIT:
			cout << "�ڻ� ������ �ʱ�ȭ �߽��ϴ�." << endl;
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
			cout << currentAssets() << endl;
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
			cout << "�߸��� �Է��Դϴ�. �ʱ�ȭ������ ���ư��ϴ�." << endl;
			*isRun = false;
	}
	cin.clear();
}

void ExpenseManager::inputAssets( int amount ) noexcept
{	
	auto& m = Manager::getInstance();
	m.mAsset = amount;
}
int ExpenseManager::currentAssets() const noexcept
{
	auto& m = Manager::getInstance();
	return m.mAsset;
}
void ExpenseManager::initAssets() noexcept
{
	auto& m = Manager::getInstance();
	m.mAsset= 0;
}