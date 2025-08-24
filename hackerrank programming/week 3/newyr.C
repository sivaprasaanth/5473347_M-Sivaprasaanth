int main()
{
    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));

        char** q_temp = split_string(rtrim(readline()));

        int* q = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            int q_item = parse_int(*(q_temp + i));

            *(q + i) = q_item;
        }

        minimumBribes(n, q);
    }

    return 0;
}