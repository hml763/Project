import serial
from numpy import *
import matplotlib.pyplot as plt

port = '/dev/ttyACM0'
srd = serial.Serial(port,9600)
srd.readline()
srd.flushInput()

lstX=[]
lstY=[]

plt.ion()
fig = plt.figure()
sf=fig.add_subplot(111)	#(1,1,1)

plt.xlim([0,60])
plt.ylim([300,1000])
line1, = sf.plot(arrX,arrY,'r-')


while(1):
	bytesR = srd.readline()
	lstR = eval(bytesR[:-2].decode())

	timeR = lstR[0]/1000.0
	lstX.append(timeR)
	lstY.append(lstR[1])

	line1.set_xdata(lstX)
	line1.set_ydata(lstY)

	plt.draw(), plt.pause(0.00001)
	print('time:%.3fs, value:%d' % (timeR, lstR[1]))
au.close()
