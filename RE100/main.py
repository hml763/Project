import MySQLdb
import serial
import time
import datetime
import sys
import string
import math
import random
from random import *
import matplotlib.pyplot as plt

i=0
i1=0

db = MySQLdb.connect("localhost","root","1234","re100")
curs = db.cursor()

name = ['Jinsul Kim','Suik Cho','Dujin Kim','SunGyu Kim','Hunmin Lee','Jack','Peter','Bob','Sarah','Chris','Tim','Cross',12]
level = ['BOSS','HOD','HOD','HOD','HOD','Worker','Worker','Worker','Worker','Worker','Worker','Worker',12]
Department = ['CEO','Network','Embedded System','Website','Coding','Website','Coding','Embedded System','Network','Network','DataBase','DataBase',12]
Birthdate = ['123456','911219','951206','950516','950925','987654','473829','398723','423456','654375','767583','980990',12]


enterprise = ['Samsung','KEPCO','LG','POSCO','WoongJin','SK','Knergy','Incheon_E','Greenco','E-inteco','Skens','GS_energy','ASjae','Solartech','Google','Tesla','Roksun','Seoul_e','Hanwha','Dasan',20]
money = ['','','','','','','','','','','','','','','','','','','','',20]
amount= ['','','','','','','','','','','','','','','','','','','','',20]

ID = ['','','','','','','','','','','',11]
Password = ['','','','','','','','','','','',11]
Name = ['','','','','','','','','','','',11]


for a in range(0,20):
	ran_num = randint(100000,999999)
	money[a] = ran_num
	ran_num = randint(1000,9999)
	amount[a] = ran_num

now = time.localtime()
print "Current date : %d.%d.%d\n" % (now.tm_year,now.tm_mon,now.tm_mday)
print "Current time : %d:%d:%d\n" % (now.tm_hour,now.tm_min,now.tm_sec)

while True:
	print "Welcome to RE100!, TUI MODE \n"
	mode = input("Choose your option(1 : Administrator mode, 2 : User mode, 0 : Exit)\n")
	while mode == 1:
                print "\n\nAdministrator mode"
                print "Options\n-----------------------------------"
                print "1. Data\n2. Users\n3. Worker\n4. Statistics Graph\n5. Back\n0. Exit\n"
                opt = input("Choose your option : ")

                if opt == 1:
			print "\n\n				<Data>"
			print "-----------------------------------------------------------------------"
			print "|    User     |    SMP     |  Amount(KW)  |     REC     |     Sum     |"
			print "-----------------------------------------------------------------------"
			for i in range(0,12):
				print "| %10s  | %6s Won |   %6s KW  | %7s Won | %7s Won |" % (enterprise[i],amount[i]*75,amount[i],amount[i]*78,amount[i]*78 + amount[i]*75)
				print "-----------------------------------------------------------------------"

			curs.execute("Select * from worker;")


		elif opt == 2:
			print "\n\n      		   < User >"
			print "-------------------------------------------------"
			print "|  Num |     Name     | Money(Won) | Amount(KW) |"
			print "-------------------------------------------------"
			for i in range(0,20):
				print "|  %2d  |  %10s  |   %6s   |   %6s   |" % (i,enterprise[i],money[i],amount[i])
				print "-------------------------------------------------"


		elif opt == 3:
			print "\n\n                          < Worker >"
			print"-------------------------------------------------------------------"
			print "|  Num  |     Name     |  level  |      Department     |  birth   |"
			print "-------------------------------------------------------------------"
			for i in range(0,12):
				print "|  %2d   |  %10s  |%8s |%20s |  %6s  |" % (i,name[i],level[i],Department[i],Birthdate[i])
				print "-------------------------------------------------------------------"

		elif opt == 4:
			print "Statistics Graph"
			fig, ax_lst = plt.subplots(figsize=(8,5))

			plt.xlabel('Hour(Red : Summer, Blue : Fall, Green : Spring, Yellow : Winter)')
			plt.ylabel('KW')
			plt.title('Seasons Energy Production per Hour')

			ax_lst.set_xlim([0, 24])
			ax_lst.set_ylim([0, 1200])

			ax_lst.plot([0,0,0,0,0,0,0,20,80,230,600,820,1030,1050,840,620,240,90,30,0,0,0,0,0], 'ro-')
			ax_lst.plot([0,0,0,0,0,0,0,10,50,200,520,710,820,810,400,210,25,0,0,0,0,0,0,0], 'bo-')
			ax_lst.plot([0,0,0,0,0,0,0,10,60,270,570,780,950,945,630,360,100,10,0,0,0,0,0,0],'go-')
			ax_lst.plot([0,0,0,0,0,0,0,0,10,80,350,650,700,640,360,120,40,0,0,0,0,0,0,0],'yo-')

			plt.plot('d', label='Fall')
			plt.plot('e', label='Winter')
			plt.plot('c', label='Spring')
			plt.plot('y', label='Summer')
			plt.legend(loc='upper left')

			plt.show()


		elif opt == 5:
			print "Back"
			break


		elif opt == 0:
			print "Exit"
			sys.exit()


	while mode == 2:
		print "User mode\n"
		print "User Mode"
                opt3 = input("1. Member mode\n2. Nonmember mode\n3. Back\n0. Exit\nChoose your Option : ")
                if opt3 == 1:
                        print "Member mode\n"
                        print "Type in your ID and Password\n----------------------------------\n"
                        ID_login = raw_input("ID : ")
                        pass_login = raw_input("Password : ")

                        #for add for loop => check id and password 
                        for e in range (0,10) :
                                if ID_login == ID[e] and pass_login == Password[e]:
                                        print "\n\nLog in Success!\n\n"

                                while ID_login == ID[e] and pass_login == Password[e]:
                                        print "Choose your options\n-------------------------\n1. Buy electricity"
                                        print "2. See the Data\n3. Back\n0. Exit\n"
                                        opt5 = input("Your Option : ")

					if opt5 == 1:
						print "\n\nBuy Electricity\n"
                                                print "-----------------------------------------------------------------------"
                                                print "|    User     |    SMP     |  Amount(KW)  |     REC     |     Sum     |"
                                                print "-----------------------------------------------------------------------"
						for i in range(0,12):
                                                        print "| %10s  | %6s Won |   %6s KW  | %7s Won | %7s Won |" % (enterprise[i],amount[i]*75,amount[i],amount[i]*78,amount[i]*75 + amount[i]*78)
                                                        print "-----------------------------------------------------------------------"

						com = raw_input("Select Company : ")
						b_amount = input("Select amount of electricity(Unit : KW) : ")
						print "Total price is : %d" % (b_amount * 75 + b_amount * 78)
						print "Account : 074-107-663695\nDeadline : 0%d.%d, %d:%d\nphone num : 010-5166-8323\n" % (now.tm_mon,now.tm_mday,21,00)
						
						ans = raw_input("Payment Sent?")
						if ans == "done":
							print "Sending, Please Press the Blue button\n"
							amount[5] = amount[5] - b_amount
							print "\n\n"
							print "-----------------------------------------------------------------------"
	                                                print "|    User     |    SMP     |  Amount(KW)  |     REC     |     Sum     |"
        	                                        print "-----------------------------------------------------------------------"

                	                                for i in range(0,12):
                        	                                print "| %10s  | %6s Won |   %6s KW  | %7s Won | %7s Won |" % (enterprise[i],amount[i]*75,amount[i],amount[i]*78,amount[i]*78 + amount[i]*75)
                                	                        print "-----------------------------------------------------------------------"
							print "Thank you! It was a pleasure buissness with us! :)\n"

					elif opt5 == 2:
						print "\n\n"
						print "-----------------------------------------------------------------------"
	        		                print "|    User     |    SMP     |  Amount(KW)  |     REC     |     Sum     |"
        	        		        print "-----------------------------------------------------------------------"
                      				for i in range(0,12):
                                			print "| %10s  | %6s Won |   %6s KW  | %7s Won | %7s Won |" % (enterprise[i],amount[i]*75,amount[i],amount[i]*78,amount[i]*75 + amount[i]*78)
                                			print "-----------------------------------------------------------------------"


					elif opt5 == 3:
						print "Back"
						break

					elif opt5 == 0:
						print "Exit"
						sys.exit()

			if ID_login != ID[e] or pass_login != Password[e]:
                                print "\nLoging Out ... \n"




		elif opt3 == 2:
                        print "Nonmember mode\n"
                        print "To make reservation, You MUST be a member\nWould you like to Sign in?(y/n)"
                        opt4 = raw_input()
                        if opt4 == "y":
                                print "Membership add\n------------------------------------\n"
                                id = raw_input("Set your ID(1~10 letters) : ")
                                ID.insert(i1,id)
                                pw = raw_input("Set your Password(1~10 letters) : ")
                                Password.insert(i1,pw)
                                name = raw_input("Type your Name : ")
                                Name.insert(i1,name)
				print "\nThank you! You are now our new member!!\n\n"

				curs.execute("Insert into user values(%s, %s, %s)" , (id,pw,name))
                                db.commit()




	while mode == 0:
		print "Exit"
		sys.exit()


