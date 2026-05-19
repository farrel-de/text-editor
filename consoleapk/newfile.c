#include <stdio.h>
#include <stdlib.h>
#include "editor.h"
#include "newfile.h"
#include "fileio.h"

void HapusSemuaNode() {
    Node *curr = head;
    while (curr != NULL) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    head = NULL;
    cursor = NULL;
}

void JalankanFiturNew() {
    if (BelumSimpan) {
        char pilihan;
        printf("\n[PERINGATAN] Simpan dulu? (y/n): ");
        scanf(" %c", &pilihan);
        if (pilihan == 'y' || pilihan == 'Y') SimpanKeFile();
    }
    HapusSemuaNode();
    BelumSimpan = false;
    printf("\n>> Lembar baru siap di.\n");
}