compileAll : quicksort.o driver1.o
	gcc -g -pg quicksort.o driver.o -o myprogram

merge.o : quicksort.c quicksort.h
	gcc -g -pg -c merge.c 

driver1.o : driver.c
	gcc -g -pg -c driver.c
