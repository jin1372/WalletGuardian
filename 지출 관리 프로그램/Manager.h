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


class Factory;
class ExpenseManager;
class FinancialManager;
class SavingsManager;

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
		END       = 4,
	};
public:
	void Render() const;
	void Update( bool* isRun );

	static Manager& getInstance();

private:

	Factory* root = nullptr;
	
	// 총 자산
	int mAsset = 0;		
	
	// 지출 관리
	std::unordered_map<std::string, int> mRecords;

	Interface mSequence = FIRST;

private:
	static std::unique_ptr<Manager> instance;
};