package components;
import SystemLib.Delay.DelayValue;

class PID {
	real pMemory;
	DelayValue DelayValue_instance_5;

	@generated("blockdiagram", "b90138b0")
	public real Out(real in InpPressure, real in PressureSet, real in qP, real in qI, real in qD) {
		const real cP_Max = 100.0;
		const real cP_Min = -100.0;
		const real cI_Max = 100.0;
		const real cI_Min = -100.0;
		const real cD_Max = 100.0;
		const real cD_Min = -100.0;
		real pPressError;
		pMemory = min(cI_Max, max((pPressError + pMemory), cI_Min)); // Main/Out 1
		pPressError = (PressureSet - InpPressure); // Main/Out 2
		DelayValue_instance_5.compute(pPressError); // Main/Out 3
		return(min(cP_Max, max((qP * pPressError), cP_Min)) + (qI * pMemory) + min(cD_Max, max((qD * (DelayValue_instance_5.value() - pPressError)), cD_Min))); // Main/Out 4
	}
}