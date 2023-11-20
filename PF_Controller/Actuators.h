#ifndef ACTUATORS_H
#define ACTUATORS_H

typedef struct
{
  uint32_t servo1;
  uint32_t servo2;
  uint32_t servo3;
  uint32_t servo4;
  uint32_t motor1;
  uint32_t motor2;
}Actuators;

Actuators actuator = {0};


/*
* Here we set the timer ticks for PWM depending upon the required servo refresh rate and motor protocol.
* Note: PWM counter is 14 bit or 16384 ticks.
* Ticks per ms = (16384/(1/SERVO_REFRESH_XXXHz))*0.001
* Rather than do this calculation at run time we have the folowing timer defines for different servo refresh rates
*/
//TODO - test all refresh rates and with flaps
#ifdef SERVO_REFRESH_300HZ
  //4915 steps between 1-2ms
  #define SERVO_MIN_TICKS           4915
  #define SERVO_MAX_TICKS           9830
  #define SERVO_CENTRE_TICKS        7373
  #define SERVO_HALF_TRAVEL_TICKS   2458
  #define SERVO_REFRESH             300    
#else 
  #ifdef SERVO_REFRESH_250HZ
    //4096 steps between 1-2ms
    #define SERVO_MIN_TICKS           4096
    #define SERVO_MAX_TICKS           8192
    #define SERVO_CENTRE_TICKS        6144
    #define SERVO_HALF_TRAVEL_TICKS   2048
    #define SERVO_REFRESH             250   
  #else 
    #ifdef SERVO_REFRESH_150HZ
      //2458 steps between 1-2ms
      #define SERVO_MIN_TICKS           2458
      #define SERVO_MAX_TICKS           4915
      #define SERVO_CENTRE_TICKS        3686
      #define SERVO_HALF_TRAVEL_TICKS   1229   
      #define SERVO_REFRESH             150   
    #else
      #ifdef SERVO_REFRESH_100HZ 
        //1638 steps between 1-2ms
        #define SERVO_MIN_TICKS           1638
        #define SERVO_MAX_TICKS           3277
        #define SERVO_CENTRE_TICKS        2458
        #define SERVO_HALF_TRAVEL_TICKS   819
        #define SERVO_REFRESH             100   
      #else
        //SERVO_REFRESH_50HZ
        //819 steps between 1-2ms
        #define SERVO_MIN_TICKS           819
        #define SERVO_MAX_TICKS           1638
        #define SERVO_CENTRE_TICKS        1229
        #define SERVO_HALF_TRAVEL_TICKS   410
        #define SERVO_REFRESH             50   
      #endif
    #endif
  #endif
#endif

//Oneshot125 max and min timer ticks
#define ONESHOT125_MIN_TICKS      4096
#define ONESHOT125_MAX_TICKS      8192

#endif