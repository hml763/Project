import MySQLdb
import serial
from time import localtime, strftime
import datetime

now = datetime.datetime.now()
port = "/dev/ttyACM1"
ard = serial.Serial(port,9600)
ard.flushInput()
db = MySQLdb.connect("localhost","root","1234","re100")
curs = db.cursor()

while 1:
	ans = input()
	if ans == 'q':
		break
	else :
		ans = ans.encode('utf-8')
		ard.write()

