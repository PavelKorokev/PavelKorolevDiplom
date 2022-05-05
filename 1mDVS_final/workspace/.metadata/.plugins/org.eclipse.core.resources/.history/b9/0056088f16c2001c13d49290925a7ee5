package PID;
import SystemLib.Delay.DelayValue;

class PID {
	real pMemory;
	DelayValue DelayValue_instance_5;
	characteristic real cP_Max = 100.0;
	characteristic real cP_Min = -100.0;
	characteristic real cI_Max = 100.0;
	characteristic real cD_Max = 100.0;
	characteristic real cD_Min = -100.0;
	characteristic real c = 0.0;
	characteristic real cI_Min = -100.0;
	real afterP;
	real afterI;
	real afterD;
	real Error;
	real InpOsc;
	characteristic real cPID_Max = 100.0;
	characteristic real cPID_Min = -100.0;

	@generated("blockdiagram", "95323c7e")
	public real Regulator(real in PressureSet, real in InpPressure, real in qP, real in qI, real in qD, real in dT_) {
		real pPressError;
		afterD = min(max(cD_Min, (qD * ((DelayValue_instance_5.value() - Error) / dT_))), cD_Max); // Main/Regulator 1
		afterP = min(max(cP_Min, (qP * Error)), cP_Max); // Main/Regulator 2
		InpOsc = PressureSet; // Main/Regulator 3
		Error = (InpOsc - InpPressure); // Main/Regulator 4
		DelayValue_instance_5.compute(Error); // Main/Regulator 5
		afterI = min(max(cI_Min, ((dT_ * (qI * Error)) + afterI)), cI_Max); // Main/Regulator 6
		return min(max(cPID_Min, (afterP + afterI + afterD)), cPID_Max); // Main/Regulator 7
	}

	@generated("blockdiagram", "45d26a2a")
	public real p_method() {
		return afterP; // Main/p_method 1
	}
}