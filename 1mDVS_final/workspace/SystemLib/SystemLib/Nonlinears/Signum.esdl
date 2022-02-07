package SystemLib.Nonlinears;

/** Signum returns the sign of the input. */

stateless class Signum
using Impl {
	/** 1.0 is returned if x > 0.0, 0.0 is returned if x = 0.0, and -1.0 is returned if x < 0.0. */
	@no_side_effect
	@generated("blockdiagram", "2328ce4b")
	public real value(real in x) {
		return(if(x == 0.0) then 0.0 else(if(x > 0.0) then 1.0 else -1.0)); // Main/value 1
	}
	representation Impl {
		represent value return using {
			datatype = float64;
		};
		represent value.x using {
			datatype = float64;
		};
	}
}