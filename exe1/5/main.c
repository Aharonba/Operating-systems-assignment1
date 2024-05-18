#include "main.h"
#define UPPER_BOUND 74
#define LOWER_BOUND -25

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Finding maximal subarray at runtime n3
void maxSubArray1(int arr[], int n)
{
    int best = 0;
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int sum = 0;
            for (int run = start; run <= end; run++)
            {
                sum = sum + arr[run];
            }

            best = max(best, sum);
        }
    }

    printf("%d\n", best);
}
// Finding maximal subarray at runtime n2, We improved by not including every possible sub-array.
void maxSubArray2(int arr[], int n)
{
    int best = 0;
    for (int start = 0; start < n; start++)
    {
        int sum = 0;
        for (int end = start; end < n; end++)
        {
            sum = sum + arr[end];
            best = max(best, sum);
        }
    }
    printf("%d\n", best);
}
// Finding maximal subarray at runtime n
void maxSubArray3(int arr[], int n)
{
    int best = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        /*
        Checking whether the sub-array up to the i-1st position is smaller than the value in the array at the i-th position.
        If so, start a new scheme of a sub-array from the i position
        */
        sum = max(sum + arr[i], arr[i]);
        best = max(best, sum);
    }
    printf("%d\n", best);
}

int randInRange(int lower_bound, int upper_bound)
{
    return (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
}

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("Please enter 2 values only\n");
        return 1;
    }

    int s = atoi(argv[1]);
    int size = atoi(argv[2]);

    srand(s);
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = randInRange(LOWER_BOUND, UPPER_BOUND);
    }

    maxSubArray1(arr, size);
    maxSubArray2(arr, size);
    maxSubArray3(arr, size);

    return 0;
}
