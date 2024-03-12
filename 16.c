#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void insert_at_beginning(struct node**s,int x){
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=*s;
    *s=p;
}
void insert_at_end(struct node**s,int x){
    struct node *p,*q;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=NULL;
    if(*s==NULL){
        *s=p;
    }
    else{
        q= *s;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
    }
}
void insertxaftery(struct node** start,int x,int y){
    struct node* q=*start;
    while(q!=NULL){
        if(q->data==y){
            break;
        }
        q=q->next;
    }
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=q->next;
    q->next=p;
}
void display(struct node* start){
    struct node* q=start;
    while(q!=NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}
struct node* search(struct node* start,int x){
    struct node* q=start;
    while(q!=NULL){
        if(q->data==x){
            return q;
        }
        q=q->next;
    }
    return NULL;
}
void deletex(struct node**s, int x){
    if(*s==NULL){
        return;
    }
    else if((*s)->data==x){
        struct node* q=*s;
        *s=(*s)->next;
        free(q);
        return;
    }
    struct node* q=*s;
    while((q->next)!=NULL&&(q->next)->data!=x){
        q=q->next;
        }
    if(q->next!=NULL){
        struct node* p=q->next;
        q->next=(q->next)->next;
        free(p);   
    }
}
void reversell(struct node**s){
    if(*s==NULL||(*s)->next==NULL){
        return;
    }
    struct node *q,*prev,*fwd;
    q=*s;
    prev=NULL;
    while(q->next!=NULL){
        fwd=q->next;
        q->next=prev;
        prev=q;
        q=fwd;
    }
    q->next=prev;
    *s=q;
}
struct node* recreversell(struct node*s){
    if(s==NULL||(s)->next==NULL){
        return s;
    }
    struct node *p;
    p=recreversell(s->next);
    (s->next)->next=s;
    s->next=NULL;
    return p;
}
int main(){
    struct node* start;
    start=(struct node*)malloc(sizeof(struct node));
    start=NULL;
    while(1){
    printf("Menu : \n");
    printf("1) Insert at beginning \n2) Insert at end \n3) Insert a value after a particular value \n4) Display linked list \n5) Search \n6) Delete a value \n7) Reverse the linked list \n8) Exit \n");
    printf("Enter the Choice \n\n");
    int x;
    scanf("%d",&x);
    if(x==1){
        int v;
        printf("Enter the value to be inserted at the beginning : ");
        scanf("%d",&v);
        insert_at_beginning(&start,v);
    }
    else if(x==2){
        int v;
        printf("Enter the value to be inserted at the end : ");
        scanf("%d",&v);
        insert_at_end(&start,v);
    }
    else if(x==3){
        int a,b;
        printf("Enter the value to be inserted and the value after which it has to be inserted : ");
        scanf("%d %d",&a,&b);
        insertxaftery(&start,a,b);
    }
    else if(x==4){
        display(start);
    }
    else if(x==5){
        int v;
        printf("Enter the value to be searched : ");
        scanf("%d",&v);
        struct node* found=search(start,v);
        if(found!=0){
            printf("The element is present at the address : %d\n",found);
        }
        else{
            printf("The element is not found.\n");
        }
    }
    else if(x==6){
        int v;
        printf("Enter the value to be deleted : ");
        scanf("%d",&v);
        deletex(&start,v);
    }
    else if(x==7){
        // reversell(&start);
        start=recreversell(start);
    }
    else{
        break;
    }
    }
}