FLAGS = -Wall -g -std=gnu99 -O3
SRC=$(wildcard *.c)

soln: $(SRC)
	gcc $(FLAGS) -o $@ $^

clean:
	rm soln