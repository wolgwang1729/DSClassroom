#include<stdio.h>
struct sparse{
    int rno;
    int cno;
    int value;
};
void ReadSparseMatrix(struct sparse s[]){
    int s1,s2;
    printf("Enter the dimension of the matrix: \n");
    scanf("%d %d",&s1,&s2);
    int arr[s1][s2];
    printf("Enter entries of matrix:  \n");
    for(int i=0;i<s1;i++){
        for(int j=0;j<s2;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    s[0].rno=s1;
    s[0].cno=s2;
    int nz=0,k=1;

    for(int i=0;i<s1;i++){
        for(int j=0;j<s2;j++){
            if(arr[i][j]!=0){
                s[k].rno=i;
                s[k].cno=j;
                s[k].value=arr[i][j];
                nz++;
                k++;
            }
        }
    }
    s[0].value=nz;
}
void PrintSparseMatrix(struct sparse s[]){
    int s1=s[0].rno;
    int s2=s[0].cno;
    int k=1;
    for(int i=0;i<s1;i++){
        for(int j=0;j<s2;j++){
            if(i==s[k].rno&&j==s[k].cno){
                printf("%d ",s[k].value);
                k++;
            }
            else{
                printf("%d ",0);
            }
        }
        printf("\n");
    }
}
void TransposeSparseMatrix(struct sparse s1[],struct sparse s2[]){
        int a=s1[0].rno;
        int b=s1[0].cno;
        s2[0].rno=b;
        s2[0].cno=a;
        s2[0].value = s1[0].value;
        int c[a];
        int m[b];
        for(int i=0;i<a;i++){
            c[i]=0;
        }
        for(int i=0;i<=s1[0].value;i++){
            c[s1[i].cno]++;
        }
        m[0]=1;
        for(int i=1;i<b;i++){
            m[i]=m[i-1]+c[i-1];
        }
        for(int i=1;i<=s1[0].value;i++){
            int j=m[s1[i].cno];
            s2[j].rno=s1[i].cno;
            s2[j].cno=s1[i].rno;
            s2[j].value=s1[i].value;
            m[s1[i].cno]++;
        }
}

void MultiplyHelper (struct sparse s1[], struct sparse t[], struct sparse s3[], int row, int* ptr, int* i1)
{
    int numbers[t[0].rno];
    for (int i = 0; i < t[0].rno; i++)
    {
        numbers[i] = 0;
    }
    int i = *i1;
    while (i <= s1[0].value && s1[i].rno == row)
    {
        int j = 1;
        while (j <= t[0].value)
        {
            if(s1[i].rno == row && s1[i].cno == t[j].cno) numbers[t[j].rno] += (s1[i].value * t[j].value);
            j++;
        }
        i++;
    }
    *i1 = i;
    int index = *ptr;
    for (int i = 0; i < t[0].rno; i++)
    {
        if(numbers[i])
        {
            s3[index].rno = row;
            s3[index].cno = i;
            s3[index].value = numbers[i];
            index++;
        }
    }
    *ptr = index;
}

void MultiplySparseMatrix (struct sparse s1[], struct sparse s2[], struct sparse s3[])
{
    if(s1[0].cno == s2[0].rno)
    {
        struct sparse t[30];
        TransposeSparseMatrix(s2, t);
        s3[0].rno = s1[0].rno; 
        s3[0].cno = t[0].rno;
        int k = 1; int i1 = 1;
        for (int i = 0; i < s1[0].rno; i++)
        {
            MultiplyHelper(s1, t, s3, i, &k, &i1); 
        }
        s3[0].value = k-1; 
        printf("Result Matrix\n");
        PrintSparseMatrix(s3);
    }
    else 
    {
        printf("Dimensions of matrices are not compatible. \n");
    }
}

int main(){
    struct sparse sparsemat1[30],sparsemat2[30],sparsemat3[30];
    while(1){
    printf("Menu : \n");
    printf("1) Form a sparse Matrix from normal Matrix \n2) Print normal matrix from sparse matrix \n3) Multply two sparse matrix \n4) Exit \n");
    printf("Enter the Choice \n\n");
    int x;
    scanf("%d",&x);
    if(x==1){
        ReadSparseMatrix(sparsemat1);
        ReadSparseMatrix(sparsemat2);
    }
    else if(x==2){
        PrintSparseMatrix(sparsemat1);
        printf("\n");
        PrintSparseMatrix(sparsemat2);
    }
    else if(x==3){
        MultiplySparseMatrix(sparsemat1,sparsemat2,sparsemat3);
    }
    else{
        break;
    }
    }
}