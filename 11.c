#include<stdio.h>
#define size 30
struct queue{
    int a[size];
    int front;
    int rear;
};
void initalise(struct queue* q){
    q->front=0;
    q->rear=0;
}
int isfull(struct queue* q){
    if((q->rear+1)%size==q->front){
        return 1;
    }
    return 0;
}
int isempty(struct queue* q){
    if(q->rear==q->front){
        return 1;
    }
    return 0;
}
void insert(struct queue* q,int x){
    q->a[q->rear]=x;
    q->rear=(q->rear+1)%size;
}
int delete(struct queue* q){
    int x=q->a[q->front];
    q->front=(q->front+1)%size;
    return x;
}
void display(struct queue q){
    for(int i=q.front;i<q.rear;i++){
        printf("%d ",q.a[i]);
    }
    printf("\n");
}
void menu_insert(struct queue* Q){
    printf("Enter the value to be inserted : ");
    int v;
    scanf("%d",&v);
    if(!isfull(Q)){
        insert(Q,v);
    }
}
void menu_delete(struct queue* Q){
    if(!isempty(Q)){
        int v=delete(Q);
        printf("%d has been deleted \n",v);
    }
    else{
        printf("Queue is empty. No value has been deleted.\n");
    }
}
int main(){
    struct queue Q;
    initalise(&Q);
    while(1){
    printf("Menu : \n");
    printf("1) Insert into queue \n2) Delete from queue \n3) Display queue \n4) Exit \n");
    printf("Enter the Choice \n\n");
    int x;
    scanf("%d",&x);
    if(x==1){
        menu_insert(&Q);
    }
    else if(x==2){
        menu_delete(&Q);
    }
    else if(x==3){
        display(Q);
    }
    else{
        break;
    }
    }
}