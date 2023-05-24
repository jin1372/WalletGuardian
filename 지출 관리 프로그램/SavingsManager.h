#pragma once
#include "Factory.h"

class SavingsManager final : public Factory
{
public:
	virtual void Render() const final;
	virtual void Update( bool* isRun ) final;

private:
	//// ���� ���� �������̽�
	void savingsList();   // ���� ����� ǥ���ϴ� ����
	void showSavings();   // ���� ������ ǥ���ϴ� �Լ�
	void addSavings();    // ������ �߰��ϴ� �Լ�
	void removeSavings(); // ������ �����ϴ� �Լ�
};

