package SystemLib.Comparators;

/** 
 * RightOpenInterval returns TRUE if the value x is in the right open interval defined by A and B.
*/

stateless class RightOpenInterval
using Impl {
	/** 
	 * TRUE is returned if A <= x < B. Otherwise, FALSE is returned.
	 */
	@no_side_effect
	@generated("blockdiagram", "6e71f310")
	public boolean value(real in A, real in x, real in B) {
		return((A <= x) && (x < B)); // Main/value 1
	}
	representation Impl {
		represent value.A using {
			datatype = float64;
		};
		represent value.B using {
			datatype = float64;
		};
		represent value return using {
			datatype = sint8;
		};
		represent value.x using {
			datatype = float64;
		};
	}
}