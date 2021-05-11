// parallel calculation of a sum
// from 1 to 10000
// by loop splitting
#include<iostream>
#include<mpi.h>
using namespace std;
int main(int argc, char ** argv){
int id, nproc;
long int sum,accum;
int startval,endval;
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD, &nproc); // get number of total nodes
MPI_Comm_rank(MPI_COMM_WORLD, &id);
// get id of mynode
sum = 1; // zero sum for accumulation
//startval = 10000*id/nproc+1;
//endval =
//10000*(id+1)/nproc;
int i;
for( i=1+id;i<=15;i+=nproc) // loop splitting
   {    
     for (int j=i;j>0;j--)  
        sum = sum * j;
       
    cout<<"I am the node "<<id<<" i is "<<i<<" factorial for i is: "<<sum<<endl;
    }
if(id!=0)
MPI_Send(&sum,1,MPI_INT,0,1,MPI_COMM_WORLD);
else
for(int j=1;j<nproc;j=j+1){
    //MPI_Recv(&accum,1,MPI_INT,j,1,MPI_COMM_WORLD, &status);
    MPI_Recv(&sum,1,MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,
    &status);
    // we do not wait for particular slave: recieve answer from anybody
    accum = sum + accum;
    cout<<"The sum yet is: "<<accum<<endl;

}
if(id == 0)
cout << "The sum is: " << accum << endl;
MPI_Finalize();
}