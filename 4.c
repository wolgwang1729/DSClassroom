#include<stdio.h>
void insert_element(int n,int* i,int arr[]){
    if((*i)<n){
    int el;
    printf("Enter element to be inserted\n");
    scanf("%d",&el);
        arr[*i]=el;
        (*i)++;
    }
    else{
        printf("List is already full\n");
    }
}
void delete_element(int n,int* i,int arr[]){
    int el,id=-1;
    printf("Enter the element to be deleted\n");
    scanf("%d",&el);
    for(int j=0;j<n;j++){
        if(arr[j]==el){
            id=j;
            break;
        }
    }
    if(id=!-1){
    for(int x=id+1;x<n;x++){
        arr[x-1]=arr[x];
    }
    (*i)=(*i)-1;
    }
}
void search_element(int n,int arr[]){
    int el,id,f=0;
    printf("Enter the element to be searched\n");
    scanf("%d",&el);
    for(int j=0;j<n;j++){
        if(arr[j]==el){
            id=j;
            f=1;
            break;
        }
    }
    if(f==1){
    printf("%d\n",id);}
    else{
        printf("Element is not present in the list\n");
    }
}
void update_element(int n,int arr[]){
    int x,y,id;
    printf("Enter the new element and the element with which it has to be replaced\n");
    scanf("%d %d",&x,&y);
    for(int j=0;j<n;j++){
        if(arr[j]==y){
            id=j;
            break;
        }
    }
    arr[id]=x;
}
void display_list(int n,int arr[]){
    for(int x=0;x<n;x++){
        printf("%d ",arr[x]);
    }
    printf("\n");
}

int main(){
    printf("Enter the size of list \n");
    int n;
    scanf("%d",&n);
    int arr[n];
    int i=0;
    while(1){
    printf("Menu : \n");
    printf("1) Insert \n2) Delete \n3) Search \n4) Update a value with another value\n5) Display List \n6) Exit \n");
    printf("Enter the Choice \n\n");
    int a;
    scanf("%d",&a);
    if(a==1){
        insert_element(n,&i,arr);
    }
    else if(a==2){
        delete_element(n,&i,arr);
    }
    else if(a==3){
        search_element(n,arr);
    }
    else if(a==4){
        update_element(n,arr);
    }
    else if(a==5){
        display_list(n,arr);
    }
    else{
        break;
    }
    }
    
}