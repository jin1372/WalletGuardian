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
	m.add( "-main" );
	m.add( mAsset );
	m.add( mTotalExpense );
	m.add( mTotalSavings );

	// ���� ���� ���Ͽ� �Է�
	m.add( "-records" );
	for ( const auto& o : mRecords )
	{
		m.add( o.first );
		m.add( o.second );
	}

	// ���� ���� ���Ͽ� �Է�
	m.add( "-savings" );
	for ( const auto& o : mSavingsList )
	{
		m.add( o.first );
		m.add( o.second );
	}

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
		size_t size = m.size();

		// ���� �б� ����
		int j = 0;
		for ( int i = 0; i < size; ++i )
		{
			int turn = 0;
			string text = m.read( i );
			if ( text == "-main" )
			{
				mAsset = stoi( m.read( i + 1 ) );
				mTotalExpense = stoi( m.read( i + 2 ) );
				mTotalSavings = stoi( m.read( i + 3 ) );
				i += 3;
			}

			if ( text == "-records" )
			{
				for ( j = 1; j < size; ++j )
				{
					text = m.read( i + j );
					if ( text == "-savings" )
					{
						text.clear();
						i += (j - 1);
						break;
					}
					int expenseAmount = stoi( m.read( i + j + 1 ) );
					mRecords.insert( unordered_map<string, int>::value_type( text, expenseAmount ) );
					j += 1;
				}
			}

			if ( text == "-savings" )
			{
				for ( j = 1; j < size; ++j )
				{
					text = m.read( i + j );
					if ( text == "-end" )
					{
						text.clear();
						i += ( j - 1 );
						break;
					}
					int savingAmount = stoi( m.read( i + j + 1 ) );
					mSavingsList.insert( unordered_map<string, int>::value_type( text, savingAmount ) );
					j += 1;
				}
			}
		}

		m.clear();
		return true;
	}

	// ���� �б⿡ �������� ���
	else
	{
		return false;
	}

}
