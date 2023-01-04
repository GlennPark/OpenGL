#include <stdio.h>
__global__ void kernel()
{
}



int main(int argc, char** argv)
{
	kernel<<<1,1>>>();

	printf("Hello Cuda! \n");
	printf("Cuda Error : %s\n", cudaGetErrorString(cudaGetLastError()));

	return 0;
}


