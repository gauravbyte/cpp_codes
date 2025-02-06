#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* roll_the_string(char* s, int* arr, int n) {
    int len = strlen(s);
    int* dp = (int*)malloc((len + 1) * sizeof(int));
    memset(dp, 0, (len + 1) * sizeof(int));

    for (int i = 0; i < n; i++) {
        dp[arr[i]]++;
    }

    // Suffix sum
    for (int i = len - 1; i >= 1; i--) {
        dp[i] += dp[i + 1];
    }

    char* roll = (char*)malloc((len + 1) * sizeof(char));
    roll[len] = '\0';

    for (int i = 0; i < len; i++) {
        int index = dp[i + 1] % 26;
        roll[i] = (char)(((s[i] - 'a' + index) % 26) + 'a');
    }

    free(dp);
    return roll;
}

int main() {
    char s[100];
    scanf("%s", s);

    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    char* result = roll_the_string(s, arr, n);
    printf("%s\n", result);

    free(arr);
    free(result);

    return 0;
}