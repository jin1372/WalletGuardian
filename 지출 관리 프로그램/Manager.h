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
		END       = 4,
	};
public:
	void Render() const;
	void Update( bool* isRun );

	static Manager& getInstance();

private:
	Factory* root = nullptr;
	
	// �� �ڻ�
	int mAsset = 0;		
	// ���� ����
	std::unordered_map<std::string, int> mRecords;
	// ���� ����
	std::unordered_map<std::string, int> mSavingsList;

	Interface mSequence = FIRST;

private:
	static std::unique_ptr<Manager> instance;
};