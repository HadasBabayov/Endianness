// 322807629 Hadas Babayov

#include "ex1.h"

/**
 *
 * @return 1 - big endian, 0 - little endian.
 */
int is_big_endian(){
    long x = 1;
    // p - pointer to the first byte of x=1.
    char* p = (char*)&x;
    int FirstByte = *p & x;
    // If the first byte is 0 - it's big endian.
    if (FirstByte == 0){
        return 1;
    }
    return 0;
}

/**
 *
 * @param x unsigned long
 * @param y unsigned long
 * @return half bytes from x and half from y.
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y){
    int sizeOfLong = sizeof(long);

    unsigned long long firstBits, lastBits;
    if (sizeOfLong == 8){
        firstBits = 0xffffffff00000000;
        lastBits = 0x00000000ffffffff;
    }
    if (sizeOfLong == 4){
        firstBits = 0xffff0000;
        lastBits = 0x0000ffff;
    }
    // Update new x,y which contain half of bytes.
    unsigned long newX, newY;
    newX = x & firstBits;
    newY = y & lastBits;
    // Return the combine of new x and new y.
    return newX | newY;
}

/**
 *
 * @param x unsigned long
 * @param b unsigned char
 * @param i int
 * @return x after change the i byte to b.
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i){
    int numOfBytes = sizeof(x);
    unsigned char *p;
    // Update the address to change the byte according to the representation.
    if (is_big_endian()){
        p = (unsigned char *)&x + i;
    } else {
        p = (unsigned char *)&x + numOfBytes - i - 1;
    }
    // Change this byte.
    *p = b;
    return x;
}
