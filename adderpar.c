#include <stdio.h>
#include <mpi.h>
#include <time.h>

 int factorial(int a)
    {
         int sum = 1;
        
        for (int i = a; i > 0; i--)
        {
            
            sum *= i;
        }
        //printf(" sum is : %.15ld\n",sum);
        return sum;
    }
int main( int argc, char ** argv )
{
	/* Definition of variables */
	int id, nproc;					
	int startval, endval;
    double sum , accum;
	double s_time, e_time;
	MPI_Status status;

	/* MPI Initialization */
	MPI_Init( &argc, &argv );

	/* Query the number of all threads */
	MPI_Comm_size( MPI_COMM_WORLD, &nproc );
	/* Query the id of this thread */
	MPI_Comm_rank( MPI_COMM_WORLD, &id );
	
	sum = 0;
	/* Calculate the boundaries of iteration for this thread */
	startval = 20 * id / nproc + 1; //
	endval = 20 * ( id + 1 ) / nproc;

	//s_time=MPI_Wtime(); // we get a time value at this point

	/* Loop within the boundaries and sum up the values */
	for ( int i = startval; i <= endval; i++ )
		{
            // a problem with iteration zero which does not exist here
            sum = sum + (double)1.0/factorial(i);
            if (i==1) sum++;// compenatse for zero 
             printf("***This is iteration %d*****\n", i);}
	
	//printf("This is node %d\n", id);
	//printf("; the partial sum is: %f\n", sum);
	
	if ( id != 0 )	
		/* If this is a worker thread */
		/* send the partial sum to the master */	
		MPI_Send( &sum, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD );
	else
	{
		/* If this is the master thread */
		/* receive the partial sums from workers in accum */
		/* and add it to sum */	
		for ( int j = 1; j < nproc; j++ )
		{
			MPI_Recv( &accum, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status );
			sum = sum + accum;
			printf("The sum so far is: %f\n", sum);
            printf("Received value: %.15f\n", accum);
		}
		//e_time=MPI_Wtime();
		//printf("Time elapsed during calculation: %f\n", e_time-s_time);


		printf("The total sum is: %.15f\n", sum);
	}
	

	MPI_Finalize();
	
	return 0;
}
