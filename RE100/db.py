import datetime
import time
import pymysql
import matplotlib.pyplot as plt
import matploblib.legend as legend
conn= pymysql.connect(host="192.168.0.154"
	user="pi",
	passwd="8323",
	db="pi_test")
current=datetime.datetime.now()
last_time=current-datetime.timedelta(minutes=1)
try
