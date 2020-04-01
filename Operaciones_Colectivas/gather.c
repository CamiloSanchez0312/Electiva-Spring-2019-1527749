//Juan Camilo Sánchez Barreiro - 1527749
//implementación de la función MPI_Gather usando MPI_Send y MPI_Recv
#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int size, rank, src=0, dest, tag=1, outmsg = 1, inmsg;
	MPI_Status Stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int array[size-1];

	//al proceso i se le manda el entero i 
	for(int i = 0; i<size-1;i++){
		array[i]=i+1;
	}
	
	if(rank == 0){
		for(int i = 0; i < size; i++){
			if(rank != i){ 
				MPI_Recv(&inmsg, 1, MPI_INT, i, tag, MPI_COMM_WORLD, &Stat);
				printf("Proceso %d recibió el entero %d del proceso %d\n", rank, inmsg, Stat.MPI_SOURCE);
			}
		}
	}else{
		MPI_Send(&array[rank-1], 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
	}
	MPI_Finalize();
}
