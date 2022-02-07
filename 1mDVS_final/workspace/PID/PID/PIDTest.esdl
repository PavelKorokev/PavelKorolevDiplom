package PID;
import SystemLib.Delay.DelayValue;



static class PIDTest {
	PID tester;
	characteristic real Regulator_PressureSet = 0.0;
	characteristic real Regulator_InpPressure = 0.0;
	characteristic real Regulator_qP = 0.0;
	characteristic real Regulator_qI = 0.0;
	characteristic real Regulator_qD = 0.0;
	characteristic real Regulator_dT_ = 0.0;
	real Regulator_return;

	@thread
	public void Regulator() {
		Regulator_return = tester.Regulator(Regulator_PressureSet, Regulator_InpPressure, Regulator_qP, Regulator_qI, Regulator_qD, Regulator_dT_);
	}
}