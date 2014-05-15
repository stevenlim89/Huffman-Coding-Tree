#include "BitOutputStream.hpp"
using namespace std;



void BitOutputStream::writeBit(int bit)
{
	//cout<<"bufi before:"<<bufi<<endl;
	if(bufi == 8)
	{
		flush();
		bufi = 0;
	}
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
		buf = buf<<(8-bufi);
	cout<<"Byte stored is "<<(unsigned char)buf<<endl;	
	}
//	cout<<"Byte stored is "<<(unsigned char)buf<<endl;
	ch = (int)buf;
	cout<<"This is the buf bitset: "<<ch<<endl;	
	out.put(buf);
	out.flush();
	//cout<<"Do you even flush bro?????"<<endl;
	buf = 0; 
	//bufi = 0;
}
