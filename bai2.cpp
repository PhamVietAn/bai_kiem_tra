#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    int id;
    char name[101], dob[11];
    float score1, score2, score3, total;
} Candidate;

void sortCandidates(Candidate candidates[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (candidates[i].id > candidates[j].id) {
                Candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Nhap so thi sinh: ");
    scanf("%d", &n);
    getchar();
    Candidate candidates[MAX];
    float maxScore = 0.0;
    for (int i = 0; i < n; i++) {
        candidates[i].id = i + 1;
        printf("Nhap ten thi sinh %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0';

        printf("Nhap ngay sinh: ");
        fgets(candidates[i].dob, sizeof(candidates[i].dob), stdin);
        candidates[i].dob[strcspn(candidates[i].dob, "\n")] = '\0';

        printf("Nhap diem 3 m0n: ");
        scanf("%f %f %f", &candidates[i].score1, &candidates[i].score2, &candidates[i].score3);
        getchar();

        candidates[i].total = candidates[i].score1 + candidates[i].score2 + candidates[i].score3;

        if (candidates[i].total > maxScore) {
            maxScore = candidates[i].total;
        }
    }
    sortCandidates(candidates, n);
    printf("\nDanh sach thu khoa:\n");
    for (int i = 0; i < n; i++) {
        if (candidates[i].total == maxScore) {
            printf("%d %s %s %.1f\n", candidates[i].id, candidates[i].name, candidates[i].dob, candidates[i].total);
        }
    }

    return 0;
}

