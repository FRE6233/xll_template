// xll_template.cpp - Sample xll project.
#include <cmath> // for double tgamma(double)
#include "xll_template.h"





using namespace xll;

AddIn xai_moneynes(
	Function(XLL_DOUBLE, "xll_moneyness", "MONEYNESS")
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

AddIn xai_tgamma(
	// Return double, C++ name of function, Excel name.
	Function(XLL_DOUBLE, "xll_tgamma", "TGAMMA")
	// Array of function arguments.
	.Arguments({
		Arg(XLL_DOUBLE, "x", "is the value for which you want to calculate Gamma.")
	})
	// Function Wizard help.
	.FunctionHelp("Return the Gamma function value.")
	// Function Wizard category.
	.Category("MATH")
	// URL linked to `Help on this function`.
	.HelpTopic("https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/tgamma-tgammaf-tgammal")
	.Documentation(R"xyzyx(
The <i>Gamma</i> function is \(\Gamma(x) = \int_0^\infty t^{x - 1} e^{-t}\,dt\), \(x \ge 0\).
If \(n\) is a natural number then \(\Gamma(n + 1) = n! = n(n - 1)\cdots 1\).
<p>
Any valid HTML using <a href="https://katex.org/" target="_blank">KaTeX</a> can 
be used for documentation.
)xyzyx")
);
// WINAPI calling convention must be specified
double WINAPI xll_tgamma(double x)
{
#pragma XLLEXPORT // must be specified to export function

	return tgamma(x);
}

