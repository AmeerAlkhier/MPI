// parallel calculation of Euler number 
// using the convergant sum representation formula 
// I wrote the sequintial program and applied the simplist loop splitting

// Euler's number is :  2.7 182818 284590 452353 602874 713526 6249775724709369995
// Euler's number using 
// the convergant series 
// representation:
// num of terms:        value:
// 10                   2.7 182815 255731922
// 11                   2.7 182818 011463845
// 12                   2.7 182818 261984929
// 13                   2.7 182818 282861686 is the best value
// 14                   2.7 182818 288037526




#include<iostream>
#include<mpi.h>
using namespace std;
int main(int argc, char ** argv){
int id, nproc;
long int accum =0;
int startval,endval;
long double  sum=0;
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD, &nproc); // get number of total nodes
MPI_Comm_rank(MPI_COMM_WORLD, &id);
// get id of mynode
sum = 0; // zero sum for accumulation
//startval = 10000*id/nproc+1;
//endval =
//10000*(id+1)/nproc;
int i;
for( i=id;i<20;i+=nproc) // loop splitting
   {    
     accum=1;
     for (int k=i;k>0;k--)  
        {
        accum = accum * k;
        }
        if (accum==0) accum=1;
    cout<<"I am the node "<<id<<" i is "<<i<<" i factorial is: "<<accum<<endl;
    }
if(id!=0)
MPI_Send(&accum,1,MPI_LONG,0,1,MPI_COMM_WORLD);
else
    for(int j=1;j<nproc;j=j+1)
    {
    //MPI_Recv(&accum,1,MPI_INT,j,1,MPI_COMM_WORLD, &status);
    MPI_Recv(&accum,1,MPI_LONG,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,
    &status);
    // we do not wait for particular slave: recieve answer from anybody
    sum = sum +(1.0/accum)  ;
    cout<<"The sum yet is: "<<sum<<endl;

    }


if(id == 0)
    {
    cout.precision(17);
    cout << "The sum is: " << sum << endl;
    }
MPI_Finalize();
}