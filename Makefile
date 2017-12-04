.PHONY: all clean test
all: bin/main

bin:
	mkdir $@

bin/src: | bin
	mkdir $@

bin/src/%.o: src/%.cpp | bin/src
	gcc -c -o $@ $^ -std=c++11

bin/main: bin/src/main.o
	gcc -o $@ $^

clean:
	rm -rf bin

test: bin/main
	bin/main < data/sample_input.txt

run: bin/main
	bin/main
