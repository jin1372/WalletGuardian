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

	// 입력 내용을 한줄 씩 입력, 자동 개행
	void add( const std::string& text );
	void add( const int& text );

	/* 
	 - 한 줄씩 파일의 내용을 불러오는 함수
	* 가져오길 원하는 줄의 인덱스 입력
	* 인덱스 범위 초과 시 string 타입의 -1을 반환
	*/
	std::string read( size_t indices ) const;

	bool saveFile( const std::string& fileName );
	bool loadFile( const std::string& fileName );
	
private:
	static std::unique_ptr<FileManager> instance;

	std::vector< std::string > mData;
};

