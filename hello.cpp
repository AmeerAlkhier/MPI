//Hello World! program with minimal communications
#include <iostream>
#include <mpi.h>
using namespace std;
int main (int argc, char **argv) {
int id, nproc, id_from;
MPI_Status status;
// Initialize MPI:
MPI_Init(&argc, &argv);
// Get my rank:
MPI_Comm_rank(MPI_COMM_WORLD, &id);

// Get the total number of processors:
MPI_Comm_size(MPI_COMM_WORLD, &nproc);




























if(id != 0){
// Slave processes sending greetings:
cout<<"Process id="<<id<<" sending greetings!"<<endl;
MPI_Send(&id, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
}
else{
// Master process receiving greetings:
cout<<"Master process (id=0) receving greetings"<<endl;
for(int i=1;i<nproc;++i){
MPI_Recv(&id_from, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD,
&status);
cout<<"Greetings from process "<<id_from<<"!"<<endl;
}
}
// Terminate MPI:
MPI_Finalize();
}
























//Hello World! program

/*

#include <iostream>
#include <mpi.h>
using namespace std;
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

*/