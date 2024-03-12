#include<stdio.h>
void shell_sort(int n, int arr[]){
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]); 
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
    shell_sort(n,arr);
}