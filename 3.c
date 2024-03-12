#include <stdio.h>
#include <string.h>
struct students
{
    int roll;
    char name[20];
    int marks;
};
void swapStudents(struct students *a, struct students *b)
{
    struct students temp = *a;
    *a = *b;
    *b = temp;
}
int partitionArray(struct students input[], int start, int end, int f)
{
    int low = start, high = end;
    if (f == 1)
    {
        int pivot = input[start].roll;
        while (low < high)
        {
            while (input[low].roll <= pivot && low < end)
            {
                low++;
            }
            while (input[high].roll > pivot && high > start)
            {
                high--;
            }
            if (low < high)
            {
                swapStudents(&input[high], &input[low]);
            }
        }
        swapStudents(&input[high], &input[start]);
        return high;
    }
    else
    {
        char* pivot=input[low].name;
        strcpy(pivot, input[start].name);
        while (low < high)
        {
            while (input[low].name<=pivot && low < end)
            {
                low++;
            }
            while (input[high].name> pivot  &&high> start)
            {
                high--;
            }
            if (low < high)
            {
                swapStudents(&input[high], &input[low]);
            }
        }
        swapStudents(&input[high], &input[start]);
        return high;
    }
}

void quickSort(struct students input[], int start, int end, int f)
{
    if (start < end)
    {
        int pid = partitionArray(input, start, end, f);
        quickSort(input, start, pid - 1, f);
        quickSort(input, pid + 1, end, f);
    }
}

int main()
{
    printf("Enter the number of the students\n");
    int n, f;
    scanf("%d", &n);
    struct students arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the roll number, name and marks of the student : ");
        scanf("%d %s %d", &arr[i].roll, &arr[i].name, &arr[i].marks);
    }
    printf("Enter the field by which you want to sort : Enter 1 for sort by Roll no. and Enter 2 for sort by Name : ");
    scanf("%d", &f);

    quickSort(arr, 0, n, f);
    for (int i = 0; i < n; i++)
    {
        printf("Roll number: %d, Name: %s, Marks: %d\n", arr[i].roll, arr[i].name, arr[i].marks);
    }
}