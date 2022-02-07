package SystemLib.Memory;

/** AccumulatorEnabled adds up its input value. It must be enabled explicitly and its accumulator value can be limited
*/
class AccumulatorEnabled
using Impl {
	real memory = 0.0;

	/** If enable is TRUE, the accumulator is incremented by the input value, i.e. accumulator(new) = accumulator(old) + input value. Additionally, the accumulator value is limited by mn and mx. */
	@generated("blockdiagram", "3d50d941")
	public void compute(real in valCompute, real in mn, real in mx, boolean in enable) {
		if (enable) {
			memory = max(min((valCompute + memory), mx), mn); // Main/compute 1/if-then 1
		} // Main/compute 1
	}

	/** The accumulator value is returned. */

	@no_side_effect
	@generated("blockdiagram", "bb3b8af9")
	public real value() {
		return memory; // Main/value 1
	}

	/** If initEnable is TRUE, the accumulator value is set to initValue. */
	@generated("blockdiagram", "58181567")
	public void reset(real in initValue, boolean in initEnalbe) {
		if (initEnalbe) {
			memory = initValue; // Main/reset 1/if-then 1
		} // Main/reset 1
	}
	representation Impl {
		represent compute.enable using {
			datatype = sint8;
		};
		represent reset.initEnalbe using {
			datatype = sint8;
		};
		represent reset.initValue using {
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
		represent compute.valCompute using {
			datatype = float64;
		};
	}
}