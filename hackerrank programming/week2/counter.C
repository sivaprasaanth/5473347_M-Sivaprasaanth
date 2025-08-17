char* counterGame(long n)
 {
    static char winner[10];
    int turn = 0;
    while (n != 1) 
    {
        if ((n & (n - 1)) == 0)
         {
            n >>= 1;
         } else 
         {
            long p = 1;
            while (p << 1 < n) p <<= 1;
            n -= p;
         }
        turn ^= 1;
    }
    strcpy(winner, turn ? "Louise" : "Richard");
    return winner;
}