#include <stdio.h>

union intParts {
  int theInt;
  char bytes[sizeof(int)];
};

union Coins {
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    }; // anonymous struct acts the same way as an anonymous union, members are on the outer container
    int coins[4];
};


int main() {
    union intParts parts;
    parts.theInt = 5968145; // arbitrary number > 255 (1 byte)

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
        parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

    // vs

    int theInt = parts.theInt;
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
        theInt, *((char*)&theInt+0), *((char*)&theInt+1), *((char*)&theInt+2), *((char*)&theInt+3));

    // or with array syntax which can be a tiny bit nicer sometimes

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
        theInt, ((char*)&theInt)[0], ((char*)&theInt)[1], ((char*)&theInt)[2], ((char*)&theInt)[3]);


    printf("\n====================\n");

    union Coins change;
    for(int i = 0; i < sizeof(change) / sizeof(int); ++i) {
        scanf("%i", change.coins + i); // BAD code! input is always suspect!
    }

    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
        change.quarter, change.dime, change.nickel, change.penny);
}

