char* isBalanced(char* s) {
    int n = strlen(s);
    char *stack = (char*)malloc(n);
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1) {
                free(stack);
                return "NO";
            }
            char c = stack[top--];
            if ((s[i] == ')' && c != '(') ||
                (s[i] == '}' && c != '{') ||
                (s[i] == ']' && c != '[')) {
                free(stack);
                return "NO";
            }
        }
    }

    if (top == -1) {
        free(stack);
        return "YES";
    } else {
        free(stack);
        return "NO";
    }

}
