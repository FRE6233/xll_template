// xll_template.h - common includes
#pragma once
#define _USE_MATH_DEFINES // for M_PI
#include <cmath>
#include "xll/xll/xll.h"

// F = f exp(-s^2/2 + s Z) <= k if and only if Z <= (log(k/f) + s^2/2)/s
inline double moneyness(double f, double s, double k)
{
	return (log(k / f) + s * s / 2) / s;
}

inline double normal_pdf(double z)
{
	return exp(-z * z / 2) / sqrt(2 * M_PI);
}

inline double normal_cdf(double z)
{
	return 0*z; //!!! use erf
}

// n-th derivative of the standard normal cumulant
inline double normal_cumulant(double s, unsigned int n = 0)
{
	if (n == 0) {
		return s * s / 2;
	}
	else if (n == 1) {
		return s;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		return 0;
	}
}

inline double black_put(double f, double s, double k)
{
	double z = moneyness(f, s, k);
	double N = 0*z; //!!! P(F <= k) = P(X <= z)
	double Ns = 0*z; //!!! P(Fe^{s^2/2} <= k) = P(X + s <= z) = P(X <= z - s)

	return k * N - f * Ns;
}