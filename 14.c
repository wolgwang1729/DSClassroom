#include<stdio.h>
#define size 30
void swap(int a[],int i,int j){
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}
void insert(int a[],int*s,int v){
    int n=*s;
    a[n]=v;
    n=n+1;
    *s=n;
    int i=n-1;
    int parentid=(i-1)/2;
    while(parentid>=0&&(a[parentid])<a[i]){
        swap(a,parentid,i);
        i=parentid;
        parentid=(i-1)/2;
    }
}
int delete(int a[],int* s){
    int x=a[0];
    *s=*s-1;
    a[0]=a[*s];
    int i=0;
    while(1){
        int left=2*i+1;
        int right=2*i+2;
        int li=i;
        if(left<*s&&a[left]>a[li]){
            li=left;
        }
        if(right<*s&&a[right]>a[li]){
            li=right;
        }
        if(li!=i){
            swap(a,i,li);
            i=li;
        }
        else{
            break;
        }
    }
    return x;
}
void display(int a[], int s){
    printf("Priority queue: ");
    for(int i = 0; i < s; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void menu_insert(int a[],int* s){
    printf("Enter the value to be inserted : ");
    int v;
    scanf("%d",&v);
    insert(a,s,v);
}
void menu_delete(int a[],int* s){
    if(*s>0){
        int v=delete(a,s);
        printf("%d has been deleted \n",v);
    }
    else{
        printf("Priority queue is empty. No value has been deleted.\n");
    }
}
int main(){
    int a[size];
    int s=0;
    while(1){
    printf("Menu : \n");
    printf("1) Insert into priority queue \n2) Delete from priority queue \n3) Display queue \n4) Exit \n");
    printf("Enter the Choice \n\n");
    int x;
    scanf("%d",&x);
    if(x==1){
        menu_insert(a,&s);
    }
    else if(x==2){
        menu_delete(a,&s);
    }
    else if(x==3){
        display(a, s);
    }
    else{
        break;
    }
    }
}