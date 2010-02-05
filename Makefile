

CC = gcc -Wall
LIBS = -I src/ -lm

default:
	$(CC) src/main_v1.c -o bin/e2solver_v1 $(LIBS)
	$(CC) src/main_v2.c -o bin/e2solver_v2 $(LIBS)
	$(CC) src/main_v3.c -o bin/e2solver_v3 $(LIBS)
	$(CC) src/main_v4.c -o bin/e2solver_v4 $(LIBS)

clean:
	rm -f bin/*


