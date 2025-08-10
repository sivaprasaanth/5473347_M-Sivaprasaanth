void plusMinus(int arr_count, int* arr)
 {
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < arr_count; i++) {
        if (arr[i] > 0)
            a++;
        else if (arr[i] < 0)
            b++;
        else
            c++;
    }

    printf("%.6f\n", (float)a / arr_count);
    printf("%.6f\n", (float)b / arr_count);
    printf("%.6f\n", (float)c / arr_count);

}