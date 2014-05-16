#include "BitOutputStream.hpp"
using namespace std;



void BitOutputStream::writeBit(int bit)
{
	if(bufi == 8)
	{
		flush();
		bufi = 0;
	}
	unsigned char mask = (buf<<1) | bit;
	buf = mask;
	bufi++;
     
        
}

void BitOutputStream::writeByte(int b)
{
	unsigned char byte = (b & 0xFF);
	out<<byte;
}

void BitOutputStream::writeInt(int i)
{
	out<<i;
}

void BitOutputStream::flush()
{
	if(bufi != 8){
		buf = buf<<(8-bufi);
	}
	out.put(buf);
	out.flush();
	buf = 0; 
}
