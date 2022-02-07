package SystemLib.Transferfunction.Control;

/** P is a time discrete proportional transfer function with gain constant K. */


stateless class P
using Impl {
	/** The return value = val * K is computed. */
	@no_side_effect
	@generated("blockdiagram", "188879c2")
	public real value(real in val, real in K) {
		return(val * K); // Main/value 1
	}
	representation Impl {
		represent value.val using {
			datatype = float64;
		};
		represent value.K using {
			datatype = float64;
		};
		represent value return using {
			datatype = float64;
		};
	}
}