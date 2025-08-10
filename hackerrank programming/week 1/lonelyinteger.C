int lonelyinteger(int size, int* array)
{
    int unique = 0;

    for (int i = 0; i < size; i++) 
    {
        unique = unique ^ array[i]; 
    }

    return unique;

}
