#include <stdio.h>
#include <time.h>


void swap (int* x, int* y){
	int temp = *x;
	*x =*y;
	*y = temp;
}

int partition(int arr[],int begin, int end){
 
 	int i = begin-1;
 	int j = begin;
 	int pivot = arr[end];

 	for (j = begin; j<= end-1; j ++){
		if (arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
 	}
 	swap(&arr[i+1], &arr[end]);
 	return i+1;
}

void quicksort(int arr[], int begin, int end){

	if (begin < end){
		int mid = partition(arr, begin, end);

		quicksort(arr, begin, mid-1);
		quicksort(arr, mid+1, end); 
	}

}



int main(){
	int i;
	int arr[] = {5,35,99973,99,241,0,7,6,5,6,6,44,3,564,359,421,7942,23,4,4,67,75,64,7,2,54350,1,3,8,74,69,30,240,86,729,573,827,154,28,61,3};
	int n = sizeof(arr)/sizeof(arr[0]);

	int begin = 0;

	int end = n-1;

   double start = clock();
   quicksort(arr, begin, end);
   double stop = clock();
   double Tempo = (stop - start) / CLOCKS_PER_SEC;

   for(i=0; i<n; i++){
   		printf("%d ", arr[i]);
   }
   printf("\n");
   printf("Tempo gasto em array de tamanho %d = %g ms.", n, Tempo * 1000);

   return 0;
}