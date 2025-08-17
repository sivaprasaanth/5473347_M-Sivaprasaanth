int cmp(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

int maxMin(int k, int arr_count, int* arr) 
{
    qsort(arr, arr_count, sizeof(int), cmp);
    int min_unfairness = INT_MAX;
    for (int i = 0; i <= arr_count - k; i++)
    {
        int unfairness = arr[i + k - 1] - arr[i];
        if (unfairness < min_unfairness) 
        {
            min_unfairness = unfairness;
        }
    }
    return min_unfairness;
}