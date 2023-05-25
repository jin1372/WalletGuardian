#include "Manager.h"
#include "FileManager.h"

std::unique_ptr<Manager> Manager::instance = nullptr;

void Manager::Render() const
{
	system( "cls" );
	switch ( mSequence )
	{
		case FIRST:
			cout << "[ ## 지출 관리 프로그램 ## ]" << endl;
			cout << "메뉴를 선택하세요" << endl;
			cout << endl;

			cout << "1. 자산 관리 매니저" << endl;
			cout << "2. 지출 관리 매니저" << endl;
			cout << "3. 저금 관리 매니저" << endl;
			cout << "4. 프로그램 종료" << endl;
			cout << "입력 = ";
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

	// 각 정보들을 파일에 입력
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

	// 파일을 정상적으로 불러왔을 경우
	if ( m.loadFile( fileName ) )
	{
		mAsset = stoi( m.read( 0 ) );
		mTotalExpense = stoi( m.read( 1 ) );
		mTotalSavings = stoi( m.read( 2 ) );
		m.clear();
		return true;
	}

	// 파일 읽기에 실패했을 경우
	else
	{
		return false;
	}

}
