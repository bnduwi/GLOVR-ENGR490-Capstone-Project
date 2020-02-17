

class motor {

public:

int motorIN1, motorIN2, motorGearRatio;

float motorInputVoltage;

void setup(int IN1, int IN2, float motorInputVolts, int motorGR);

void setVoltage(float voltage);

//void readEncoder()

};
