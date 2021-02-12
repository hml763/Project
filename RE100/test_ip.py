import MySQLdb
import serial

ser= serial.Serial('/dev/ttyACM0',9600)
db = MySQLdb.connect("localhost","root","1234", "health_care")
curs=db.cursor()

try:
    print "insert"
    curs.execute("Insert into heart_rate_raw_data values(11, now());")
    db.commit()
    print "sucess"
except:
    print "error"
#while 1:
#	h = ser.readline()
#	print h
#	try:
#		print "hi"
#		curs.execute("Insert into sensor values(default,"+h+")")
#		db.commit()
#		print "End db commit"

#	except:
#		print "Error: db commit"

