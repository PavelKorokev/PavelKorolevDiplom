package SystemLib.Transferfunction.Control;
import SystemLib.Miscellaneous.DeltaTimeService;

/** DT1 is a time discrete differentiation transfer function with time constant T and gain constant K. */
class DT1
using Impl {
	real memory1 = 0.0;
	real memory2 = 0.0;
	characteristic real one = 1.0;

	/** The differentiation value is computed via a P-function and an I-function which is backcoupled. */
	@generated("blockdiagram", "cf055f41")
	public void compute(real in val, real in K, real in T) {
		memory1 = ((memory2 * (one / (T * K)) * DeltaTimeService.deltaT) + memory1); // Main/compute 1
		memory2 = (K * (val - memory1)); // Main/compute 2
	}

	/** The differentiation value is returned. */

	@no_side_effect
	@generated("blockdiagram", "e95e7197")
	public real value() {
		return memory2; // Main/value 1
	}

	/** The differentiation value is set to initValue. */
	@generated("blockdiagram", "f68b2edd")
	public void reset(real in initValue) {
		memory2 = initValue; // Main/reset 1
	}
	representation Impl {
		represent compute.val using {
			datatype = float64;
		};
		represent reset.initValue using {
			datatype = float64;
		};
		represent compute.K using {
			datatype = float64;
		};
		represent memory1 using {
			datatype = float64;
		};
		represent memory2 using {
			datatype = float64;
		};
		represent one using {
			datatype = float64;
		};
		represent value return using {
			datatype = float64;
		};
		represent compute.T using {
			datatype = float64;
		};
	}
}