// Sharon Zheng <s5zheng>, Steven Lim <stl054>

#include <fstream>
#include <iostream>
#include <vector>
#include <array>

#define MAX 256

using namespace std;

int main( int argc, const char *argv[])
{
   if( argc != 3 ){
      printf("Please put in correct input");
      exit(0); 
   }

  
   map<unsigned char, unsigned int> frequency;

   ifstream ifs;
   ifs.open(argv[1], ios::binary);
  
   
   int asciiArray[MAX];
   for(int i =0 ; i < MAX; i++)
   {
		asciiArray[i]=0;
	}


   while(ifs.good()){
   		   unsigned char letter = ifs.get();
   		  for(int index = 0; index < MAX; index++){
		     if(index == letter){
			    asciiArray[index]++;
			 }
		  }

	 }
 
 	for( int k =0 ; k < MAX; k++)
	{
		cout<<"index"<<k<<endl;
		cout<<"occurence:"<<asciiArray[k]<<endl;
	}
   ifs.close();
   return 0;
   
   
}
