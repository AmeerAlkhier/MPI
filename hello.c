//Hello World! program
#include <stdio.h>
#include <mpi.h>
//using namespace std;
int main (int argc, char **argv) {
int id, nproc;
// Initialize MPI:
MPI_Init(&argc, &argv);
// Get my rank:
MPI_Comm_rank(MPI_COMM_WORLD, &id);
// Get the total number of processors:
MPI_Comm_size(MPI_COMM_WORLD, &nproc);
cout<<"Process "<<id<<" of "<<nproc<<": Hello World!"<<endl;
// Terminate MPI:
MPI_Finalize();
}