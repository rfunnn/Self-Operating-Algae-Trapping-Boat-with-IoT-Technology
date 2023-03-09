#include <NewPing.h>
//Motor PINs
#define IN1 2
#define IN2 4
#define IN3 5
#define IN4 18
//sensor pins
#define trig_pin 22 //analog input 1
#define echo_pin 23 //analog input 2
#define maximum_distance 200
boolean goesForward = false;
int distance = 100;
bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;
bool automatic = 0; //new auto
char auth[] =
"Emx18uJLa8pwQsPxe3ci_jmEryyvmMad";
//Enter your Blynk application auth token
char ssid[] = "hehehehe"; //Enter your WIFI name
char pass[] = "arfan000"; //Enter your WIFI
passowrd
NewPing sonar(trig_pin, echo_pin,
maximum_distance); //sensor function Servo
servo_motor; //our servo name
void setup() {
Serial.begin(9600);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
servo_motor.attach(21); //NEW our servo pin
servo_motor.write(115);
delay(2000);
distance = readPing();
delay(100);
distance = readPing();
delay(100);
distance = readPing();
delay(100);
distance = readPing();
delay(100);
Blynk.begin(auth, ssid, pass);
}
BLYNK_WRITE(V0) {
forward = param.asInt();
}
BLYNK_WRITE(V1) {
backward = param.asInt();
}
BLYNK_WRITE(V2) {
left = param.asInt();
}
BLYNK_WRITE(V3) {
right = param.asInt();
}
BLYNK_WRITE(V4) {
automatic = param.asInt(); //new auto
}
void smartcar() {
carStop();
if (forward == 1) {
carforward();
Serial.println("carforward");
} else if (backward == 1) { carbackward();
Serial.println("carbackward");
} else if (left == 1) {
carturnleft();
Serial.println("carfleft");
} else if (right == 1) { carturnright();
Serial.println("carright");
} else if (automatic == 1) { //new auto
carStop();
Serial.println("carauto");
}else if (forward == 0 && backward == 0 && left
== 0 && right == 0 && automatic == 0)
{
carStop();
Serial.println("carstop");
}
}
void loop() {
int distanceRight = 0;
int distanceLeft = 0;
delay(50);
if (distance <= 20){
carStop();
delay(300);
carbackward();
delay(400);
carStop();
delay(300);
distanceRight = lookRight();
delay(300);
distanceLeft = lookLeft();
delay(300);
if (distance >= distanceLeft){
carturnright();
carStop();
}
else{
carturnleft();
carStop();
}
}
else{
carforward();
}
-Blynk.run();
smartcar();
distance = readPing()
int lookRight(){
servo_motor.write(50);
delay(500);
int distance = readPing();
delay(100);
servo_motor.write(115);
return distance; }
int lookLeft(){
servo_motor.write(170);
delay(500);
int distance = readPing();
delay(100);
servo_motor.write(115);
return distance;
delay(100); }
int readPing(){
delay(70);
int cm = sonar.ping_cm();
if (cm==0){
cm=250; }
return cm; }
void carforward() {
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW); }
void carbackward() {
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH); }
void carturnleft() {
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
delay(1000);
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW); }
void carturnright() {
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
delay(1000);
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH); }
void carStop() {
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW); }
