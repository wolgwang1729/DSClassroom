#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left,*right;
};
int search(struct node *root,int x){
    if(root==NULL){
        return(0);
    }
    struct node*p=root;
    while(p!=NULL){
        if(p->data==x){
            return(1);
        }
        if(x<p->data){
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    return(0);
}
void displayinorder(struct node* root){
    if(root==NULL){
        return;
    }
    displayinorder(root->left);
    printf("%d ",root->data);
    displayinorder(root->right);
}
void displaypostorder(struct node* root){
    if(root==NULL){
        return;
    }
    displaypostorder(root->left);
    displaypostorder(root->right);
    printf("%d ",root->data);
}
void displaypreorder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    displaypreorder(root->left);
    displaypreorder(root->right);
}
void insert(struct node** root,int x){
    struct node*q;
    q=(struct node*)malloc(sizeof(struct node));
    q->data=x;
    q->left=NULL;
    q->right=NULL;
    if(*root==NULL){
        *root=q;
        return;
    }
    struct node*p=*root;
    while(p!=NULL){
        if(x<p->data){
            if(p->left!=NULL){
                p=p->left;
            }
            else{
                break;
            }
        }
        else{
            if(p->right!=NULL){
                p=p->right;
            }
            else{
                break;
            }
        }
    }
    if(x<p->data){
        p->left=q;
    }
    else{
        p->right=q;
    }
}
int largest(struct node* r){
    int x;
    struct node*p=r;
    while(p!=NULL){
        x=p->data;
        p=p->right;
    }
    return x;
}
struct node* delete(struct node *root,int x){
    if(root=NULL){
        return(NULL);
    }
    struct node* p,*q;
    p=root;
    q=NULL;
    while(p!=NULL){
        if(x<p->data){
            q=p;
            p=p->left;
        }
        else if(x>p->data){
            q=p;
            p=p->right;
        }
        else{
            break;
        }
    }
    if(p==NULL){
        return;
    }
    if(p->left==NULL&&p->right==NULL){
        if(q==NULL){
            root=NULL;
            free(p);
        }
        else{
            if(q->left==p){
                q->left=NULL;
            }
            else{
               q->right=NULL;
            }
            free(p);
        }
    }
    else if(p->left==NULL||p->right==NULL){
        struct node* r;
        if(p->left!=NULL){
            r=p->left;
        }
        else{
            r=p->right;
        }
        if(q==NULL){
            root=r;
        }
        else if(p==q->left){
            q->left=r;
        }
        else{
            q->right=r;
        }
        free(p);
    }
    else{
        int y=largest(p->left);
        p->data=y;
        p->left=delete(p->left,y);
    }
    return(root);
}
int main(){
    struct node *root;
    root=NULL;
    while(1){
    printf("Menu : \n");
    printf("1) Insert a value \n2) Delete a value \n3) Search a value \n4) Display inorder \n5) Display preorder \n6) Display postorder \n7) Exit \n");
    printf("Enter the Choice \n\n");
    int x;
    scanf("%d",&x);
    if(x==1){
        int v;
        printf("Enter the value to be inserted : ");
        scanf("%d",&v);
        insert(&root,v);
    }
    else if(x==2){
        int v;
        printf("Enter the value to be deleted : ");
        scanf("%d",&v);
        root=delete(&root,v);
    }
    else if(x==3){
        int v;
        printf("Enter the value to be searched : ");
        scanf("%d",&v);
        int found=search(root,v);
        if(found==1){
            printf("The element is present.\n");
        }
        else{
            printf("The element is not present.\n");
        }
    }
    else if(x==4){
        displayinorder(root);
        printf("\n");
    }
    else if(x==5){
        displaypreorder(root);
        printf("\n");
    }
    else if(x==6){
        displaypostorder(root);
        printf("\n");
    }
    else{
        break;
    }
    }
}