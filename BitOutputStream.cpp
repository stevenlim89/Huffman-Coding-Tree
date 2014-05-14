#include "BitOutputStream.hpp"
using namespace std;



void BitOutputStream::writeBit(int bit)
{
	if(bufi == 7)
		out.flush();
	char mask = (bit & 1) <<bufi;
	buf = buf | mask;
	bufi++;
     
        
}

void BitOutputStream::writeByte(int b)
{
	char byte = (b & 0xFF);
	out<<byte;
}

void BitOutputStream::writeInt(int i)
{
	out<<i;
}

void BitOutputStream::flush()
{
	out.put(buf);
	out.flush();
	buf = bufi = 0;
}
