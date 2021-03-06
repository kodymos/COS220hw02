/*
220hw2.cpp
Assignment:  COS220_Homework2
Programmer:  Kody Moseley
Description: This program takes in string Isp packages, integer month number
			 and integer hours used in the month. It goes through error correcting
			 functions to make sure user input is correct. Outputs monthly bill cost
			 and what if scenarios with costs and savings if you had another plan. 
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int monthToDay(int month) {	//IN: integer month
							//OUT: returns the number of days in the month as integer
	//if month is jan, mar, may, jul, aug, oct, dec
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	}
	
	//if month is feb
	else if (month == 2) {	
		return 28;
	}
	//else month has 30 days
	else
		return 30;
}

int inputChecker(string package, int month, int hours) {//IN: string isp package, integer month, integer hours
														//OUT: returns 1 if the inputs are errors
	
	if (package == "A" || package == "B" || package == "C") {
	}
	else {									//if the package is not A, B, or C ==> return error
		return 1;
	}

	if (month < 1 || month > 12) {			//if month is negative or more than 12 ==> return error
		return 1;
	}
	
	if (hours > monthToDay(month) * 24) {	//if hours is more than month allows ==> return error
		return 1;
	}

	return 0;								//return 0 if no errors are found
}

int main()
{
	//variable declaration
	string sIspPlan = "";	//string isp plan
	int iMonthNumber = 0;	//integer month
	int iHoursUsed = 0;		//integer hours

	double dMonthlyCost = 0.0;	//double, end monthly bill

	//prompts to get user inputs
	cout << "Enter your plan: ";
	cin >> sIspPlan;	//prompt for isp plan
	cout << "Enter month number (1-12): ";
	cin >> iMonthNumber;//prompt for month number
	cout << "Enter hours used: ";
	cin >> iHoursUsed;	//prompt for monthly hours used

	cout << setprecision(2) << fixed;	//set precision

	//error checking: if zero, end program
	if (inputChecker(sIspPlan, iMonthNumber, iHoursUsed) == 1) {
		system("pause");
		exit(0);
	}

	//monthly bill calculation
	if (sIspPlan == "A" ) {		//if the string isp plan == A
		//if int hours used is 10, there is not overage cost
		dMonthlyCost = (iHoursUsed - 10) * 2 + 9.95;	
	}
	else if (sIspPlan == "B") {	//if the string isp plan == B
		//if int hours used is 20, there is not overage cost
		dMonthlyCost = (iHoursUsed - 20) + 14.95;	
	}
	else if (sIspPlan == "C") {	//if the string isp plan == C
		dMonthlyCost = 19.95;	//unlimited monthly cost
	}

	cout << "ISP Bill by Kody Moseley\n\n";	//name header

	cout << "Package: " << sIspPlan << endl;		//print out package 
	cout << "Hours Used: " << iHoursUsed << endl;	//print out hours
	cout << "Monthly Bill: $" << dMonthlyCost;		//print out calculated monthly bill
	cout << endl << endl;

	//output for Isp plan A
	if (sIspPlan == "A") {
		double whatIfB = (iHoursUsed - 20) + 14.95;		//double cost if it was plan B
		double whatIfBSavings = dMonthlyCost - whatIfB;	//double savings if it was plan B
		double whatIfC = 19.95;							//double cost if it was plan C
		double whatIfCSavings = dMonthlyCost - whatIfC;	//double savings if it was plan C

		//output for what if scenarios
		cout << "If you had used Package B the bill would be $" << whatIfB << " for a savings of $" << whatIfBSavings << "!" << endl;
		cout << "If you had used Package C the bill would be $" << whatIfC << " for a savings of $" << whatIfCSavings << "!" << endl;
	}
	
	//output for Isp plan B
	if (sIspPlan == "B") {
		double whatIfC = 19.95;							//double cost if it was plan C
		double whatIfCSavings = dMonthlyCost - whatIfC;	//double savings if it was plan C

		//output for what if scenario
		cout << "If you had used Package C the bill would be $" << whatIfC << " for a savings of $" << whatIfCSavings << "!" << endl;
	}

	system("pause");
	return 0;
}