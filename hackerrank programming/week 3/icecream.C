int* icecreamParlor(int m, int arr_count, int* arr, int* result_count) 
{
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < arr_count - 1; i++) 
    {
        for (int j = i + 1; j < arr_count; j++) 
        {
            if (arr[i] + arr[j] == m) 
            {
                result[0] = i + 1;
                result[1] = j + 1;
                *result_count = 2;
                return result;
            }
        }
    }
    *result_count = 0; 
    return result;

}