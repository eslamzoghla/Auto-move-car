void move_forward_motor()
{
  analogWrite (enable_right_motor, speed_right_motor);
  analogWrite (enable_left_motor, speed_left_motor);
  digitalWrite(input1_right_motor, HIGH);
  digitalWrite(input2_right_motor, LOW);
  digitalWrite(input1_left_motor, HIGH);
  digitalWrite(input2_left_motor, LOW);

}
void move_back_motor()
{
  analogWrite (enable_right_motor, speed_right_motor);
  analogWrite (enable_left_motor, speed_left_motor);
  digitalWrite(input1_right_motor, LOW);
  digitalWrite(input2_right_motor, HIGH);
  digitalWrite(input1_left_motor, LOW);
  digitalWrite(input2_left_motor, HIGH);
}
void move_right_motor()
{
  analogWrite (enable_right_motor, speed_right_motor);
  analogWrite (enable_left_motor, speed_left_motor);
  digitalWrite(input1_right_motor, LOW);
  digitalWrite(input2_right_motor, HIGH);
  digitalWrite(input1_left_motor, HIGH);
  digitalWrite(input2_left_motor, LOW);
}
void move_left_motor()
{
  analogWrite (enable_right_motor, speed_right_motor);
  analogWrite (enable_left_motor, speed_left_motor);
  digitalWrite(input1_right_motor, HIGH);
  digitalWrite(input2_right_motor, LOW);
  digitalWrite(input1_left_motor, LOW);
  digitalWrite(input2_left_motor, HIGH);
}
void stop_motor()
{
  digitalWrite(input1_right_motor, LOW);
  digitalWrite(input2_right_motor, LOW);
  digitalWrite(input1_left_motor, LOW);
  digitalWrite(input2_left_motor, LOW);
}
void forward_distance_calibration()
{
  stop_motor();
  delay(1000);
  move_forward_motor();
  delay(2000);
  stop_motor();
  while (1) {}

}
void move_distance(float dis)
{
  int delay_time = int(dis / veliacty);
  stop_motor();
  delay(500);
  move_forward_motor();
  delay(delay_time);
  stop_motor();
  delay(500);
}
void right_distance_calibration()
{
  stop_motor();
  delay(500);
  move_right_motor();
  delay(3950);
  stop_motor();
  while (1) {}
}
void left_distance_calibration()
{
  stop_motor();
  delay(500);
  move_left_motor();
  delay(3950);
  stop_motor();
  while (1) {}
}
void rotation_degree(float degree, char letter_direction)
{
  int right_delay_time = int(degree / right_angler_veliacty);
  int left_delay_time = int(degree / left_angler_veliacty);
  if (letter_direction == 'R' || letter_direction == 'r')
  {
    move_right_motor();
    delay(right_delay_time);
  }
  if (letter_direction == 'L' || letter_direction == 'l')
  {
    move_left_motor();
    delay(left_delay_time);
  }
  stop_motor();
  delay(500);
}
void forward_distance_read()
{
  digitalWrite(trager_forward, HIGH);
  delayMicroseconds(10);
  digitalWrite(trager_forward, LOW);
  float time_forward = pulseIn(ehco_forward, HIGH);
  forward_distance = (0.034 * time_forward) / 2;
  //delay(85);
}
void right_distance_read()
{
  digitalWrite(trager_right, HIGH);
  delayMicroseconds(10);
  digitalWrite(trager_right, LOW);
  float time_right = pulseIn(ehco_right, HIGH);
  right_distance = (0.034 * time_right) / 2;
  //delay(85);
}
void left_distance_read()
{
  digitalWrite(trager_left, HIGH);
  delayMicroseconds(10);
  digitalWrite(trager_left, LOW);
  float time_left = pulseIn(ehco_left, HIGH);
  left_distance = (0.034 * time_left) / 2;
  //delay(85);
}
