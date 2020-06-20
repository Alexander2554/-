.PHONY: clean
all: bin/main 
test: bin/main

./bin/test: ./build/test/test_func.o ./build/src/func.o 
	g++ -Wall -I src -Werror -o ./bin/test ./build/src/func.o ./build/test/test_func.o -lm
	./bin/test

./bin/main: ./build/src/allzero.o ./build/src/congrats.o ./build/src/reaknots.o ./build/src/statistics.o ./build/src/validateknot1.o ./build/src/nim.o
	g++ -std=c++17 -Wall -Werror -o ./bin/main ./build/src/nim.o ./build/src/allzero.o ./build/src/congrats.o ./build/src/reaknots.o ./build/src/statistics.o ./build/src/validateknot1.o -lm

./build/src/allzero.o: ./src/allzero.cpp
	g++ -std=c++17 -c -o ./build/src/allzero.o ./src/allzero.cpp -lm

./build/src/congrats.o: ./src/congrat.cpp
	g++ -std=c++17  -c -o  ./build/src/congrats.o ./src/congrats.cpp -lm

./build/src/reaknots.o: ./src/reaknots.cpp
	g++ -std=c++17  -c -o  ./build/src/reaknots.o ./src/reaknots.cpp -lm

./build/src/nim.o: ./src/nim.cpp
	g++ -std=c++17  -c -o  ./build/src/nim.o ./src/nim.cpp -lm

./build/src/statistics.o: ./src/statistics.cpp
	g++ -std=c++17  -c -o  ./build/src/statistics.o ./src/statistics.cpp -lm

./build/src/validateknot1.o: ./src/validateknot1.cpp
	g++ -std=c++17  -c -o  ./build/src/validateknot1.o ./src/validateknot1.cpp -lm

clean:
	rm -rf bin/* build/src/*o build/test/*o

run_main:
	./bin/main

run_test:
	./bin/test
