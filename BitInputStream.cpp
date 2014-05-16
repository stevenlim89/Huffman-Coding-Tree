// ---------------------------------------------------------------------------
// Filename: BitInputStream.cpp
// Authors: Steven Lim, Sharon Zheng
// Date: 5/5/2014
// Rev-Date: 5/16/2014
// Description: Reads bits and integers from an istream by obtaining a byte 
// 		and interpret each individual bit that has been compressed.
// Acknowledgements: Thank you, tutors!
// ---------------------------------------------------------------------------
#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"
#include <stdio.h>


// --------------------------------------------------------------------------
// int BitInputStream::readBit(): Reads the next bit from the bit buffer and
// if the bit buffer is currently empty, it will fill the bit by reading a
// char from the istream.
// Input: <none>
// Output: returns a readBit integer
// --------------------------------------------------------------------------

int BitInputStream::readBit()
{	
	//checks if the input file is good
	if(!in.good()){
		return -1;
	}
	
	//checks if the buffer is filled
	if(bufi == 8){
		//gets the next character
		buf = in.get();
		bufi = 0;
	}
	
	//shifts the bits overs
	unsigned int readBit = ((buf>>(7-bufi)) & 1);
	//increments the index of buffer
	bufi++;
	return readBit;	
}

// --------------------------------------------------------------------------
// int BitInputStream::readByte(): Reads a byte from the ostream
// char from the istream.
// Input: <none>
// Output: returns -1 on EOF
// --------------------------------------------------------------------------
int BitInputStream::readByte()
{
	if(in.eof()){
		return -1;
	}
	unsigned char readByte;
	readByte = in.get();
	return (int)readByte;
		

}

// --------------------------------------------------------------------------
// int BitInputStream::readBit(): Reads a non-negative int from the ostream
// char from the istream.
// Input: <none>
// Output: returns -1 on EOF
// --------------------------------------------------------------------------
int BitInputStream::readInt()
{
		int buffer = 0;
	in.read((char *)&buffer, 4);
if(in.eof()){
		printf("hello\n");
		return -1;
	}

	return buffer;

}
