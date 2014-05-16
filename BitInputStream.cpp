#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"

int BitInputStream::readBit()
{
	if(!in.good()){
		return -1;
	}
	
	if(bufi == 8){
		//in.read(reinterpret_cast<char *>(&buf), 1);
		buf = in.get();
		bufi = 0;
	}
	unsigned int readBit = ((buf>>(7-bufi)) & 1);
	bufi++;
	return readBit;	
}

int BitInputStream::readByte()
{
	if(in.eof()){
		return -1;
	}

}

	
void BitInputStream::fill(int n)
{
	in.putback((unsigned char)n);
	bufi--;
}

int BitInputStream::readInt()
{
	if(in.eof()){
		return -1;
	}

}
