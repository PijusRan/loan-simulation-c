main.exe : main.o
	gcc main.o -std=c99 -o main.exe

main.o : main.c ./simulation/config.h ./simulation/config.c ./simulation/loan.h  ./simulation/simulations.h ./simulation/simulations.c ./queue-types/queue.h ./queue-types/queue.c ./queue-types/priority_queue.c ./queue-types/priority_queue.h
	gcc -std=c99 main.c ./simulation/config.h ./simulation/config.c ./simulation/loan.h  ./simulation/simulations.h ./simulation/simulations.c ./queue-types/queue.h ./queue-types/queue.c ./queue-types/priority_queue.c ./queue-types/priority_queue.h -o main.o

main : main.c ./simulation/config.h ./simulation/config.c ./simulation/loan.h  ./simulation/simulations.h ./simulation/simulations.c ./queue-types/queue.h ./queue-types/queue.c ./queue-types/priority_queue.c ./queue-types/priority_queue.h
	gcc -std=c99 main.c ./simulation/config.h ./simulation/config.c ./simulation/loan.h  ./simulation/simulations.h ./simulation/simulations.c ./queue-types/queue.h ./queue-types/queue.c ./queue-types/priority_queue.c ./queue-types/priority_queue.h -o main