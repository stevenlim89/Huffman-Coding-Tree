// ---------------------------------------------------------------------------
// Filename: compress.cpp
// Authors: Steven Lim, Sharon Zheng
// Date: 5/5/2014
// Rev-Date: 5/16/2014
// Description: Compresses the file by obtaining the code from the tree and 
// 		store them into bytes. It will also write a frequency header
// 		for the file to be uncompressed containing a series of 
// 		frequencies to of all the ascii values.
// Acknowledgements: Thank you, tutors!
// ---------------------------------------------------------------------------
#include "BitOutputStream.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include "HCTree.hpp"
#include "BitOutputStream.hpp"
#define MAX 256

using namespace std;

 


int main( int argc, const char *argv[])
{
	//declares variables
	ifstream ifs;
	ofstream outputFile;
	vector< int> list_freq;	
	unsigned int asciiArray[MAX];
	unsigned int decode = 0;

	//opens to be encoded
	ifs.open(argv[1], ios::binary);
	outputFile.open(argv[2], ios::binary);

	//check if there are more than 3 arguments
	if( argc != 3 ){
		printf("Please put in correct input");
		exit(0); 
	}

	//set the frequency of all the arrays to zero
	for(int i =0 ; i < MAX; i++){
		asciiArray[i]=0;
	}
	

	//sets the frequency of each letter
	while(1){
		//loops to find the letter in the array and sets the
		//frequency in that array
		unsigned char letter1 = ifs.get();
		if(! ifs.good()) break;
		++(asciiArray[letter1]);	
		++decode;
		//obtains the next letter
        cout<<" This is the ascii array: " <<asciiArray[letter1]<< "letter1:    "<<letter1<<endl;
	}
	
	//closes the file that is read
	ifs.close();

	BitOutputStream bitFile(outputFile);
	//pushes all the frequency into a vector
	for( int k =0 ; k < MAX; k++){
		list_freq.push_back(asciiArray[k]);
		bitFile.writeInt(asciiArray[k]);		
	}

	//stores the number of times to be decoded
	bitFile.writeInt(decode);
	
	//creates a tree and build it by passing in the vector	
	HCTree tree;	
	tree.build(list_freq);
	
	//reopens the file
	ifs.open(argv[1], ios::binary);
	
	//obtains the first letter

	
	//encodes each letter in the file
	while(1){
		byte letter = ifs.get();

		if(!ifs.good())
			break;
		tree.encode(letter, bitFile);
	}

	//flushes the last bit to shift the bits over
	bitFile.flush();
	
	//closes the files
	ifs.close();
	outputFile.close();
	return 0;

}
