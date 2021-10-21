/*
*	Copyright © Mohammad Sadat Rahman, 2021
*	=================================================
*
*	\file	main.cpp
*	\author	Mohammad Sadat Rahman
*	\date	21 Oct 2021
*
*	Implementation of birthday paradox algorithms
*/


#include "bdparadox.hpp"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

void printusage() {
	cout << "\tusage: bdparadox [num_people]" << endl
		<< "\t\tnum_people\t: number of people to calculate a match for." << endl;
}

int main(int argc, char* argv[]) {

	cout << "Birthday Paradox (c) Mohammad Sadat Rahman, 2021\n"
		"===============================================" << endl << endl;

	people_package* ppl = new people_package(0);

	/** check for command line args */
	// check for arg overloads
	if (argc > 2) {
		cerr << "error: too many arguments." << endl;
		printusage();
		return EXIT_FAILURE;
	}
	// check for single arg
	if (argc == 2) {
		*ppl = people(stod(argv[1]));
	}
	// when no arg provided
	else {
		double nppl;
		cout << "Enter the number of people: ";
		cin >> nppl;
		*ppl = people(nppl);

		cout << endl << endl;
	}

	cout << "Birthday paradox calculation for " << ppl->_npeople << " people.\n"
		"----------------------------------------------------------------------" << endl;

	// match probability
	auto match = match_percent(*ppl);

	cout << "There is a/an [" << (match * 100) << "%] chance that at least 2 people among " << ppl->_npeople << " share the same birthday." << endl;
	cout << "On the contrary, there is a/an [" << ((1 - match) * 100) << "%] chance for not matching." << endl << endl;

	cout << "Raw probability: "
		<< "\tmatch:   " << match
		<< "\tunmatch: " << unmatch_percent(*ppl);


	//program return 
	return EXIT_SUCCESS;
}