#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"

int BitInputStream::readBit()
{
	if(in.eof()){
		return -1;
	}
	
	if(bufi == 8){
		buf = in.get();
		ch = (int)buf;
//		cout<<"This is ch: "<<ch<<endl;
		bufi = 0;
	}
	//int readBit = (buf & 1); 
	int readBit = ((buf>>(7-bufi)) & 1);
	cout<<"This is the read bit:     "<<readBit<<endl;	
//	cout<<"BUFI INDEX:               "<<bufi<<endl;
	bufi++;
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

	
void BitInputStream::fill(int n)
{
	in.putback((char)n);
	bufi--;
}

int BitInputStream::readInt()
{
	if(in.eof()){
		return -1;
	}

}
