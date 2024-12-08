#include "util.c"

int main() {


}

void sort(LIST *A, LIST *B) {
    LIST *trav, temp;
    while (*B != NULL) {
        for (; *trav != NULL && (*trav)->data < (*B)->data; trav = &(*trav)->link) {}
        temp = *B;
        *B = temp->link;
        temp->link = *trav;
        *trav = temp;
    }
}

void bucketSort(LIST *L, int placevalue) {
    LIST temp;
    int x;

    LIST buckets[BUCKETS] = {NULL};
    while (*L != NULL) {
        temp = *L;
        *L = temp->link;
        x = temp->data / placevalue % BUCKETS;
        temp->link = buckets[x];
        buckets[x] = temp;
    }

    for (x = BUCKETS - 1; x >= 0; --x) {
        while (buckets[x] != NULL) {
            temp = buckets[x];
            buckets[x] = temp->link;
            temp->link = *L;
            *L = temp;
        }
    }
}