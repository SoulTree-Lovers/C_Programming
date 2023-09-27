all: helloWorld input rectangle salary theater typeSize sun quiz_01 unsigned change calc_int chicken

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

change: change.c
	gcc -o change change.c

unsigned: unsigned.c
	gcc -o unsigned unsigned.c

calc_int: calc_int.c
	gcc -o calc_int calc_int.c

chicken: chicken.c
	gcc -o chicken chicken.c

clean : 
	rm helloWorld input rectangle salary theater typeSize sun quiz_01 change unsigned calc_int chicken