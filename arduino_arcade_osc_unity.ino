#include <Arduino.h>

#include <Bounce2.h>
Bounce2::Button button1;

#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial); 

void setup()
{
    Serial.begin(115200);

    button1.attach(2, INPUT_PULLUP);
    button1.setPressedState(LOW);
    pinMode(3, OUTPUT);
}

void loop()
{
    button1.update();


    if (button1.pressed()) {

        monOsc.sendInt("/button1", 1);
    }

    if (button1.released()) {

        monOsc.sendInt("/button1", 0);
    }

    if (button1.isPressed()) {
        digitalWrite( 3 , HIGH );
    } else {
        digitalWrite( 3 , LOW );
    }
}
