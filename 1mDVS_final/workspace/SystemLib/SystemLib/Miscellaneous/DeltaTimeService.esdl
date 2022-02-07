package SystemLib.Miscellaneous;

// time is using seconds as unit
type TimeType is real 0.0 .. 100.0;

/**
 * Provides the delta time variable
 */
static class DeltaTimeService {
	/**
	 * This value contains the delta time between two subsequent task activations in seconds.
	 * There are several representations possible.
	 */
	@dT
	public TimeType deltaT = 0.0;

	/**
	 * return the delta time value in microseconds
	 */
	@no_side_effect
	public integer getMicroSecond() {
		return integer(deltaT * 1_000_000.0);
	}

	representation Float64Resolution {
		represent deltaT using {
			datatype = float64;
		};
	}

	representation FixpointMilliSecondResolution {
		represent deltaT using {
			datatype = uint32;
			delta = 1.0e-3; // millisecond resolution
		};
	}

	representation FixPointMicroSecondResolution {
		represent deltaT using {
			datatype = uint32;
			delta = 1.0e-6; // microsecond resolution
		};
	}
}