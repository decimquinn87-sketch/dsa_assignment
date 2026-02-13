#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void min_h(int d[], int n, int i) {
    int s = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && d[l] < d[s]) s = l;
    if (r < n && d[r] < d[s]) s = r;

    if (s != i) {
        swap(&d[i], &d[s]);
        min_h(d, n, s);
    }
}

void make_min(int d[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_h(d, n, i);
    }
}

void max_h(int d[], int n, int i) {
    int lg = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
if (l < n && d[l] > d[lg]) lg = l;
    if (r < n && d[r] > d[lg]) lg = r;
    if (lg != i) {
        swap(&d[i], &d[lg]);
        max_h(d, n, lg);
    }
}

void make_max(int d[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
    max_h(d, n, i);
    }
}

int main() {
    int len;
    printf("Total: ");
    scanf("%d", &len);

    int a1[len], a2[len];

    printf("Values:\n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &a1[i]);
        a2[i] = a1[i];
    }

    make_min(a1, len);
    make_max(a2, len);

    printf("\nMIN_OUT:\n");
    for (int i = 0; i < len; i++) printf("%d ", a1[i]);

    printf("\n\nMAX_OUT:\n");
    for (int i = 0; i < len; i++) 
    printf("%d ", a2[i]);

    return 0;
}