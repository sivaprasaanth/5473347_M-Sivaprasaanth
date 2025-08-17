int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) 
{
    int** arr = (int**)malloc(n * sizeof(int*));
    int* sizes = (int*)calloc(n, sizeof(int));
    int* capacity = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(2 * sizeof(int));
        capacity[i] = 2;
        sizes[i] = 0;
    }

    int lastAnswer = 0;
    int* results = (int*)malloc(queries_rows * sizeof(int));
    *result_count = 0;

    for (int i = 0; i < queries_rows; i++) 
   {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) 
        {
            if (sizes[idx] == capacity[idx]) 
            {
                capacity[idx] *= 2;
                arr[idx] = (int*)realloc(arr[idx], capacity[idx] * sizeof(int));
            }
            arr[idx][sizes[idx]++] = y;
        } else if (type == 2) 
        {
            int size = sizes[idx];
            lastAnswer = arr[idx][y % size];
            results[(*result_count)++] = lastAnswer;
        }
    }

    return results;
}