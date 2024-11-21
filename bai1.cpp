#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim(char *str) {
    int n = strlen(str), j = 0, start = 0;
    while (str[start] == ' ') start++;
    for (int i = start; i < n; i++) {
        if (!(str[i] == ' ' && (j == 0 || str[j - 1] == ' '))) {
            str[j++] = str[i];
        }
    }
    if (j > 0 && str[j - 1] == ' ') j--;
    str[j] = '\0';
}

void standardizeName(char *str) {
    trim(str);
    str[0] = toupper(str[0]);
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i - 1] == ' ') {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    int testCases;
    printf("Nhap so bo test: ");
    scanf("%d", &testCases);
    getchar();

    while (testCases--) {
        char name[81];
        printf("Nhap xau ho ten: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        standardizeName(name);
        printf("Xau chuan hoa: %s\n", name);
    }
    return 0;
}

