#include<stdio.h>
int partitionArray(int input[], int start, int end) {
	int pivot=input[start];
	int low=start,high=end;
	while(low<high){
          while (input[low] <= pivot && low < end) {
            low++;
          }
		  while (input[high] > pivot && high> start) {
            high--;
          }
		  if(low<high){
            int t=input[high];
            input[high]=input[low];
            input[low]=t;
            }
        }
        int t=input[high];
        input[high]=input[start];
        input[start]=t;
		return high;
}

void quickSort(int input[], int start, int end) {
	if(start<end){
		int pid=partitionArray(input,start, end);
		quickSort(input,start,pid-1);
		quickSort(input,pid+1,end);
	}
}
int main(){
    printf("Enter the size of list \n");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        int t;
        printf("Enter the element : ");
        scanf("%d",&t);
        arr[i]=t;
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]); 
    } 
}