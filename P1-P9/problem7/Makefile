FLAGS = -Wall -g -std=gnu99 -O3
SRC=$(wildcard *.c)

soln: $(SRC)
	gcc $(FLAGS) -o $@ $^ -lm

clean:
	rm soln