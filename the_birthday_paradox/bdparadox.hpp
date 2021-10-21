#pragma once

/*
*	Copyright © Mohammad Sadat Rahman, 2021
*	=================================================
*	
*	\file	bdparadox.hpp
*	\author	Mohammad Sadat Rahman
*	\date	21 Oct 2021
* 
*	function declarations of birthday paradox
*/


#include <cstdint>

/** Creating a struct to do the calculation of birthday paradox.
	A possibility of having a floating point number as the number of people
	or a negative number in that matter, is solved to some degree using a struct 
	and controlling what can be entered to calculate birthday problem. */

using people_type = std::uintmax_t;

/// <summary>
/// The number of people
/// </summary>
struct people_package {
	people_type _npeople;
	constexpr people_package(people_type people): _npeople(people) {}
};
/// <summary>
/// Constructs and returns an intantitated people_package
/// </summary>
/// <param name="people">The number of people</param>
/// <returns>An instantiated people_package struct</returns>
constexpr people_package people(std::intmax_t people) {
	if (people < 0) 
		people *= -1;
	return people_package(people);
}
constexpr people_package people(double num_people) { return people(static_cast<std::intmax_t>(num_people)); }
constexpr people_package people(float num_people) { return people(static_cast<std::intmax_t>(num_people)); }
template <typename T> constexpr people_package people(T num_people) { return people(static_cast<double>(num_people)); }



using probability_type = double;

/// <summary>
/// The probability of having all the people with different birthdays. <p>
/// Here, the probability: [0 <= probability <= 1]
/// </summary>
/// <param name="npeople">The number of people</param>
/// <returns>The probability of different birthdays</returns>
probability_type unmatch_percent(people_package npeople);

/// <summary>
/// The probability of having at least 1 pair of people with matching birthday <p>
/// Here, the probability: [0 <= probability <= 1]
/// </summary>
/// <param name="npeople">The number of people</param>
/// <returns>The probability of same birthdays</returns>
probability_type match_percent(people_package npeople);