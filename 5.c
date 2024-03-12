#include <stdio.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
int binary_search(int arr[], int low, int high, int target)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binary_search(arr, low, mid - 1, target);
        return binary_search(arr, mid + 1, high, target);
    }
    return -1;
}

void insert_element(int n, int *i, int arr[])
{
    if ((*i) < n)
    {
        int el;
        printf("Enter element to be inserted\n");
        scanf("%d", &el);
        int j;
        for (j = (*i) - 1; j >= 0 && arr[j] > el; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = el;
        (*i)++;
    }
    else
    {
        printf("List is already full\n");
    }
}
void delete_element(int n, int *i, int arr[])
{
    int el, id;
    printf("Enter the element to be deleted\n");
    scanf("%d", &el);
    id = binary_search(arr, 0, *i, el);
    if (id != -1)
    {
        for (int x = id + 1; x < n; x++)
        {
            arr[x - 1] = arr[x];
        }
        (*i) = (*i) - 1;
    }
}
void search_element(int n, int *i, int arr[])
{
    int el, id;
    printf("Enter the element to be searched\n");
    scanf("%d", &el);
    id = binary_search(arr, 0, *i, el);
    printf("%d\n", id);
}
void update_element(int n, int *i, int arr[])
{
    int x, y, id;
    printf("Enter the new element and the element with which it has to be replaced\n");
    scanf("%d %d", &x, &y);
    id = binary_search(arr, 0, *i, y);
    if (id != -1)
    {
        for (int xk = id + 1; xk < n; xk++)
        {
            arr[xk - 1] = arr[xk];
        }
        (*i) = (*i) - 1;
    }
    int j;
        for (j = (*i) - 1; j >= 0 && arr[j] > x; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = x;
        (*i)++;
    
    // id = binary_search(arr, 0, *i, y);
    // arr[id] = x;
    // quicksort(arr, 0, *i);
}
void display_list(int n, int arr[])
{
    for (int x = 0; x < n; x++)
    {
        printf("%d ", arr[x]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the size of list \n");
    int n;
    scanf("%d", &n);
    int arr[n];
    int i = 0;
    while (1)
    {
        printf("Menu : \n");
        printf("1) Insert \n2) Delete \n3) Search \n4) Update a value with another value\n5) Display List \n6) Exit \n");
        printf("Enter the Choice \n\n");
        int a;
        scanf("%d", &a);
        if (a == 1)
        {
            insert_element(n, &i, arr);
        }
        else if (a == 2)
        {
            delete_element(n, &i, arr);
        }
        else if (a == 3)
        {
            search_element(n, &i, arr);
        }
        else if (a == 4)
        {
            update_element(n, &i, arr);
        }
        else if (a == 5)
        {
            display_list(n, arr);
        }
        else
        {
            break;
        }
    }
}