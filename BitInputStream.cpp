#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"

int BitInputStream::readBit()
{
	if(in.eof()){
		return -1;
	}
	
	if(bufi == 8){
		buf = in.get();
		bufi = 0;
	}
	
	//int readBit = (buf & 1); 
//	cout<<"This is the read bit:     "<<readBit<<endl;	
	int readBit = ((buf>>(7-bufi)) & 1);
	bufi++;
	//cout<<"BUFI INDEX:               "<<bufi<<endl;
	return readBit;	
}

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
