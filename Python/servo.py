import pigpio
import time
pi1 = pigpio.pi()
pi2 = pigpio.pi()
pi3 = pigpio.pi()
#2500
pi1.set_servo_pulsewidth(16,2500)
pi2.set_servo_pulsewidth(20,2500)
pi3.set_servo_pulsewidth(21,2500)
time.sleep(1)
