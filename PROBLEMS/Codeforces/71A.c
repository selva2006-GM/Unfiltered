
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char arr[n][101];

    for (int i = 0; i < n; i++) {
        scanf("%100s", arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int len = strlen(arr[i]);

        if (len > 10) {
            printf("%c%d%c\n", arr[i][0], len - 2, arr[i][len - 1]);
        } else {
            printf("%s\n", arr[i]);
        }
    }

    return 0;
}
