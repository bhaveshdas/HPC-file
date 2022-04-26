// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h> //Header file for sleep(). man 3 sleep for details.
// #include <pthread.h>

// void *myThreadFun(int a, int b)
// {
//     int c;
//     c = a+b;
// 	printf("Answer: %d \n",c);
// 	return NULL;
// }

// int main(void)
// {
// 	pthread_t thread_id1,thread_id2;
// 	printf("Before Thread\n");
// 	int err = pthread_create(&thread_id1, NULL, myThreadFun(9,4), NULL);
//     int err2 = pthread_create(&thread_id2, NULL, myThreadFun(90,6), NULL);
//     if(err){
//         printf("error cannot make thread");
//     }

//     else
// 	{   pthread_join(thread_id1, NULL);
//         pthread_join(thread_id2, NULL);
// 	    printf("After Thread\n");
//     }
// 	exit(0);
// }
#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv) {
// Initialize the MPI environment
MPI_Init(NULL, NULL);
// Get the number of processes
int world_size;
MPI_Comm_size(MPI_COMM_WORLD, &world_size);
// Get the rank of the process
int world_rank;
MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
// Get the name of the processor
char processor_name[MPI_MAX_PROCESSOR_NAME];
int name_len;
MPI_Get_processor_name(processor_name, &name_len);
// Print off a hello world message
printf("Hello world from processor %s, rank %d out of %d processors\n",
processor_name, world_rank, world_size);
// Finalize the MPI environment.
MPI_Finalize();
}