package SystemLib.Miscellaneous;

/** DeltaOneStep returns the difference of the current input value and the last input value. */
class DeltaOneStep
using Impl {
	real buffer = 0.0;
	real oldValue = 0.0;

	/** The previous input value is subtracted from the input value. */
	@generated("blockdiagram", "335a9ed0")
	public void compute(real in val) {
		buffer = (val - oldValue); // Main/compute 1
		oldValue = val; // Main/compute 2
	}

	/** The difference is returned. */

	@no_side_effect
	@generated("blockdiagram", "c1805d56")
	public real value() {
		return buffer; // Main/value 1
	}
	representation Impl {
		represent buffer using {
			datatype = float64;
		};
		represent oldValue using {
			datatype = float64;
		};
		represent value return using {
			datatype = float64;
		};
		represent compute.val using {
			datatype = float64;
		};
	}
}