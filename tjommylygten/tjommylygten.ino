#define LED_CONTROL_PIN 6
#define FAN_POWER_PIN 8
#define FAN_PWM_PIN 5
#define MODE_LED_PIN 13
#define SWITCH_PIN 9
#define ENCODER_SW 10
#define ENCODER_DT 11
#define ENCODER_CLK 12

#define LED_OFF 255
#define FAN_OFF HIGH

void setup() {
  pinMode(LED_CONTROL_PIN, OUTPUT);
  pinMode(FAN_POWER_PIN, OUTPUT);
  pinMode(FAN_PWM_PIN, OUTPUT);
  pinMode(MODE_LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT);
  pinMode(ENCODER_SW, INPUT);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_CLK, INPUT);
}

void loop() {
  // Read all pins
  int mainSwitch = digitalRead(SWITCH_PIN);

  // Do maths
  // Fx calculate blink speed based on rotary encoder, etc.

  // React on data
  if ( mainSwitch == HIGH ) {

  } else {
    analogWrite(LED_CONTROL_PIN, LED_OFF);
    digitalWrite(FAN_POWER_PIN, FAN_OFF);
  }
}