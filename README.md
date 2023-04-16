# Light-tracker
This robot uses two photoresists. 
One of them on the left and the other one on the right. 
The code understands the difference between these two photoresists. This code turns on the right engine or the left engine.
But if the difference is 0, that means the light is in front of the robot, it turns on the two engines at the same time.
And, if the value at these two photoresists is over than 1.023, that means "total darkness", the code turns on the right engine and turns off de left engine, turning 360° serching the light.
