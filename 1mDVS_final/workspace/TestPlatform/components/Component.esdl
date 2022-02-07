package components;

static class Component
reads Filter.TsFilter, PID.PressSet, PID.qP, PID.qI, PID.qD, PID.TsPID, InpOut.Input
writes InpOut.Output {
	PID.PID PID_instance;
	RunningAverage RunningAverage_instance;
	FilterBy FilterBy_instance;
	real afterInp;
	real afterFilt;
	real afterRunAv;
	PID.PID PID_instance_2;

	@thread
	@generated("blockdiagram", "5d235b5a")
	public void Spid() {
		afterInp = InpOut.Input; // Main/Spid 1
		afterRunAv = RunningAverage_instance.mean(afterInp); // Main/Spid 2
		InpOut.Output = PID_instance.Regulator(afterFilt, afterRunAv, PID.qP, PID.qI, PID.qD, PID.TsPID); // Main/Spid 3
		afterFilt = FilterBy_instance.Filter(PID.PressSet, Filter.TsFilter); // Main/Spid 4
	}
}