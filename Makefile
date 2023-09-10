all: helloWorld

helloWorld: helloWorld.c
	gcc -o helloWorld helloWorld.c


clean : 
	rm helloWorld