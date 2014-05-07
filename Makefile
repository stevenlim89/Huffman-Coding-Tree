# A simple makefile for CSE 100 P3

CC=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-g

all: compress 

compress: compress.o 


compress.o: compress.cpp


HCTree.o: HCNode.hpp HCTree.hpp

HCNode.o: HCNode.hpp

BitOutputStream.o: BitOutputStream.hpp

BitInputStream.o: BitInputStream.hpp

clean:
	rm -f compress uncompress *.o core*

