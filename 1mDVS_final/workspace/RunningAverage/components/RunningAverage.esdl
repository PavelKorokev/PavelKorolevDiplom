package components;
import SystemLib.Delay.DelayValue;

class RunningAverage {
	DelayValue DelayValue_instance;
	characteristic real c1 = 10.0;
	DelayValue DelayValue_instance_2;
	DelayValue DelayValue_instance_3;
	DelayValue DelayValue_instance_4;
	DelayValue DelayValue_instance_5;
	DelayValue DelayValue_instance_6;
	DelayValue DelayValue_instance_7;
	DelayValue DelayValue_instance_8;
	DelayValue DelayValue_instance_9;

	@generated("blockdiagram", "ca946a3e")
	public real mean(real in Inp) {
		DelayValue_instance.compute(Inp); // Main/mean 1
		DelayValue_instance_9.compute(DelayValue_instance_8.value()); // Main/mean 2
		DelayValue_instance_8.compute(DelayValue_instance_7.value()); // Main/mean 3
		DelayValue_instance_7.compute(DelayValue_instance_6.value()); // Main/mean 4
		DelayValue_instance_6.compute(DelayValue_instance_5.value()); // Main/mean 5
		DelayValue_instance_4.compute(DelayValue_instance_3.value()); // Main/mean 6
		DelayValue_instance_3.compute(DelayValue_instance_2.value()); // Main/mean 7
		DelayValue_instance_2.compute(DelayValue_instance.value()); // Main/mean 8
		DelayValue_instance_5.compute(DelayValue_instance_4.value()); // Main/mean 9
		return((DelayValue_instance_9.value() + (DelayValue_instance_8.value() + (DelayValue_instance_7.value() + (DelayValue_instance_6.value() + (DelayValue_instance_5.value() + (DelayValue_instance_4.value() + (DelayValue_instance_3.value() + (DelayValue_instance_2.value() + (DelayValue_instance.value() + Inp))))))))) / c1); // Main/mean 10
	}
}