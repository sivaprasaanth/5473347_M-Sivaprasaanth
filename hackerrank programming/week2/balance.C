char* balancedSums(int arr_count, int* arr)
{
    static char yes[] = "YES";
    static char no[] = "NO";
    long total = 0, left = 0;
    for (int i = 0; i < arr_count; i++) total += arr[i];
    for (int i = 0; i < arr_count; i++) 
    {
        long right = total - left - arr[i];
        if (left == right) return yes;
        left += arr[i];
    }
    return no;
}