package components;
import SystemLib.Delay.DelayValue;

static class PIDTest {
	PID tester;
	characteristic real Out_InpPressure = 0.0;
	characteristic real Out_PressureSet = 0.0;
	characteristic real Out_qP = 0.0;
	characteristic real Out_qI = 0.0;
	characteristic real Out_qD = 0.0;
	real Out_return;

	@thread
	public void Out() {
		Out_return = tester.Out(Out_InpPressure, Out_PressureSet, Out_qP, Out_qI, Out_qD);
	}
}