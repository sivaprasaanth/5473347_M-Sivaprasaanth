void miniMaxSum(int arr_count, int* arr) 
{
    long sum = 0;
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < arr_count; i++) 
    {
        int val = arr[i];
        sum += val;
        if (val < min) min = val;
        if (val > max) max = val;
    }

    printf("%lld %lld\n", sum - max, sum - min);

}