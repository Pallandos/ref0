.PHONY: clean

default: all

all: hello_world password

hello_world: code/src/hello_world.c | out
	gcc -o code/out/hello_world code/src/hello_world.c

password: code/src/password.c | out
	gcc -o code/out/password code/src/password.c

out:
	mkdir -p code/out

clean:
	rm -f code/out/*