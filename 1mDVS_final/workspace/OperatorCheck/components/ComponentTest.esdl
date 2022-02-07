package components;

static class ComponentTest {
	Component tester;
	characteristic real calc_arg = 0.0;
	characteristic real calc_arg_2 = 0.0;
	characteristic real calc_Rest = 0.0;
	real calc_return;

	@thread
	public void calc() {
		calc_return = tester.calc(calc_arg, calc_arg_2, calc_Rest);
	}
}