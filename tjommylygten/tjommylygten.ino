// -------- //
// SETTINGS // 
// -------- //

// Fan speed on boot
// Limit to between 0 and 255
#define FAN_DEFAULT_SPEED 255

// LED power on boot
// Percentage between 0% (off) and 100% (on)
#define LED_POWER_DEFAULT 50

// // // // // // //
//  Configuration //
// // // // // // //

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
#define FAN_ON LOW

void setup() {
  pinMode(LED_CONTROL_PIN, OUTPUT);
  pinMode(FAN_POWER_PIN, OUTPUT);
  pinMode(FAN_PWM_PIN, OUTPUT);
  pinMode(MODE_LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(ENCODER_SW, INPUT);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_CLK, INPUT);
}

int setLedPercentage( int percentage = 0 ) {
  int LEDPwm = map(percentage, 0, 100, 255, 0);
  analogWrite(LED_CONTROL_PIN, LEDPwm);
}

int setFanPercentage( int percentage = 0 ) {
  int FanPwm = map(percentage, 0, 100, 255, 0);
  analogWrite(FAN_PWM_PIN, FanPwm);

  if ( percentage <= 0 ) {
    // Off
    digitalWrite(FAN_POWER_PIN, HIGH);
  } else {
    // ON
    digitalWrite(FAN_POWER_PIN, LOW);
  }
}

int lastEncoderClk = HIGH;

int fanSpeed = FAN_DEFAULT_SPEED;
int ledPower = LED_POWER_DEFAULT;

void loop() {
  // Read input pins
  int switchState = digitalRead(SWITCH_PIN);
  int newEncoderClk = digitalRead(ENCODER_CLK);

  // Handle Encoder rotation
  if (newEncoderClk != lastEncoderClk) {
    lastEncoderClk = newEncoderClk;
    int encoderDtValue = digitalRead(ENCODER_DT);

    if ( newEncoderClk == LOW && encoderDtValue == HIGH ) {
      // Clockwise rotation
      // DO SHIT
      // constrain(x, min, max);
    }
    if ( newEncoderClk == LOW && encoderDtValue == LOW ) {
      // Counterclockwise rotation
      // DO SHIT
      // constrain(x, min, max);
    }
  }

  // React on data
  if ( switchState == HIGH ) {
    setLedPercentage(ledPower);
    setFanPercentage(fanSpeed);
  } else {
    setLedPercentage();
    setFanPercentage();
  }
}