package components;
import SystemLib.Delay.DelayValue;

class FilterBy {
	DelayValue DelayValue_instance;
	characteristic real K1 = 1.0;
	characteristic real K2 = 1.0;

	@generated("blockdiagram", "6f5e80c9")
	public real Filter(real in Inp, real in Ts) {
		real k1 = 1.0;
		real k2 = 1.0;
		DelayValue_instance.compute((((Ts / K1) * ((Inp * K2) - DelayValue_instance.value())) + DelayValue_instance.value())); // Main/Filter 1
		return(((Ts / K1) * ((Inp * K2) - DelayValue_instance.value())) + DelayValue_instance.value()); // Main/Filter 2
	}
}