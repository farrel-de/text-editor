#include <stdio.h>
#include "fileio.h"
#include "editor.h"

void SimpanKeFile() {
    FILE *fptr = fopen(namaFile, "w");
    if (fptr == NULL) {
        printf(">> Gagal membuka file!\n");
        return;
    }

    Node *curr = head;
    while (curr != NULL) {
        fputc(curr->data, fptr);
        curr = curr->next;
    }

    fclose(fptr);
    BelumSimpan = false;
    printf(">> Berhasil disimpan ke %s\n", namaFile);
}