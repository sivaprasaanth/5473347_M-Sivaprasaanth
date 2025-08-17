int superDigit(char* n, int k) 
{
    long initialSum = digitSum(n) * k;
    return superDigitCalc(initialSum);

}