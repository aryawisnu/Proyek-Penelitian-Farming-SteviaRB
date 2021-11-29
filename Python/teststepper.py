#library
import RPi.GPIO as GPIO
from RpiMotorLib import RpiMotorLib
import pigpio
import time
import os
#insiaialisasi gpio
GPIO_pins = (19,13,6)     # Microstep Resolution MS1-MS3 -> GPIO Pin
direction= 0               # Direction Pin, 
step = 5                   # Step Pin
servo1 = pigpio.pi()
servo2 = pigpio.pi()
servo3 = pigpio.pi()

distance = 600              #300 Default move 1mm => 80 steps per mm
baris = 1
#void setup
mymotortest = RpiMotorLib.A4988Nema(direction, step, GPIO_pins, "A4988")
#main
#True = maju
#False = mundur
servo1.set_servo_pulsewidth(21, 500)
servo2.set_servo_pulsewidth(20, 500)
servo3.set_servo_pulsewidth(16, 500)
time.sleep(1)
for number in range (14):
    mymotortest.motor_go(True, "Full" , distance, 0.001 , False, .05)
    time.sleep(1)
servo1.set_servo_pulsewidth(21, 2500)
servo2.set_servo_pulsewidth(20, 2500)
servo3.set_servo_pulsewidth(16, 2500)
time.sleep(1)
for number in range (14):
    mymotortest.motor_go(False, "Full" , distance, 0.001 , False, .05)
    time.sleep(1)
    
# for number in range (3):
#     mymotortest.motor_go(True, "Full" , distance, 0.001 , False, .05)
#     time.sleep(3)
#     baris = baris+1
#     print("motor jalan maju")
# servo1.set_servo_pulsewidth(21, 1600)
# servo2.set_servo_pulsewidth(20, 1600)
# servo3.set_servo_pulsewidth(16, 1600)
# print("servo putar")
#for number in range (3):
#    mymotortest.motor_go(False, "Full" , distance, 0.001 , False, .05)
#    time.sleep(3)
#    baris = baris+1
#    print("motor jalan mundur")    
    
    
