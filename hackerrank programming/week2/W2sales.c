int sockMerchant(int n, int ar_count, int* ar)
 {
    int count[101] = {0};
    int pairs = 0;
    for (int i = 0; i < n; i++) 
    {
        count[ar[i]]++;
    }
    for (int i = 0; i <= 100; i++) 
    {
        pairs += count[i] / 2;
    }
    return pairs;

}