#include <stdio.h>
#include <stdlib.h>
// Euler's number 2.7 182818 284590 452353 602874 713526 6249775724709369995

// 50             2.7 182818 284590 455348 848081 484903

//64              2.7 182818 284590 455348 848081 484903

//33     (recursive)         2.7 182818 324523 116970 681257 953402
int main(int argc, char *argv[])

{
    int i = 0;
    double acc = 0;

    /*long int factorial(int a)
    {
     if (a==1)  return a;
     if (a==0)  return 1; 
     int sum=0;
     sum+=(a * factorial(a-1));
     return sum;
    }
*/
    long int factorial(int a)
    {
        long int sum = 1;

        for (int i = a; i > 0; i--)
        {
            sum *= i;
        }
        //printf(" sum is : %.15ld\n",sum);
        return sum;
    }
    //  printf(" Euler's number is : %ld\n",factorial(i));
    //  printf(" Euler's number is : %f\n",1.0/factorial(i));

    while (i < 65)
    {
        acc += (1.0 / factorial(i));
        i += 1;

    }

    printf(" acc is : %.16f\n", acc);
}
