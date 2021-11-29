#library
import RPi.GPIO as GPIO
from RpiMotorLib import RpiMotorLib
from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive
import datetime
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
#inisialisasi google drive api
gauth = GoogleAuth()
gauth.LoadCredentialsFile("mycreds.txt")
#gauth.LocalWebserverAuth()
if gauth.credentials is None:
    gauth.LocalWebserverAuth()
elif gauth.access_token_expired:
    gauth.Refresh()
else:
    gauth.Authorize()
gauth.SaveCredentialsFile("mycreds.txt")
drive = GoogleDrive(gauth)
#data
t = datetime.datetime.now().strftime("%Y-%m-%d_%H:%M")
fid = '1M2AOTV6g184XZzttXmVeblcx9yQ4fvdf'
distance = 600               # Default move 1mm => 80 steps per mm
baris = 1
#deklarasi pin
mymotortest = RpiMotorLib.A4988Nema(direction, step, GPIO_pins, "A4988")
#main
servo1.set_servo_pulsewidth(21, 2500)
servo2.set_servo_pulsewidth(20, 2500)
servo3.set_servo_pulsewidth(16, 2500)
print("servo putar")
time.sleep(1)
for number in range (14):
    mymotortest.motor_go(True, "Full" , distance, 0.001 , False, .05)
    filename = ("Rak1_Baris{0}_{1}".format(baris, t))
    os.system('fswebcam -d /dev/video3 -r 1920x1080 -S 10 /home/pi/hasilfoto/{0}.png'.format(filename))
    print("foto rak 1 dijepret")
    time.sleep(3)
    f = drive.CreateFile({"parents": [{"kind": "drive#fileLink", "id": fid}]})
    f.SetContentFile('/home/pi/hasilfoto/{0}.png'.format(filename))
    f.Upload()
    print("foto rak 1 diaplod")
    time.sleep(2)
    filenamee = ("Rak2_Baris{0}_{1}".format(baris, t))
    os.system('fswebcam -d /dev/video1 -r 1920x1080 -S 10 /home/pi/hasilfoto/{0}.png'.format(filenamee))
    print("foto rak 2 dijepret")
    time.sleep(3)
    f = drive.CreateFile({"parents": [{"kind": "drive#fileLink", "id": fid}]})
    f.SetContentFile('/home/pi/hasilfoto/{0}.png'.format(filenamee))
    f.Upload()
    print("foto rak 2 diaplod")
    time.sleep(2)
    filenameee = ("Rak3_Baris{0}_{1}".format(baris, t))
    os.system('fswebcam -d /dev/video2 -r 1920x1080 -S 10 /home/pi/hasilfoto/{0}.png'.format(filenameee))
    print("foto rak 3 dijepret")
    time.sleep(3)
    f = drive.CreateFile({"parents": [{"kind": "drive#fileLink", "id": fid}]})
    f.SetContentFile('/home/pi/hasilfoto/{0}.png'.format(filenameee))
    f.Upload()
    print("foto rak 3 diaplod")
    time.sleep(2)
    baris = baris+1

servo1.set_servo_pulsewidth(21, 500)
servo2.set_servo_pulsewidth(20, 500)
servo3.set_servo_pulsewidth(16, 500)
print("servo putar")
time.sleep(1)
for number in range (14):
    mymotortest.motor_go(False, "Full" , distance, 0.001 , False, .05)
    filename = ("Rak1_Baris{0}_{1}".format(baris, t))
    os.system('fswebcam -d /dev/video4 -r 1920x1080 -S 10 /home/pi/hasilfoto/{0}.png'.format(filename))
    print("foto rak 1 dijepret")
    time.sleep(3)
    f = drive.CreateFile({"parents": [{"kind": "drive#fileLink", "id": fid}]})
    f.SetContentFile('/home/pi/hasilfoto/{0}.png'.format(filename))
    f.Upload()
    print("foto rak 1 diaplod")
    time.sleep(2)
    filenamee = ("Rak2_Baris{0}_{1}".format(baris, t))
    os.system('fswebcam -d /dev/video0 -r 1920x1080 -S 10 /home/pi/hasilfoto/{0}.png'.format(filenamee))
    print("foto rak 2 dijepret")
    time.sleep(3)
    f = drive.CreateFile({"parents": [{"kind": "drive#fileLink", "id": fid}]})
    f.SetContentFile('/home/pi/hasilfoto/{0}.png'.format(filenamee))
    f.Upload()
    print("foto rak 2 diaplod")
    time.sleep(2)
    filenameee = ("Rak3_Baris{0}_{1}".format(baris, t))
    os.system('fswebcam -d /dev/video2 -r 1920x1080 -S 10 /home/pi/hasilfoto/{0}.png'.format(filenameee))
    print("foto rak 3 dijepret")
    time.sleep(3)
    f = drive.CreateFile({"parents": [{"kind": "drive#fileLink", "id": fid}]})
    f.SetContentFile('/home/pi/hasilfoto/{0}.png'.format(filenameee))
    f.Upload()
    print("foto rak 3 diaplod")
    time.sleep(2)
    baris = baris+1
    