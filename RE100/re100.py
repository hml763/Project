import MySQLdb
import serial
from time import localtime, strftime
import datetime
#import matplotlib.pyplot as plt
#from numby import *
#from matplotlib import animation as animation


now = datetime.datetime.now()
port = "/dev/ttyACM0"
serialFromArduino = serial.Serial(port,9600)
serialFromArduino.flushInput()
db = MySQLdb.connect("localhost","root","1234","re100")
curs = db.cursor()
list1=[]
i=1
count=0
ch = ""

print ".."

while 1:
	input_s = serialFromArduino.readline()
	amp = float(input_s)
#	int(amp) = am

	v = amp * 66 + 200
	amp = -amp

	if amp == 0.0:
		amp = 0

	print"Amp : ", amp
	print"V : ",v
	print ""
	amp = amp * 1000

	curs.execute("Insert into electricity values(%s, %s, %s)" , (now, amp, v))
	db.commit()
	#print"Vol : ", input
	#cur.execute("


