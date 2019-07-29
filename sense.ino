#include <Wire.h>
#include <LIDARLite.h>
#include <Servo.h>  //servo library

// Globals
LIDARLite lidarLite;
Servo myservo;      
int cal_cnt = 0;

void setup()
{
  Serial.begin(9600); // Initialize serial connection to display distance readings
  myservo.attach(3);
  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(1); 
}

void measure(int angle) {
  int dist;

  int iterations = 10;
  double tot = 0;
  for (int i = 0; i <= iterations; i+= 1) {
      dist = lidarLite.distance(); 
      tot += dist;
  }
  double average_dist = tot/iterations;

  // Increment reading counter
  cal_cnt++;
  cal_cnt = cal_cnt % 100;

  String delim = ",";
  // Display distance
  Serial.println(average_dist + delim + angle);

}

void loop()
{
  int max_pos = 150;
  int min_pos = 30;
  int pos;
  int delay_val = 10;  
  for (pos = min_pos; pos <= max_pos; pos += 1) {
    delay(delay_val);
    myservo.write(pos);
    measure(pos);
  }
  for (pos = max_pos; pos >= min_pos; pos -= 1) {
    delay(delay_val);
    myservo.write(pos);
    measure(pos);
  }
}
