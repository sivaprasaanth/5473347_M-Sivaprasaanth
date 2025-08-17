int pageCount(int n, int p) 
{
    int fromFront = p / 2;
    int fromBack = n / 2 - p / 2;
    return fromFront < fromBack ? fromFront : fromBack;
}