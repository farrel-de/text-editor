#include <stdio.h>
#include <stdlib.h>  // Ditambahkan untuk fungsi malloc dan free
#include "fileio.h"
#include "editor.h"
#include "newfile.h" // Ditambahkan untuk mengosongkan RAM saat open file

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

void SaveAs() {
    printf("Masukkan nama file baru (contoh: tugas.txt): ");
    // namaFile sudah dialokasikan memori sebesar 100 bytes di main.c, jadi langsung aman di-scanf
    scanf("%s", namaFile); 

    SimpanKeFile(); // Panggil fungsi simpan yang sudah ada
}

void BukaDariFile() {
    char *tempNama = (char*)malloc(100);
    if (tempNama == NULL) return;

    printf("Masukkan nama file yang ingin dibuka: ");
    scanf("%s", tempNama);

    FILE *fptr = fopen(tempNama, "r");
    if (fptr == NULL) {
        printf(">> GAGAL: File '%s' tidak ditemukan!\n", tempNama);
        free(tempNama); // Bebaskan memori temporary jika file tidak ada
        return;
    }

    // 1. Bersihkan semua node lama yang ada di RAM terlebih dahulu
    HapusSemuaNode();

    // 2. Baca file karakter demi karakter, masukkan ke Linked List lewat SisipTeks
    char huruf;
    while ((huruf = fgetc(fptr)) != EOF) {
        SisipTeks(huruf); 
    }

    fclose(fptr);

    // 3. Salin tempNama ke namaFile menggunakan Pointer Arithmetic manual (0% strcpy bawaan)
    char *src = tempNama;
    char *dest = namaFile;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Beri null terminator di akhir pointer

    free(tempNama); // Bebaskan memori temporary karena tugasnya sudah selesai
    BelumSimpan = false; // Setel status menjadi bersih (sudah sinkron dengan harddisk)
    printf(">> SUKSES: File '%s' berhasil dimuat ke memori!\n", namaFile);
}