.PHONY: clean

default: hello_world

hello_world: code/src/hello_world.c | out
	gcc -o code/out/hello_world code/src/hello_world.c

out:
	mkdir -p code/out

clean:
	rm -f code/out/*