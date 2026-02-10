#include <stdio.h>
#include <stdlib.h>

typedef struct node {                                                            
      int data;               
      struct node *next;      
} node;  

node *head;

int printList(node *traverse) {
    if (traverse->next == NULL) {
        return -1;
    }
    traverse = traverse->next;
    printList(traverse);
    printf("%d\n", traverse->data);
     return 0;

}

int main() {
    node *temp = NULL;
    node *begin = NULL;      
    for (int i = 0; i < 10; i++) {
        temp = (node*)malloc(sizeof(node));
         temp->data = i;

        if (begin == NULL) {
            begin = temp;
        }

        if (head != NULL) {
            head->next = temp;
        }
        head = temp;
        head->next = NULL;

    }
    head = begin;
    printList(head);
    return 0;

}