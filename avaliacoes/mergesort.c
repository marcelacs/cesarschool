#include<stdio.h>
#include<time.h>

void merge(int arr[],int plist,int j1,int slist,int size){

	int temp[size];	
	int i=plist,j=slist,k=0;
	
	while(i<=j1 && j<=size){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
    }
		else{
			temp[k++]=arr[j++];
    }
	}
	
	while(i<=j1){	
		temp[k++]=arr[i++];
  }
		
	while(j<=size){
		temp[k++]=arr[j++];
  }
  
	for(i=plist,j=0;i<=size;i++,j++){
		arr[i]=temp[j];
  }

}
 
void mergesort(int arr[],int i,int j){
	int mid;
		
	if(i<j)
	{
		mid=(i+j)/2;

		mergesort(arr,i,mid);

		mergesort(arr,mid+1,j);	

		merge(arr,i,mid,mid+1,j);
	}
}
 
int main(){

	int a[]={1,34,1234,23,23,23,123,5312,4,123,53,2412,35,132,574567,87,68569,456,123,1};
	int n = sizeof(a)/sizeof(a[0]);

  double start = clock();
	mergesort(a,0,n-1);
  double stop = clock();
	for(int i=0;i<n;i++){
	  printf("%d ",a[i]);
  }
	double Tempo = (stop - start) / CLOCKS_PER_SEC;
	printf("\n");
  printf("Tempo gasto em array de tamanho %d = %g ms.", n, Tempo * 1000);
  printf("\n");
	return 0;
}