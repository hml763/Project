import MySQLdb
import serial
from time import localtime, strftime
import datetime
import math

now = datetime.datetime.now()
port = "/dev/ttyACM0"
serialFromArduino = serial.Serial(port,9600)
serialFromArduino.flushInput()
db = MySQLdb.connect("localhost","root","1234","health_care")
curs = db.cursor()
i=1
list=[]

while 1:
        for num in range(20):
                input_s = serialFromArduino.readline()
                input = int(input_s)
                print "EMG : ", input           
                curs.execute("Insert into SP02_raw_data values(%s, %s)" , (input, now))
                db.commit()
                list.insert(i, input)
                i+=1


        list.sort()
        print(list)
        print "max : ", list[len(list)-1]
        print "min : ", list[0]
        max = list[len(list)-1]
        min = list[0]
	
        curs.execute("Insert into SP02 values(%s, %s, %s)" , (max, min, now))
        db.commit() 

        break 


