package components;
import SystemLib.Delay.DelayValue;

static class RunningAverageTest {
	RunningAverage tester;
	characteristic real mean_Inp = 0.0;
	real mean_return;

	@thread
	public void mean() {
		mean_return = tester.mean(mean_Inp);
	}
}