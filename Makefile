.PHONY: clean

default: hello_world

hello_world: code/src/hello_world.c
	gcc -o code/hello_world code/src/hello_world.c

clean:
	rm -f code/hello_world