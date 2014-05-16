// ---------------------------------------------------------------------------
// Filename: BitOutputStream.cpp
// Authors: Steven Lim, Sharon Zheng
// Date: 5/5/2014
// Rev-Date: 5/16/2014
// Description: Writes chars and integers to an ostream into bits by writing
// 		their binary code and compressing them.
// Acknowledgements: Thank you, tutors!
// ---------------------------------------------------------------------------
#include "BitOutputStream.hpp"
using namespace std;


// --------------------------------------------------------------------------
// void BitOutputStream::writeBit(int bit): Writes the least significant bit
// of the argument into the bit buffer and increments the bit buffer index.
// It will print to the ostream by calling on flush.
// char from the istream.
// Input: int bit-the bit that is being written onto the byte
// Output: <none>
// --------------------------------------------------------------------------
void BitOutputStream::writeBit(int bit)
{
	//checks if the buffer is full
	if(bufi == 8)
	{	
		flush();	//flushes the buffer
		bufi = 0;	//resets the index
	}
	
	//shifts the buffer by one and inserts the bit at the end
	unsigned char mask = (buf<<1) | bit;
	buf = mask;
	bufi++;
     
        
}

// --------------------------------------------------------------------------
// void BitOutputStream::writeByte(int b): Writes the least significant byte 
// of the argument to the ostream.
// It will print to the ostream by calling on flush.
// char from the istream.
// Input: int b-the integer that is being written into a byte
// Output: <none>
// --------------------------------------------------------------------------
void BitOutputStream::writeByte(int b)
{
	//gets the least significant byte
	out.put((char) b);
}

// --------------------------------------------------------------------------
// void BitOutputStream::writeInt(int i): Writes the argument to the ostream.
// char from the istream.
// Input: int i-the integer that is being written 
// Output: <none>
// --------------------------------------------------------------------------
void BitOutputStream::writeInt(int i)
{
	out.write((char*)(&i), 4);
}

// --------------------------------------------------------------------------
// void BitOutputStream::flush(): Flushes the bit buffer to the ostream and 
// clears the bit buffer and sets the bit buffer index to 0.
// Input: <none>
// Output: <none>
// --------------------------------------------------------------------------
void BitOutputStream::flush()
{	
	//checks if the buffer is full for the stray bits
	if(bufi != 8){
		buf = buf<<(8-bufi);
	}
	out.put(buf);
	out.flush();
	buf = 0; 
}
