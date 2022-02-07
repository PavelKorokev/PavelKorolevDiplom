package SystemLib.Math;

type real64 is real using float64;

/**
 * MathLib is a C code class that returns the results of numerous mathematical functions.
 */

stateless class MathLib{
	@symbol("sqrt")
	extern public real64 sqrt(real64 val);
	@symbol("pow")
	extern public real64 pow(real64 val, real64 factor);
	@symbol("sin")
	extern public real64 sin(real64 val);
	@symbol("cos")
	extern public real64 cos(real64 val);
	@symbol("tan")
	extern public real64 tan(real64 val);
	@symbol("sinh")
	extern public real64 sinh(real64 val);
	@symbol("cosh")
	extern public real64 cosh(real64 val);
	@symbol("tanh")
	extern public real64 tanh(real64 val);
	@symbol("asin")
	extern public real64 asin(real64 val);
	@symbol("acos")
	extern public real64 acos(real64 val);
	@symbol("atan")
	extern public real64 atan(real64 val);
	@symbol("atan2")
	extern public real64 atan2(real64 x, real64 y);
	@symbol("exp")
	extern public real64 exp(real64 val);
	@symbol("log")
	extern public real64 log(real64 val);
	@symbol("log10")
	extern public real64 log10(real64 val);
	@symbol("ceil")
	extern public real64 ceil(real64 val);
	@symbol("floor")
	extern public real64 floor(real64 val);
}

