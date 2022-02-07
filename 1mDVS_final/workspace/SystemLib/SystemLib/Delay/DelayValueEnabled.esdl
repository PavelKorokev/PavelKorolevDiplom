package SystemLib.Delay;

/** DelayValueEnabled delays its input value by one evaluation step. It must be enabled explicitly.
*/
class DelayValueEnabled
using Impl {
	real memory1 = 0.0;
	real memory2 = 0.0;

	/** If enable is TRUE, the input value is buffered. */
	@generated("blockdiagram", "f5777c56")
	public void compute(real in val, boolean in enable) {
		if (enable) {
			memory2 = memory1; // Main/compute 1/if-then 1
			memory1 = val; // Main/compute 1/if-then 2
		} // Main/compute 1
	}

	/** The buffered value is returned, thus the input value is delayed by one step. */

	@no_side_effect
	@generated("blockdiagram", "0e0150a6")
	public real value() {
		return memory2; // Main/value 1
	}

	/** If initEnable is TRUE, initValue is buffered. */
	@generated("blockdiagram", "07df33df")
	public void reset(real in initValue, boolean in initEnable) {
		if (initEnable) {
			memory1 = initValue; // Main/reset 1/if-then 1
			memory2 = memory1; // Main/reset 1/if-then 2
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
		represent memory1 using {
			datatype = float64;
		};
		represent memory2 using {
			datatype = float64;
		};
		represent value return using {
			datatype = float64;
		};
	}
}