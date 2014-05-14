#include "BitOutputStream.hpp"
using namespace std;



void BitOutputStream::writeBit(int bit)
{
	//cout<<"bufi before:"<<bufi<<endl;
	if(bufi == 8)
		flush();
	char mask = (buf<<1);
	buf = mask | (bit);
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
		buf<<(8-bufi);
	//cout<<"Byte stored is "<<(unsigned char)buf<<endl;	
	}
//	cout<<"Byte stored is "<<(unsigned char)buf<<endl;	
	out.put(buf);
	out.flush();
	buf = bufi = 0;
}
