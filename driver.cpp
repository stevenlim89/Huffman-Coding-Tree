#include "BitOutputStream.hpp"
#include "BitInputStream.hpp"
#include <fstream>

int main() {

  std::ofstream out;
  std::ifstream in;

  out.open("output", std::ios::binary);

  BitOutputStream bos(out);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);

  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);

  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);

  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);

  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);
  bos.writeBit(1);
  bos.writeBit(0);

  bos.flush();

  out.close();

  in.open("output", std::ios::binary);
  BitInputStream bis(in);

  int i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();


  std::cout << (char)i;

  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;

  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;

  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;

  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;

  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;
  i = bis.readBit() << 7;
  i += bis.readBit() << 6;
  i += bis.readBit() << 5;
  i += bis.readBit() << 4;
  i += bis.readBit() << 3;
  i += bis.readBit() << 2;
  i += bis.readBit() << 1;
  i += bis.readBit();

  std::cout << (char)i;

  return 0;
}
