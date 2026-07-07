#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

/*=========================================================
                MERGE SORT
=========================================================*/

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[MAX], R[MAX];

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/*=========================================================
                BINARY SEARCH
=========================================================*/

int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void displayArray(int arr[], int size)
{
    int i;

    printf("\nArray:\n");

    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
/*=========================================================
                    QUICK SORT
=========================================================*/

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for(j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*=========================================================
                ACTIVITY SELECTION
=========================================================*/

struct Activity
{
    int start;
    int finish;
};

void activitySelection(struct Activity a[], int n)
{
    int i;
    int last = 0;

    printf("\nSelected Activities:\n");
    printf("( %d , %d )\n", a[0].start, a[0].finish);

    for(i = 1; i < n; i++)
    {
        if(a[i].start >= a[last].finish)
        {
            printf("( %d , %d )\n", a[i].start, a[i].finish);
            last = i;
        }
    }
}
/*=========================================================
                0/1 KNAPSACK
=========================================================*/

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int knapsack(int capacity, int weight[], int profit[], int n)
{
    int K[50][50];
    int i, w;

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
                K[i][w] = 0;

            else if(weight[i-1] <= w)
            {
                K[i][w] = max(profit[i-1] +
                              K[i-1][w-weight[i-1]],
                              K[i-1][w]);
            }
            else
            {
                K[i][w] = K[i-1][w];
            }
        }
    }

    return K[n][capacity];
}

/*=========================================================
                    MAIN PROGRAM
=========================================================*/

int main()
{
    int choice;
    int arr[MAX];
    int n, i, key;

    struct Activity activities[6] =
    {
        {1,2},
        {3,4},
        {0,6},
        {5,7},
        {8,9},
        {5,9}
    };

    int weight[] = {2,3,4,5};
    int profit[] = {3,4,5,6};

    clock_t start, end;
    double timeTaken;

    while(1)
    {
        printf("\n==============================\n");
        printf(" ALGORITHMS & PROBLEM SOLVING\n");
        printf("==============================\n");

        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Binary Search\n");
        printf("4. Activity Selection\n");
        printf("5. 0/1 Knapsack\n");
        printf("6. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                printf("Enter Number of Elements : ");
                scanf("%d",&n);

                for(i=0;i<n;i++)
                    scanf("%d",&arr[i]);

                start = clock();

                mergeSort(arr,0,n-1);

                end = clock();

                displayArray(arr,n);

                timeTaken = ((double)(end-start))/CLOCKS_PER_SEC;

                printf("Execution Time : %lf seconds\n",timeTaken);

                break;

            case 2:

                printf("Enter Number of Elements : ");
                scanf("%d",&n);

                for(i=0;i<n;i++)
                    scanf("%d",&arr[i]);

                start = clock();

                quickSort(arr,0,n-1);

                end = clock();

                displayArray(arr,n);

                timeTaken=((double)(end-start))/CLOCKS_PER_SEC;

                printf("Execution Time : %lf seconds\n",timeTaken);

                break;

            case 3:

                printf("Enter Size of Sorted Array : ");
                scanf("%d",&n);

                for(i=0;i<n;i++)
                    scanf("%d",&arr[i]);

                printf("Enter Element to Search : ");
                scanf("%d",&key);

                i = binarySearch(arr,n,key);

                if(i==-1)
                    printf("Element Not Found.\n");
                else
                    printf("Element Found at Index %d\n",i);

                break;

            case 4:

                activitySelection(activities,6);

                break;

            case 5:

                printf("Maximum Profit : %d\n",
                       knapsack(5,weight,profit,4));

                break;

            case 6:

                printf("Program Terminated.\n");
                return 0;

            default:

                printf("Invalid Choice.\n");
        }
    }

    return 0;
}
