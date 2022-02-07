package SystemLib.Transferfunction.Lowpass;
import SystemLib.Miscellaneous.DeltaTimeService;

/** LowpassKEnabled is a simplified PT1 function with gain constant K (low pass filter). It must be enabled explicitly. */
class LowpassKEnabled
using Impl {
	real memory = 0.0;

	/** If enable is TRUE, the lowpass is computed via lowpass (new) = lowpass (old)+ (in - lowpass (old) ) * dT* K. */
	@generated("blockdiagram", "1fda9b73")
	public void compute(real in val, real in K, boolean in enable) {
		if (enable) {
			memory = (((DeltaTimeService.deltaT * K) * (val - memory)) + memory); // Main/compute 1/if-then 1
		} // Main/compute 1
	}

	/** The lowpass value is returned. */

	@no_side_effect
	@generated("blockdiagram", "2a5f3d05")
	public real value() {
		return memory; // Main/value 1
	}

	/** If initEnable is TRUE, the lowpass value is set to initValue. */
	@generated("blockdiagram", "2e5d444d")
	public void reset(real in initValue, boolean in initEnable) {
		if (initEnable) {
			memory = initValue; // Main/reset 1/if-then 1
		} // Main/reset 1
	}
	representation Impl {
		represent compute.enable using {
			datatype = sint8;
		};
		represent compute.val using {
			datatype = float64;
		};
		represent reset.initEnable using {
			datatype = sint8;
		};
		represent reset.initValue using {
			datatype = float64;
		};
		represent compute.K using {
			datatype = float64;
		};
		represent memory using {
			datatype = float64;
		};
		represent value return using {
			datatype = float64;
		};
	}
}