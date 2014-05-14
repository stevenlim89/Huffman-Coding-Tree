#include "BitOutputStream.hpp"
using namespace std;



void BitOutputStream::writeBit(int bit)
{
	cout<<"bufi before:"<<bufi<<endl;
	if(bufi == 7)
		flush();
	unsigned char mask = (bit & 1) <<bufi;
	buf = buf | mask;
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
	out.put(buf);
	out.flush();
	buf = bufi = 0;
}
