file := $(wildcard *.sk)
build:
	gcc -o bin/main main.c

run: build
	./bin/main $(file)

clean:
	rm -rf bin/main

.PHONY: clean run build
