all: helloWorld input rectangle salary theater typeSize sun quiz_01

helloWorld: helloWorld.c
	gcc -o helloWorld helloWorld.c

input: input.c
	gcc -o input input.c

rectangle: rectangle.c
	gcc -o rectangle rectangle.c

salary: salary.c
	gcc -o salary salary.c

theater: theater.c
	gcc -o theater theater.c

typeSize: typeSize.c
	gcc -o typeSize typeSize.c

sun: sun.c
	gcc -o sun sun.c

quiz_01: quiz_01.c
	gcc -o quiz_01 quiz_01.c

clean : 
	rm helloWorld input rectangle salary theater typeSize sun quiz_01