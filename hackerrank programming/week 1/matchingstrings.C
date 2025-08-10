int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) 
{
    int* result = malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++)
     {
        int match = 0;

        for (int j = 0; j < strings_count; j++) 
        {
            if (strcmp(queries[i], strings[j]) == 0) 
            {
                match++;
            }
        }

        result[i] = match;
     }

        *result_count = queries_count;
        return result;
    

}
