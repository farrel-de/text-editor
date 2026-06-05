#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

void SisipTeks(char c) {
    Node *baru = (Node*)malloc(sizeof(Node));
    if (baru == NULL) return;
    baru->data = c;

    if (head == NULL) {
        baru->next = baru->prev = NULL;
        head = cursor = baru;
    } else {
        // Menyisipkan tepat setelah posisi kursor
        baru->next = cursor->next;
        baru->prev = cursor;
        
        if (cursor->next != NULL) {
            cursor->next->prev = baru;
        }
        cursor->next = baru;
        cursor = baru; // Kursor otomatis pindah ke karakter baru
    }
    BelumSimpan = true;
}