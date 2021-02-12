import MySQLdb
import serial
from time import localtime, strftime
import datetime

now = datetime.datetime.now()
port = "/dev/ttyUSB0"
serialFromArduino = serial.Serial(port,9600)
serialFromArduino.flushInput()
db = MySQLdb.connect("localhost","root","1234","health_care")
curs = db.cursor()
list1=[]
i=1
count=0

while 1:
	for num in range(400):
		input_s = serialFromArduino.readline()
		input = int(input_s)
	
		print"Heart rate : ", input
		curs.execute("Insert into ECG_raw_data values(%s, %s)" , (input, now))
		db.commit()
		list1.insert(i, input)
		i+=1

		if input >= 160:
			count+=1

	list1.sort()
	print(list1)
	print "max : ", list1[len(list1)-1]
        print "min : ", list1[0]
#	print "Heart beat : ", count
        max = list1[len(list1)-1]
        min = list1[0]
        curs.execute("Insert into ECG values(%s, %s, %s, %s)" , (max, min, count, now))
        db.commit() 

        break 

	
