#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap (int* x, int* y){
	int temp = *x;
	*x =*y;
	*y = temp;
}


int left(int i){

	return(2*i+1);
}

int right (int i){

	return(2*i+2);
}

int parent(int i){

	return((i-1)/2);
}

struct heap {

	int capacity;
	int heap_size;
	int* harr;
};


struct heap create_heap(int cap){

	int* harr = malloc(sizeof(int)*cap);
	struct heap h = {cap, 0, harr};
	return h;
}

int getmin (struct heap* h){

	return(h->harr[0]);
}

void insert(struct heap* h, int val){
	if(h-> heap_size == h->capacity){
		return;
	}

	int i = h-> heap_size;
	h->harr[h->heap_size] = val;
	h->heap_size++;
	

	while(i!=0 && h->harr[parent(i)] > h->harr[i] ){
		swap(&h->harr[i], &h->harr[parent(i)]);
		i = parent(i);	
	}
}

void decreaseKey(struct heap* h, int i, int new_val){

	h->harr[i] = new_val;
	while(i!=0 && h->harr[parent(i)] > h->harr[i]){
		swap(&h->harr[i], &h->harr[parent(i)]);
		i = parent(i);

	}
}

void minHeapify(struct heap* h, int i){
	int l = left(i);
	int r = right(i);
	int menor = i;
	if(l< h->heap_size && h->harr[l]< h->harr[menor]){
		menor = l;
	}
	if (r< h->heap_size && h->harr[r] < h->harr[menor]){
		menor = r;
	}
	if (menor != i) {
		swap(&h->harr[i], &h->harr[menor]);
		minHeapify(h,menor);
	}
	
}

int popMin(struct heap* h){

	if (h->heap_size <= 0){

		return(2000000000);
	}
	else if (h->heap_size == 1){
		int val = h->harr[0];
		h->harr[0] = -1;
		h->heap_size--;
		return val;
	}
	
		int var = h->harr[0];
		h->harr[0] = h->harr[h->heap_size-1];
		h->harr[h->heap_size-1] = -1;
		h->heap_size--;
		minHeapify(h,0);
		return var;
	
}

int* heapsort(struct heap* h){
	int i = 0;
	int* arr = malloc(sizeof(int) *h->heap_size);
	while(h->heap_size>0){
		arr[i++] = h->harr[0];
		popMin(h);
	}
	return arr;
}

int main(){

	int capacity = 50000, j, x,i, y;
	struct heap h = create_heap(capacity);
	int arr[] = {26 ,13021 ,36843 ,33627 ,22348 ,10244 ,12683 ,26939 ,39901 ,38841 ,9413 ,28563 ,3540,2 ,13021 ,368943 ,336627 ,223948 ,102448 ,126383 ,26939 ,39901 ,38841 ,9413 ,284563 ,354043 ,20660 ,111180 ,23622 ,900 ,2433 ,27460 ,3543 ,43 ,302 ,388 ,28340 ,115 ,37 ,272 ,19};
	int size =  sizeof(arr)/sizeof(arr[0]);

	for (x=0; x< capacity; x++){
		h.harr[x] = -1;
	}

	for(y =0; y<size; y++){
		insert(&h, arr[y]);
	}

printf("\n");
	double start = clock();
	int* a = heapsort(&h);
   double stop = clock();
	for(i=0; i< size;i++){
		printf("%d ", a[i]);
	}

    double Tempo = (stop - start) / CLOCKS_PER_SEC;
	printf("\n");
    printf("Tempo gasto em array de tamanho %d: %g ms.", size, Tempo * 1000);
	free(h.harr);
	return 0;
	}