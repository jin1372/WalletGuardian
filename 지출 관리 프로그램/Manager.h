#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Factory.h"
#include "ExpenseManager.h"
#include "FinancialManager.h"
#include "SavingsManager.h"

namespace {
using namespace std;
};

class Manager
{
	friend class ExpenseManager;
	friend class FinancialManager;
	friend class SavingsManager;

public:
	enum Interface
	{
		FIRST     = 0,
		EXPENSE   = 1,
		FINANCIAL = 2,
		SAVINGS   = 3,
		SAVE      = 4,
		END       = 5,
	};
public:
	void Render() const;
	void Update( bool* isRun );

	static Manager& getInstance();

public:
	bool saveData( const std::string& fileName );
	bool loadData( const std::string& fileName );

private:
	Factory* root = nullptr;
	
	// 총 자산
	int mAsset = 0;		
	// 총 저금액
	int mTotalSavings = 0;
	// 총 지출액
	int mTotalExpense = 0;
	// 추천 지출량
	int mSugOutlay = 0;

	// 지출 관리
	std::unordered_map<std::string, int> mRecords;
	// 저금 관리
	std::unordered_map<std::string, int> mSavingsList;

	Interface mSequence = FIRST;

private:
	static std::unique_ptr<Manager> instance;
};