/*
*	Copyright © Mohammad Sadat Rahman, 2021
*	=================================================
*
*	\file	bdparadox.cpp
*	\author	Mohammad Sadat Rahman
*	\date	21 Oct 2021
*
*	Definitions of birthday paradox algorithms
*/

#include "bdparadox.hpp"
#include <cmath>

namespace detail {
	/**
	*	!!!! WARNING !!!!
	*	=========================
	*	Do not use factorial for calculation.
	*	Factorial generates long numbers beyond calculation.
	*	Use detail::consecutive_product() instead.
	*/
	constexpr double factorial(std::uintmax_t n_) {
		if (n_ == 0 || n_ == 1)
			return 1;

		double product = double(n_);
		while (n_-- > 1) { product *= n_; }
		return product;
	}

	/// <summary>
	/// Calculates products of n consecutive natural numbers in the range [highest_n, lowest_n], where highest_n and lowest_n are inclusive, and (highest_n < lowest_n)
	/// </summary>
	/// <param name="highest_n">Highest number in the range</param>
	/// <param name="lowest_n">Lowest number in the range</param>
	/// <returns>the product of all numbers in the range</returns>
	constexpr double consecutive_product(std::intmax_t highest_n, std::intmax_t lowest_n) {
		if (highest_n < lowest_n || lowest_n == 0 || (highest_n >= 0 && lowest_n < 0)) return 0;

		double product = 1;

		while (highest_n >= lowest_n) { product *= highest_n--; }

		return product;
	}
}

probability_type unmatch_percent(people_package npeople)
{
	auto den = std::pow(366, npeople._npeople);

	return (detail::consecutive_product(366, 366 - npeople._npeople + 1) / den);
}

probability_type match_percent(people_package npeople)
{
	return 1 - unmatch_percent(npeople);
}
