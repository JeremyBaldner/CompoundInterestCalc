#ifndef PROJECT2_AIRGEAD_BANKING_H
#define PROJECT2_AIRGEAD_BANKING_H
#include <iostream>
using namespace std;

class AirgeadBanking {
private:
	AirgeadBanking* nextNodePtr;
	double m_intAmount = 0, m_monthlyDeposit = 0, m_annualInterest = 0, m_yearInterest = 0, m_interest = 0;
	double m_intAmountWO = 0, m_yearInterestWO = 0, m_interestWO = 0;
	int m_numYears = 0;
	unsigned int i = 0;
	unsigned int f = 0;

public:
	AirgeadBanking();
	void initialization();
	void initialPrint();
	void calculation();
	void setUpPrint();
	void finalPrint();
};
#endif