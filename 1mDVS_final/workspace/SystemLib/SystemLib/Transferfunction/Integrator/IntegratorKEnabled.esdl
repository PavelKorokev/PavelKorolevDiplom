package SystemLib.Transferfunction.Integrator;
import SystemLib.Miscellaneous.DeltaTimeService;

/** IntegratorKEnabled is a time discrete integrator with gain constant K. It must be enabled explicitly and its integrator value can be limited. */
class IntegratorKEnabled
using Impl {
	real memory = 0.0;

	/** If enable is TRUE, the integrator value is computed via integrator(new) = integrator(old) + in * dT * K (limited by mn and mx). */
	@generated("blockdiagram", "405cf552")
	public void compute(real in val, real in K, real in mn, real in mx, boolean in enable) {
		if (enable) {
			memory = max(min(((DeltaTimeService.deltaT * K * val) + memory), mx), mn); // Main/compute 1/if-then 1
		} // Main/compute 1
	}

	/** The integrator value is returned. */

	@no_side_effect
	@generated("blockdiagram", "d7c2b5d8")
	public real value() {
		return memory; // Main/value 1
	}

	/** If initEnable is TRUE, the integrator value is set to initValue. */
	@generated("blockdiagram", "59f99fea")
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
		represent compute.mn using {
			datatype = float64;
		};
		represent compute.mx using {
			datatype = float64;
		};
		represent value return using {
			datatype = float64;
		};
	}
}