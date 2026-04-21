main: main.c ./simulation/config.h ./simulation/config.c ./simulation/loan.h ./queue-types/queue.h ./queue-types/queue.c ./simulation/simulations.h ./simulation/simulations.c ./queue-types/priority_queue.c ./queue-types/priority_queue.h
	gcc main.c ./simulation/config.h ./simulation/config.c ./simulation/loan.h ./queue-types/queue.h ./queue-types/queue.c ./simulation/simulations.h ./simulation/simulations.c ./queue-types/priority_queue.c ./queue-types/priority_queue.h -o main

main.exe : main.c config.h config.c loan.h queue.h queue.c simulations.h simulations.c priority_queue.c priority_queue.h
	gcc -std=c99 main.c config.h config.c loan.h queue.h queue.c simulations.h simulations.c priority_queue.c priority_queue.h -o main.exe

main.o : main.c config.h config.c loan.h queue.h queue.c simulations.h simulations.c priority_queue.c priority_queue.h
	gcc -std=c99 main.c config.h config.c loan.h queue.h queue.c simulations.h simulations.c priority_queue.c priority_queue.h -o main.o