import datetime
import gspread
from oauth2client.service_account import ServiceAccountCredentials
import serial
import time
  
scope = ['https://spreadsheets.google.com/feeds','https://www.googleapis.com/auth/drive']
creds = ServiceAccountCredentials.from_json_keyfile_name('dataloggerfarming-6439fe6eb040.json', scope) 
client = gspread.authorize(creds)
sheet = client.open("Data_Logger").sheet1
#main
if __name__ == '__main__' :
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.flush()
    while True :
        if ser.in_waiting > 0 :
            timee = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')
            data = ser.readline().decode('utf-8').rstrip()
            datasplit = data.split(',')
            temp1  = datasplit[0]
            humid1 = datasplit[1]
            temp2  = datasplit[2]
            humid2 = datasplit[3]
            temp3  = datasplit[4]
            humid3 = datasplit[5]
            values =[timee,temp1,humid1,temp2,humid2,temp3,humid3]
            sheet.append_row(values)
            time.sleep(60)