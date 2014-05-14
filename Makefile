

# A simple makefile for CSE 100 P3


CC=g++

CXXFLAGS=-std=c++11 -g

LDFLAGS=-g

<<<<<<< HEAD

all: compress uncompress
=======
all: compress
>>>>>>> 5f43817e50655b5bddf1ca231dac0a6cf72257fb


<<<<<<< HEAD
compress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o

=======
>>>>>>> 5f43817e50655b5bddf1ca231dac0a6cf72257fb

uncompress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o


HCTree.o: BitInputStream.hpp BitOutputStream.hpp HCNode.hpp HCTree.hpp


HCNode.o: HCNode.hpp


BitOutputStream.o: BitOutputStream.hpp


BitInputStream.o: BitInputStream.hpp


clean:
	rm -f compress uncompress *.o core*


