/*
 * Test Endian folks
 */

#include <stdio.h>

/* sometimes in sys/endian.h */
#include <endian.h>

int main(int argc, char *argv[])
{
    char *order = "unknown";
    char *memory = "";
    char *examples = "";

    switch (__BYTE_ORDER) {
        case __LITTLE_ENDIAN:
    	    order = "little";
    	    memory = "1234";
    	    examples = "Little Endian - LSB first: x86, Vax, Alpha, PPC";
    	    break;

        case __BIG_ENDIAN:
     	    order = "big";
    	    memory = "4321";
    	    examples = "Big Endian - MSB first: 68000, IBM 360/370, SPARC, Internet";
    	    break;

        case __PDP_ENDIAN:
     	    order = "pdp";
    	    memory = "3412";
    	    examples = "PDP11 Endian - LSB first in 16-bit word, MSW first in 32-bit long - PDP11";
    	    break;

        default:
    	    break;
    }
    printf("This is a %s endian machine.\n", order);
    printf("Memory layout of a byte: %s,\t%s\n", memory, examples);
    return(0);
}
