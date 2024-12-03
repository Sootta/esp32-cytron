#ifndef SOTA_ESP32_MOTOR
#define SOTA_ESP32_MOTOR

#include <Arduino.h>
#include <roboken_interface.h>

class Esp32Cytron : public Motor {
    public:
    Esp32Cytron(int dir_pin, int pwm_channel) {
        this->dir_pin = dir_pin;
        this->pwm_channel = pwm_channel;
    }

    void cw(int speed) {
        digitalWrite(dir_pin, LOW);
        ledcWrite(pwm_channel, speed);
    }

    void ccw(int speed) {
        digitalWrite(dir_pin, HIGH);
        ledcWrite(pwm_channel, speed);
    }

    private:
    int32_t dir_pin;
    int32_t pwm_channel;
};

#endif