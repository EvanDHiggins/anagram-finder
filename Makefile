

all: *.cpp
	clang++ -std=c++1z -o out $^
