#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"
#include <iostream>
using namespace std;

int BitInputStream::readBit()
{
	if(in.eof()){
		return -1;
	}
	
	if(bufi == 0){
		buf = in.get();
		bufi = 8;
	}
	
	int readBit = (buf & 1); 
	cout<<"This is the read bit:     "<<readBit<<endl;	
	buf = (buf>> 1);
	bufi--;
	cout<<"BUFI INDEX:               "<<bufi<<endl;
	return readBit;	
}
//edgar allen poe and spoken word
int BitInputStream::readByte()
{
	if(in.eof()){
		return -1;
	}

//	int character = in.read(buf, sizeof(char));
//	return character;
}

	
void BitInputStream::fill()
{
	cout<<"HELLLLLOOOOOOOOOOOOOOOOO"<<endl;	
	buf = in.get();
	bufi = 8;
}
int BitInputStream::readInt()
{
	if(in.eof()){
		return -1;
	}

}
