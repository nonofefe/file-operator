run:
	rm ./a.out
	g++ test.cpp -std=c++17 -I .
	./a.out
test:test.cpp
	g++ test.cpp -std=c++17 -I .
	./a.out
set: set.cpp
	g++ -std=c++17 -o set set.cpp
	./set
clean:
	rm test
	rm set