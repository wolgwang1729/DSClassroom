#include<stdio.h>
#define size 30
void swap(int a[],int i,int j){
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}
void display(int a[], int n){
    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void heapify(int a[],int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int li=i;
    if(left<n&&a[left]>a[li]){
        li=left;
    }
    if(right<n&&a[right]>a[li]){
        li=right;
    }
    if(li!=i){
        swap(a,i,li);
        heapify(a,n,li);
    }
}
void make_heap(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
}
void delete_max(int a[],int n){
    swap(a,0,n-1);
    heapify(a,n-1,0);
}
void heap_sort(int a[],int n){
    make_heap(a,n);
    for(int i=n;i>1;i--){
        delete_max(a,i);
    }
}
void menu_insert(int a[],int* n){
    printf("Enter the number of elements in the array : ");
    scanf("%d",n);
    for(int i=0;i<*n;i++){
        printf("Enter the element : ");
        scanf("%d",&a[i]);
    }
}
int main(){
    int a[size];
    int n=0;
    while(1){
    printf("Menu : \n");
    printf("1) Insert array \n2) Display sorted array \n3) Exit \n");
    printf("Enter the Choice \n\n");
    int x;
    scanf("%d",&x);
    if(x==1){
        menu_insert(a,&n);
    }
    else if(x==2){
        heap_sort(a,n);
        display(a,n);
    }
    else{
        break;
    }
    }
}