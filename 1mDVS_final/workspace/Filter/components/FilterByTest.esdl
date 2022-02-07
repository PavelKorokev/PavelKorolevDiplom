package components;
import SystemLib.Delay.DelayValue;

static class FilterByTest {
	FilterBy tester;
	characteristic real Filter_Inp = 0.0;
	characteristic real Filter_Ts = 0.0;
	real Filter_return;

	@thread
	public void Filter() {
		Filter_return = tester.Filter(Filter_Inp, Filter_Ts);
	}
}