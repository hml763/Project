import serial
ser = serial.Serial("/dev/ttyACM0",9600)
print ser.portstr
while 1:

	ser.write("10")



