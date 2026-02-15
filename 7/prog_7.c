#include <stdio.h>

#define X_VAL 5
#define NO_LIMIT 9999

int find_low(int p[], int q[]) {
    int cur_low = NO_LIMIT,   low_ptr;

    for (int k = 0; k < X_VAL; k++) {
        if ( q[k] == 0  && p[k] <=  cur_low) {
            cur_low =  p[k];
            low_ptr = k;
        }
    }
    return   low_ptr;
}

void  show_out(int p[]) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < X_VAL;  i++)
        printf("%d\t%d\n", i,  p[i]);
}

void  run_proc(int m[X_VAL][X_VAL], int start) {
    int  p[X_VAL];
    int q[X_VAL];

    for (int i = 0; i <  X_VAL; i++) {
        p[i] =  NO_LIMIT;
        q[i] = 0;
    }

    p[start] =  0;

    for (int  step = 0; step < X_VAL - 1;   step++) {

        int  idx = find_low(p,  q);
        q[idx] = 1;

        for (int j = 0; j <  X_VAL; j++) {
            if (!q[j]  && m[idx][j] &&
                p[idx] !=  NO_LIMIT &&
                p[idx] + m[idx][j] <  p[j]) {

                p[j] =  p[idx] +  m[idx][j];
            }
        }
    }

    show_out(p);
}

int main() {
    int  data_grid[X_VAL][X_VAL] = {
        {0, 4, 1, 0, 0},
        {4, 0, 2, 5, 0},
        {1, 2, 0, 8, 0},
        {0, 5, 8, 0, 3},
        {0, 0, 0, 3, 0}
    };

    run_proc(   data_grid, 0);

    return  0;
}