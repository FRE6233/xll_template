// xll_template.cpp - Sample xll project.
#include "xll_template.h"

using namespace xll;

AddIn xai_moneyness(
	Function(XLL_DOUBLE, "xll_moneyness", "NORMAL.MONEYNESS")
	.Arguments({
		Arg(XLL_DOUBLE, "f", "is the forwar4d."),
		Arg(XLL_DOUBLE, "s", "is the vol."),
		Arg(XLL_DOUBLE, "k", "is the strike.")
		})
);
double WINAPI xll_moneyness(double f, double s, double k)
{
#pragma XLLEXPORT
	return moneyness(f, s, k);
}

//!!! implement xll_normal_pdf as NORMAL.PDF using normal_pdf
//!!! implement xll_normal_cdf as NORMAL.CDF using normal_pdf
//!!! implement xll_normal_cumulant as NORMAL.CUMULANT using normal_cumlant
//!!! implement xll_black_put as BLACK.PUT using black_put