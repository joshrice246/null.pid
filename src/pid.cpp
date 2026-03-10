

double kP = 0.4;
double kI = 0.001;
double kD = 0.2;

double error = 0;
double prevError = 0;
double integral = 0;
double derivative = 0;

double target = 1000; // desired encoder value