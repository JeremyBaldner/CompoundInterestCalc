#include <iostream>
#include <stdlib.h> // clear screen
#include <conio.h> // Detect user input
#include <iomanip>  //set fill & width
#include <limits> // checking input
#include "Project2AirgeadBanking.h"
using namespace std;

// construct
AirgeadBanking::AirgeadBanking() {
}
// initial questions
void AirgeadBanking::initialization() {
	cout << "What is your initial investment amount?" << endl;
	cin >> m_intAmount;
	while (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Enter a number...\n";
		cin >> m_intAmount;
	}
	system("CLS");
	cout << "How much will you deposit monthly?" << endl;
	cin >> m_monthlyDeposit;
	while (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Enter a number...\n";
		cin >> m_monthlyDeposit;
	}
	system("CLS");
	cout << "What is the expected annual interest rate?" << endl;
	cin >> m_annualInterest;
	while (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Enter a number...\n";
		cin >> m_annualInterest;
	}
	system("CLS");
	cout << "How many years will you invest?" << endl;
	cin >> m_numYears;
	while (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Enter a number...\n";
		cin >> m_numYears;
	}
	system("CLS"); // clear screen
	initialPrint(); //show answers to questions
	cout << "Press any key to continue...\n";
	while (1) {
		if (_kbhit()) { // If statement to detect user input
			system("CLS"); //clear screen
			break;
		}
	}
}
// prints answers to initial questions
void AirgeadBanking::initialPrint() {
	cout << setfill('*') << setw(41) << "*\n";
	cout << right << setfill('*') << setw(25) << "Data Input" << setw(15) << "*" << endl;
	cout << fixed << setprecision(2) << "Initial Investment Amount: $" << m_intAmount << endl;
	cout << "Monthly Deposit: $" << m_monthlyDeposit << endl;
	cout << fixed << setprecision(1) << "Annual Interest: %" << m_annualInterest << endl;
	cout << "Number of years: " << m_numYears << endl;
	cout << setfill('*') << setw(42) << "*\n\n";
}
// calculates compound interest and yearly balance with and without deposits
void AirgeadBanking::calculation() {
	setUpPrint();
	m_intAmountWO = m_intAmount;
	for (i = 0; i < m_numYears; ++i) {
		// resets interest variables to get accurate yearly values
		m_yearInterest = 0;
		m_yearInterestWO = 0;
		for (f = 0; f < 12; ++f) {
			// calculates with deposit
			m_interest = ((m_intAmount + m_monthlyDeposit) * ((m_annualInterest / 100.0) / 12.0));
			m_intAmount = (m_intAmount + m_monthlyDeposit + m_interest);
			m_yearInterest = m_yearInterest + m_interest;
			// calculates without deposit
			m_interestWO = ((m_intAmountWO) * ((m_annualInterest / 100.0) / 12.0));
			m_intAmountWO = (m_intAmountWO + m_interestWO);
			m_yearInterestWO = m_yearInterestWO + m_interestWO;
		}
		finalPrint();
	}
}
void AirgeadBanking::setUpPrint() {
	cout << right << setfill(' ') << setw(40) << "With a monthly deposit";
	cout << right << setfill(' ') << setw(43) << "Without a monthly Deposit\n";
	cout << setfill('=') << setw(88) << "=\n";
	cout << "Year     Interest Earned | Year End Balance";
	cout << "          Interest Earned | Year End Balance\n";
	cout << setfill('-') << setw(88) <<  "-\n";
}
void AirgeadBanking::finalPrint() {
	cout << setfill(' ') << setw(4) << (i + 1);
	cout << fixed << setprecision(2) << setfill(' ') << setw(20) << round(m_yearInterest * 100) / 100;
	cout << setfill(' ') << setw(19) << round(m_intAmount * 100) / 100;
	cout << setfill(' ') << setw(25) << round(m_yearInterestWO * 100) / 100;
	cout << setfill(' ') << setw(19) << round(m_intAmountWO * 100) / 100 << endl;
}