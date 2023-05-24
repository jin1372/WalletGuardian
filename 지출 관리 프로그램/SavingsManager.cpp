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

void SavingsManager::showSavings()
{

}

void SavingsManager::addSavings()
{

}

void SavingsManager::removeSavings()
{

}
