
// Sonares
        
int sonares(int sonar_trig, int sonar_echo){     
        
        digitalWrite(sonar_echo, LOW);
	delayMicroseconds(2);
	digitalWrite(sonar_trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(sonar_trig, LOW);

	int duration = pulseIn(sonar_echo, HIGH,3500);

	int cm = duration/58.3;

        //delay(100);
        if(cm == 0)
          cm=40;
        return(cm);
}
