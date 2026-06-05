#include <stdio.h>
#include <stdlib.h>  // Ditambahkan untuk malloc dan free
#include "searchfile.h"
#include "editor.h"

void CariKata() {
    // 1. Alokasi memori dinamis untuk kata yang dicari (0% Array!)
    char *kata = (char*)malloc(50);
    if (kata == NULL) return;

    printf("Masukkan kata yang dicari: ");
    scanf("%s", kata);

    // Hitung panjang kata yang dicari secara manual pakai pointer walking
    int panjangKata = 0;
    char *p = kata;
    while (*p != '\0') {
        panjangKata++;
        p++;
    }

    Node *startNode = head;
    bool ditemukan = false;

    // 2. Traversal Linked List untuk mencari kecocokan kata
    while (startNode != NULL) {
        Node *currNode = startNode;
        char *currKata = kata;
        bool cocok = true;

        // Cek apakah karakter ke depan sama dengan kata yang dicari
        while (*currKata != '\0') {
            if (currNode == NULL || currNode->data != *currKata) {
                cocok = false;
                break;
            }
            currNode = currNode->next;
            currKata++;
        }

        if (cocok && panjangKata > 0) {
            ditemukan = true;
            break;
        }

        startNode = startNode->next; // Geser ke node berikutnya jika belum cocok
    }

    // 3. Cetak Hasil
    if (ditemukan) {
        printf(">> Hasil: Kata '%s' DITEMUKAN!\n", kata);
    } else {
        printf(">> Hasil: Kata tidak ada.\n");
    }

    // 4. Bebaskan memori dinamis
    free(kata);
}