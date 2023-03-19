#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value: %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[4]; //point to the 5th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

    intpointer -= 2; //now shift by two the point's address so it points to the 3rd element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 3rd element

    return 0;
}
