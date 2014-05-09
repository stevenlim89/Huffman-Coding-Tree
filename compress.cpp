// Sharon Zheng <s5zheng>, Steven Lim <stl054>

#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include "HCTree.hpp"
#define MAX 256

using namespace std;

 


int main( int argc, const char *argv[])
{
	ifstream ifs;
	ofstream outputFile;
	vector<int> list_freq;	
	int asciiArray[MAX];

	ifs.open(argv[1], ios::binary);
	outputFile.open(argv[2]);


	//check if there are more than 3 arguments
	if( argc != 3 ){
		printf("Please put in correct input");
		exit(0); 
	}

	//set the frequency of all the arrays to zero
	for(int i =0 ; i < MAX; i++){
		asciiArray[i]=0;
	}
	
	unsigned char letter1 = ifs.get();

	//sets the frequency of each letter
	while(ifs.good()){
		for(int index = 0; index < MAX; index++){
			if(index == letter1){
				asciiArray[index]++;
			}
		}
		letter1 = ifs.get();

	}

	//pushes all the frequency into a vector
	for( int k =0 ; k < MAX; k++){
		list_freq.push_back(asciiArray[k]);
		outputFile<<" "<<asciiArray[k];		
	}

        outputFile<<"!";	
	//resets the pointer to the beginning of the file
	ifs.clear();
	ifs.seekg(0, ios::beg);
	
	//creates a tree and build it
	HCTree * tree = new HCTree();
	tree->build(list_freq);

	unsigned char letter = ifs.get();

	//encodes each letter in the file
	while(ifs.good()){
		tree->encode(letter, outputFile);
		//cout<<"reached"<<endl;
		letter = ifs.get();

	}


	ifs.close();
	outputFile.close();
	return 0;

}
