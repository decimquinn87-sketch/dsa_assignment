#include <stdio.h>
#include <stdlib.h>

struct qwe {
    int ret;
    struct qwe *yui;
    struct qwe *iop;
};

struct qwe *asd(int fgh) {
    struct qwe *jkl = (struct qwe *)malloc(sizeof(struct qwe));
    jkl->ret = fgh;
    jkl->yui = NULL;
    jkl->iop = NULL;
    return jkl;
}

struct qwe *zxc(struct qwe *vbn, int mqw, int ert) {
    struct qwe *tyu = vbn;

    while (tyu != NULL) {
        if (tyu->ret == mqw)
            break;
        tyu = tyu->yui;
    }

    if (tyu == NULL)
        return vbn;

    struct qwe *iop_node = asd(ert);
    iop_node->iop = tyu;
    iop_node->yui = tyu->yui;
    tyu->yui = iop_node;

    if (iop_node->yui != NULL)
        iop_node->yui->iop = iop_node;

    return vbn;
}

void uio(struct qwe **pas, int dfg) {
    struct qwe *hjk = *pas;

    while (hjk != NULL && hjk->ret != dfg) {
        hjk = hjk->yui;
    }

    if (hjk == NULL) return;

    if (*pas == hjk) {
        *pas = hjk->yui;
    }

    if (hjk->yui != NULL) {
        hjk->yui->iop = hjk->iop;
    }

    if (hjk->iop != NULL) {
        hjk->iop->yui = hjk->yui;
    }

    free(hjk);
}

void lzx(struct qwe *cvb) {
    struct qwe *nmq = cvb;
    while (nmq != NULL) {
        printf(" %d", nmq->ret);
        nmq = nmq->yui;
    }
    printf("\n");
}

int main() {
    struct qwe *wer = asd(1);
    wer->yui = asd(3);
    wer->yui->iop = wer;
    wer->yui->yui = asd(4);
    wer->yui->yui->iop = wer->yui;

    printf("Original Linked List:");
    lzx(wer);

    printf("Inserting Node 2 after 1:");
    wer = zxc(wer, 1, 2);
    lzx(wer);

    printf("Deleting Node 3:");
    uio(&wer, 3);
    lzx(wer);

    return 0;
}