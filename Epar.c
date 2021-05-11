#include <stdio.h>
#include <stdlib.h>
#include<mpi.h>

int main(int argc, char *argv[])

{
    int i = 0;
    double acc = 0;
    unsigned long int sum =1;


    while (i < 50)
    {
        sum=1;


        for (int j = i; j > 0; j--)
        {
            sum =sum *j;
        }

        if (i==0) sum =1;
        printf(" i index is: %d", i);
        printf(" factorial of i is : %ld\n", sum);
        acc += (1.0 / sum);
        i += 1;

    }

    printf(" acc is : %.16f\n", acc);
}













