#pragma config(Sensor, S1,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S3,     color,          sensorEV3_Color)
#pragma config(Sensor, S4,     ultra,          sensorEV3_Ultrasonic)

float color_reflected, white, black, boundary_value, vavg, s, t, left, right;

float getting_sensorvalue()
{
	float a;

	displayCenteredBigTextLine(3,"input");

	while(SensorValue[S1] == 0){}
	a = SensorValue[S3];

	displayCenteredBigTextLine(5,"wait");
	sleep(1000);

	return a;
}

float calculate_display()
{
	right = nMotorEncoder[motorB];
	left = nMotorEncoder[motorC];

	s = (right+left)/2/180*3.14*2.8;

	t = getTimerValue(T1);
	vavg = s/t;
	displayCenteredBigTextLine(7,"v = %0.3f cm/s",vavg);
	displayCenteredBigTextLine(9,"s = %0.3f cm",s);

	return 0;
}

float motorpower(float a, float b)
{
	motor[motorB] = a;
	motor[motorC] = b;

	return 0;
}

task main()
{
	displayCenteredBigTextLine(5,"white value");
	white = getting_sensorvalue();
	displayCenteredBigTextLine(5,"black value");
	black = getting_sensorvalue();
	boundary_value = (white+black)/2;

	eraseDisplay();
	displayCenteredBigTextLine(5,"press to go");
	while(SensorValue[S1] == 0){}
	clearTimer(T1);
	wait1Msec(1);

	while(SensorValue[S4]>10)
	{
		calculate_display();
		color_reflected = SensorValue[S3];
		if(color_reflected<=boundary_value)
		{
			motorpower(1,10);
		}
		else
		{
			motorpower(5,-5);
		}
	}

	while(SensorValue[S4]>5)
	{
		calculate_display();
		motorpower(SensorValue[S4]- 5,SensorValue[S4]- 5);
	}
	motorpower(0,0);
	while(SensorValue[S1] == 0){}

}
