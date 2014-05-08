# A simple makefile for CSE 100 P3

CC=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-g

all: compress uncompress

compress: HCNode.o HCTree.o 

uncompress: HCNode.o HCTree.o

HCTree.o: HCNode.hpp HCTree.hpp HCTree.cpp 

HCNode.o: HCNode.hpp HCNode.cpp

BitOutputStream.o: BitOutputStream.hpp

BitInputStream.o: BitInputStream.hpp

new:
	make clean
	make

clean:
	rm -f compress uncompress *.o core*

