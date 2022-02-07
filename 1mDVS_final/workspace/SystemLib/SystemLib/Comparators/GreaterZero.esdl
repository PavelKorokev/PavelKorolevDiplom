package SystemLib.Comparators;

/** 
 * GreaterZero returns TRUE if the value val is greater than zero.
*/

stateless class GreaterZero
using Impl {
	/** 
	 * TRUE is returned if val > 0.0. Otherwise, FALSE is returned.
	 */
	@no_side_effect
	@generated("blockdiagram", "4e6ac0e1")
	public boolean value(real in val) {
		return(val > 0.0); // Main/value 1
	}
	representation Impl {
		represent value.val using {
			datatype = float64;
		};
		represent value return using {
			datatype = sint16;
		};
	}
}