#include "FileManager.h"
#include <fstream>

using namespace std;

unique_ptr<FileManager> FileManager::instance = nullptr;

FileManager& FileManager::getInstance()
{
	if ( instance == nullptr )
	{
		instance = make_unique<FileManager>();
	}
	return *instance.get();
}

void FileManager::clear()
{
	mData.clear();
	vector<string>().swap( mData );
}

void FileManager::add( const string& text )
{
	mData.push_back( text );
}

void FileManager::add( const int& text )
{
	mData.push_back( to_string( text ) );
}

string FileManager::read( size_t indices ) const
{
	if ( indices < mData.size() )
		return { mData[indices] };
	else
		return string{ "-1" };
}

bool FileManager::saveFile( const string& fileName )
{
	ofstream file;

	file.open( fileName );
	bool isOpen = file.is_open();

	if ( isOpen ) {
		for ( const auto& o : mData )
		{
			file << o;
			file << '\n';
		}
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}

bool FileManager::loadFile( const string& fileName )
{
	ifstream file;
	string readData;

	file.open( fileName );
	bool isOpen = file.is_open();

	if ( isOpen )
	{
		while ( getline( file, readData ) )
		{
			mData.push_back( readData );
		}
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}

}

