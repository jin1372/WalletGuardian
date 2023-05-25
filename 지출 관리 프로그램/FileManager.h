#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class FileManager
{
public:
	static FileManager& getInstance();

	void clear();

	// �Է� ������ ���� �� �Է�, �ڵ� ����
	void add( const std::string& text );
	void add( const int& text );

	/* 
	 - �� �پ� ������ ������ �ҷ����� �Լ�
	* �������� ���ϴ� ���� �ε��� �Է�
	* �ε��� ���� �ʰ� �� string Ÿ���� -1�� ��ȯ
	*/
	std::string read( size_t indices ) const;

	bool saveFile( const std::string& fileName );
	bool loadFile( const std::string& fileName );
	
private:
	static std::unique_ptr<FileManager> instance;

	std::vector< std::string > mData;
};

