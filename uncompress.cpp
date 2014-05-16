// ---------------------------------------------------------------------------
// Filename: uncompress.cpp
// Authors: Steven Lim, Sharon Zheng
// Date: 5/5/2014
// Rev-Date: 5/16/2014
// Description: Uncompresses the file that has been compress by recreating the
// 		tree with the frequency stored in the header file. Using the 
// 		same tree, the file will decode the message stored as a binary
// 		into the same file as before. 
// Acknowledgements: Thank you, tutors!
// ---------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <vector>
#include "HCTree.hpp" 
#include <istream>
#include "BitInputStream.hpp"
#include <istream>
#include <stdio.h>
using namespace std;


int main(int argc, const char *argv[]){
	//declare variables
	ifstream input;
	ofstream output;
	vector< int> freqList;
	unsigned int num_decode =0;
	unsigned int freq = 0; 

	// open files to be decoded
	input.open(argv[1], ios::binary);
	output.open(argv[2], ios::binary);

	// make sure there are 3 arguments inputted
	if(argc != 3){
		printf("Please put in correct inputs");
		exit(0);
   	}

	
   	BitInputStream inFile(input);
	BitOutputStream outFile(output);
	

		
	int size = 0;
	// checks encoded file for the frequency of all Ascii characters
	// and stores them into the vector 
	while(size<256){
		freq = inFile.readInt();
		//input>>freq;
		//cout<<"freq"<<freq<<endl;
		printf("%d\n", freq);
        	freqList.push_back(freq);
      		size++;
   	}
	
	//obtain the number for the times to decode
	num_decode=inFile.readInt();
	
	// build a tree using the frequency list that has been recreated
	HCTree tree;
	tree.build(freqList);



	//loops to decode the file
	for(int i = 0; i< num_decode; i++){
		int value = tree.decode(inFile);
		if(value != -1)
			outFile.writeByte((unsigned char)value);
		else
			break;
	}
        
	// close the files
	input.close();
	output.close();

	return 0;
}
