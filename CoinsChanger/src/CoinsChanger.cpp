// Scott Auge
// Test Eclipse C/C++ on Linux
// Code to determine how much change for a given amount in US currency
// Beginning of auto-checkout programming


#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "CoinChanger.h"

// Use these to keep values to dollars

#define ONE 1.00
#define FIVE 5.00
#define TEN 10.00
#define TWENTY 20.00

// Use these to keep values to coins

#define QUARTER 0.25
#define DIME 0.10
#define NICKEL 0.05
#define PENNY 0.01

using namespace std;

int main(int argc, char **Arg) {

	float Change = 0.0;

	// Determine if user needs instructions

	if (argc < 2) {
		cout << Arg[0] << " " << "[Amount of US change]" << endl;
		return 0;
	}

	// Convert into decimal value

	Change = atof(Arg[1]);

	// cout << Change << endl;

	// Convert into coins

	cout << "Twenty: " << NumberOfCoins (&Change, TWENTY) << endl;
	cout << "Tens: " << NumberOfCoins (&Change, TEN) << endl;
	cout << "Fives: " << NumberOfCoins (&Change, FIVE) << endl;
	cout << "Ones: " << NumberOfCoins (&Change, ONE) << endl;
	cout << "Quarters: " << NumberOfCoins (&Change, QUARTER) << endl;
	cout << "Dimes: " << NumberOfCoins (&Change, DIME) << endl;
	cout << "Nickels: " << NumberOfCoins (&Change, NICKEL) << endl;
	cout << "Pennies: " << NumberOfCoins (&Change, PENNY) << endl;

	return 0;
} // main



int NumberOfCoins (float *Amt, float Denomination) {


	float CountOfCoin = 0;

	do {
		CountOfCoin++;
	} while (roundf(*Amt * 100) / 100 >= (CountOfCoin * Denomination));

	CountOfCoin--;

	// cout
	// << "Amount " << *Amt
	// << " CountOfCoin " <<  CountOfCoin
	// << " Denomination " << Denomination
	// << " Op " << CountOfCoin * Denomination
	// << endl;

	// Fun with floating points, use roundf to chop off the extra digits)
	// Pennies: Amount 0.04 CountOfCoin 4 Denomination 0.01 Op 0.04
	// Amount 0.00999998
	// 3


    *Amt -= CountOfCoin * Denomination;
    *Amt = roundf(*Amt * 100) / 100;

    // cout << "Amount " << *Amt << endl;

	return (int)CountOfCoin;

} // NumberOfCoins

