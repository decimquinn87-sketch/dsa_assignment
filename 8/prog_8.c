#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int com = 0;
int swa = 0;

void bub(int arr[], int num) {
    com = swa = 0;
  for (int idx = 0; idx < num - 1; idx++) {
      for (int jdx = 0; jdx < num - idx - 1; jdx++) {
            com++;
    if (arr[jdx] > arr[jdx + 1]) {
                swa++;
            int tmp = arr[jdx];
            arr[jdx] = arr[jdx + 1];
            arr[jdx + 1] = tmp;
            }
        }
    }
}

void sel(int arr[], int num) {
    com = swa = 0;
    for (int idx = 0; idx < num - 1; idx++) {
        int min = idx;
    for (int jdx = idx + 1; jdx < num; jdx++) {
            com++;
            if (arr[jdx] < arr[min])
                min = jdx;
        }
    if (min != idx) {
            swa++;
            int tmp = arr[idx];
            arr[idx] = arr[min];
            arr[min] = tmp;
        }
    }
}

void ins(int arr[], int num) {
    com = swa = 0;
    for (int idx = 1; idx < num; idx++) {
        int key = arr[idx];
        int jdx = idx - 1;
        com++;
      while (jdx >= 0 && arr[jdx] > key) {
            com++;
            arr[jdx + 1] = arr[jdx];
            swa++;
            jdx--;
        }
        arr[jdx + 1] = key;
        swa++;
    }
}

void mrg(int arr[], int lft, int mid, int rgt) {
    int n01 = mid - lft + 1, n02 = rgt - mid;
    int Lar[n01], Rar[n02];
    for (int idx = 0; idx < n01; idx++) Lar[idx] = arr[lft + idx];
    for (int jdx = 0; jdx < n02; jdx++) Rar[jdx] = arr[mid + 1 + jdx];

    int idx = 0, jdx = 0, kdx = lft;
    while (idx < n01 && jdx < n02) {
        com++;
        if (Lar[idx] <= Rar[jdx]) {
            arr[kdx++] = Lar[idx++];
            swa++;
        } else {
            arr[kdx++] = Rar[jdx++];
            swa++;
        }
    }
    while (idx < n01) {
    arr[kdx++] = Lar[idx++];
        swa++;
    }
    while (jdx < n02) {
        arr[kdx++] = Rar[jdx++];
        swa++;
    }
}

void mst(int arr[], int lft, int rgt) {
    if (lft < rgt) {
        int mid = lft + (rgt - lft) / 2;
        mst(arr, lft, mid);
        mst(arr, mid + 1, rgt);
        mrg(arr, lft, mid, rgt);
    }
}

void prn(int arr[], int num) {
    for (int idx = 0; idx < num; idx++)
        printf("%d ", arr[idx]);
    printf("\n");
}

int main() {
    int Nvl, cho;
    printf("How many numbers we using? (N): ");
    scanf("%d", &Nvl);

    int arr[Nvl];
    srand(time(NULL));
    for (int idx = 0; idx < Nvl; idx++)
        arr[idx] = rand() % 1000 + 1;

    printf("\nHere is the messy array:\n");
    prn(arr, Nvl);

    printf("\nWhich one you wanna use?\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Pick one (1-4): ");
    scanf("%d", &cho);

    switch (cho) {
        case 1:
            bub(arr, Nvl);
            break;
        case 2:
            sel(arr, Nvl);
            break;
        case 3:
            ins(arr, Nvl);
            break;
        case 4:
            com = swa = 0;
            mst(arr, 0, Nvl - 1);
            break;
        default:
            printf("Nah, that choice doesn't work.\n");
            return 1;
    }

    printf("\nFixed it! Here is the sorted array:\n");
    prn(arr, Nvl);

    printf("\nTotal times we compared stuff: %d\n", com);
    printf("Total times we swapped stuff: %d\n", swa);

    return 0;
}