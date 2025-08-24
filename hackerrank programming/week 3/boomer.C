static char** alloc_grid(int r, int c, char fill) {
    char** g = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        g[i] = malloc(c + 1);
        for (int j = 0; j < c; j++) g[i][j] = fill;
        g[i][c] = '\0';
    }
    return g;
}
static char** copy_grid(char** src, int r, int c) {
    char** g = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        g[i] = malloc(c + 1);
        memcpy(g[i], src[i], c + 1);
    }
    return g;
}

static void punch(char** g, int r, int c, int i, int j) {
    static const int di[5] = {0, 1, -1, 0, 0};
    static const int dj[5] = {0, 0, 0, 1, -1};
    for (int k = 0; k < 5; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni >= 0 && ni < r && nj >= 0 && nj < c) g[ni][nj] = '.';
    }
}
static char** detonate(char** src, int r, int c) {
    char** out = alloc_grid(r, c, 'O');
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (src[i][j] == 'O') punch(out, r, c, i, j);
    return out;
}

char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
    int r = grid_count;
    int c = strlen(grid[0]);
    *result_count = r;
    if (n == 1) return copy_grid(grid, r, c);
    if (n % 2 == 0) return alloc_grid(r, c, 'O');
    char** g3 = detonate(grid, r, c);
    if (n % 4 == 3) return g3;
    char** g5 = detonate(g3, r, c);
    return g5;
    

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int r = parse_int(*(first_multiple_input + 0));

    int c = parse_int(*(first_multiple_input + 1));

    int n = parse_int(*(first_multiple_input + 2));

    char** grid = malloc(r * sizeof(char*));

    for (int i = 0; i < r; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    int result_count;
    char** result = bomberMan(n, r, grid, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}
