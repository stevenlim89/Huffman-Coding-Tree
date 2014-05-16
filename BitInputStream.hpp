// ---------------------------------------------------------------------------
// Filename: BitInputStream.hpp
// Authors: Steven Lim, Sharon Zheng
// Date: 5/5/2014
// Rev-Date: 5/16/2014
// Description: Reads bits and integers from an istream by obtaining a byte 
// 		and interpret each individual bit that has been compressed.
// Acknowledgements: Thank you, tutors!
// ---------------------------------------------------------------------------

#ifndef BITINPUTSTREAM_HPP
#define BITINPUTSTREAM_HPP

#include <iostream>
#include <bitset>

using namespace std;

/** A class for reading bits (and ints) from an istream
 */
class BitInputStream {
private:
    istream& in;  // the istream to delegate to
    unsigned char buf;     // the buffer of bits
    bitset<8> ch;
    int bufi;     // the bit buffer index

public:
bool flag = true;
  /** Initialize a BitInputStream object, given an istream.
   */
  BitInputStream(istream& s) : in(s), buf(0), bufi(8) { 
  }
  //    BitInputStream(istream& s) : in(s), bufi(8) { }
  

    /** Read the next bit from the bit buffer.
     *  If the bit buffer is currently empty,
     *  fill the bit buffer by reading a char from the istream first.
     *  Return the bit read as the least signficant bit of an int.
     *  Return -1 on EOF.
     *  This must be consistent with BitOutputStream::writeBit(), in terms
     *  of ordering of bits in the stream.
     */
    int readBit();

    /** Read a byte from the ostream.
     *  Return -1 on EOF.
     *  This function doesn't touch the bit buffer.
     *  The client has to manage interaction between reading bits
     *  and reading bytes.
     */
    int readByte();

    /** Read a non-negative int from the ostream.
     *  Return -1 on EOF.
     *  This function doesn't touch the bit buffer.
     *  The client has to manage interaction between reading bits
     *  and reading ints.
     */
    int readInt();


};

#endif // BITINPUTSTREAM_HPP
