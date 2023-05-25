#include "Manager.h"
#include "FileManager.h"

std::unique_ptr<Manager> Manager::instance = nullptr;

void Manager::Render() const
{
	system( "cls" );
	switch ( mSequence )
	{
		case FIRST:
			cout << "[ ## ���� ���� ���α׷� ## ]" << endl;
			cout << "�޴��� �����ϼ���" << endl;
			cout << endl;

			cout << "1. �ڻ� ���� �Ŵ���" << endl;
			cout << "2. ���� ���� �Ŵ���" << endl;
			cout << "3. ���� ���� �Ŵ���" << endl;
			cout << "4. ���α׷� ����" << endl;
			cout << "�Է� = ";
			break;

		default:
			if( root )
			    root->Render();
	}
}

void Manager::Update( bool* isRun )
{
	int select = 0;
	bool isOn = true;
	switch ( mSequence )
	{
		case FIRST:
			cin >> select;
			cin.clear();
			mSequence = static_cast<Interface>( select );
			break;
		case EXPENSE:
			if ( root == nullptr )
			{
				root = new ExpenseManager;
				break;
			}
			root->Update( &isOn );
			break;
		case FINANCIAL:
			if ( root == nullptr )
			{
				root = new FinancialManager;
				break;
			}
			root->Update( &isOn );
			break;
		case SAVINGS:
			if ( root == nullptr )
			{
				root = new SavingsManager;	
				break;
			}
			root->Update( &isOn );
			break;
		case END:
			if ( root )
				delete root;
			*isRun = false;
			break;
	}
	if ( isOn == false )
	{
		delete root;
		root = nullptr;
		mSequence = FIRST;
		isOn = true;
	}
}

Manager& Manager::getInstance()
{
	if ( instance.get() == nullptr )
	{
		instance = std::make_unique<Manager>();
	}
	return *instance;
}

bool Manager::saveData( const std::string& fileName )
{
	auto& m = FileManager::getInstance();

	// �� �������� ���Ͽ� �Է�
	m.add( mAsset );
	m.add( mTotalExpense );
	m.add( mTotalSavings );

	m.saveFile( fileName );
	m.clear();

	return true;
}

bool Manager::loadData( const std::string& fileName )
{
	auto& m = FileManager::getInstance();

	// ������ ���������� �ҷ����� ���
	if ( m.loadFile( fileName ) )
	{
		mAsset = stoi( m.read( 0 ) );
		mTotalExpense = stoi( m.read( 1 ) );
		mTotalSavings = stoi( m.read( 2 ) );
		m.clear();
		return true;
	}

	// ���� �б⿡ �������� ���
	else
	{
		return false;
	}

}
