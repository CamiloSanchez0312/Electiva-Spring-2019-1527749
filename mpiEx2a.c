#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]){
	int  rank, size;
	
	MPI_Init(&argc, &argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if (rank == 0){
		printf("Yo soy el maestro y existen: %d procesos\n",rank, size);
	}else{
		printf("Yo soy un proceso con identificador %d de %d procesos\n", rank, size);
	}
		
	MPI_Finalize(); 
	
	return 0;
}


