
//Motores

#define MaxSpeed 150 // nunca passem dos 255

void Motores(int _velesq, int _veldir) {

  if (_velesq > 0) {
    if (_velesq > MaxSpeed)
      _velesq = MaxSpeed;

    _velesq = 255 - _velesq;
    analogWrite(MotorDir1, _velesq);
    digitalWrite(MotorDir2, 1);
  }
  else {
    _velesq = _velesq * (-1);
    if (_velesq > MaxSpeed)
      _velesq = MaxSpeed;

    analogWrite(MotorDir1, _velesq);
    digitalWrite(MotorDir2, 0);
  }

  if (_veldir > 0) {
    if (_veldir > MaxSpeed)
      _veldir = MaxSpeed;

    _veldir = 255 - _veldir;
    analogWrite(MotorEsq1, _veldir);
    digitalWrite(MotorEsq2, 1);
  }
  else {
    _veldir = _veldir * (-1);
    if (_veldir > MaxSpeed)
      _veldir = MaxSpeed;

    analogWrite(MotorEsq1, _veldir);
    digitalWrite(MotorEsq2, 0);
  }



}
