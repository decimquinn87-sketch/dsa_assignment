#include <stdio.h>
#include <stdlib.h>

#define N 10

struct V {
    char n;
    int v;
};

int mat[N][N];
struct V* g[N];

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = 0;
        }
    }
}

void conn(int s, int e) {
    mat[s][e] = 1;
    mat[e][s] = 1;
}

void dfs(int c) {
    printf("%c ", g[c]->n);
    g[c]->v = 1;

    for (int i = 0; i < N; i++) {
        if (mat[c][i] == 1 && !g[i]->v) {
            dfs(i);
        }
    }
}

void bfs(int s) {
    int q[N];
    int f = 0, r = 0;

    g[s]->v = 1;
    printf("%c ", g[s]->n);
    q[r++] = s;

    while (f < r) {
        int c = q[f++];
        for (int i = 0; i < N; i++) {
            if (mat[c][i] == 1 && !g[i]->v) {
                printf("%c ", g[i]->n);
                g[i]->v = 1;
                q[r++] = i;
            }
        }
    }
}

void clr() {
    for (int i = 0; i < N; i++) g[i]->v = 0;
}

int main() {
    init();

    for (int i = 0; i < N; i++) {
    g[i] = (struct V*)malloc(sizeof(struct V));
    g[i]->n = 'A' + i;
    g[i]->v = 0;
    }

    conn(0, 1); conn(0, 2); 
    conn(1, 3); 
    conn(2, 4); 
    conn(3, 5); 

    printf("Depth First Search: ");
    dfs(0); 

    clr();
    printf("Breadth First Search: ");
    bfs(0);
    printf("finished");
    return 0;
}