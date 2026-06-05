#include <stdio.h>
#include <stdlib.h>
#include "editor.h"
#include "fileio.h"
#include "newfile.h"

// Gunakan tipe data custom jika bool tidak terdefinisi (atau tetap pakai stdbool.h)
// pakai ga ya
#include <stdbool.h> 

bool BelumSimpan = false;
Node *head = NULL;
Node *cursor = NULL;
char *namaFile = NULL;

// Fungsi pengganti strcpy menggunakan Pointer Arithmetic
void salinTeks(char *tujuan, const char *sumber) {
    while (*sumber != '\0') { // Selama karakter sumber bukan null terminator
        *tujuan = *sumber;    // Isi alamat yang ditunjuk 'tujuan' dengan isi 'sumber'
        tujuan++;             // Geser alamat tujuan ke depan
        sumber++;             // Geser alamat sumber ke depan
    }
    *tujuan = '\0';           // Beri tanda akhir string di akhir
}

int main() {
    // 1. Alokasi memori untuk pointer namaFile
    namaFile = (char*)malloc(100 * sizeof(char));
    
    if (namaFile != NULL) {
        // 2. Mengganti strcpy(namaFile, "catatan.txt") dengan fungsi pointer manual
        salinTeks(namaFile, "catatan.txt");
    }

    int menu;
    char inputChar;

    while (1) {
        printf("\n=== NOTEPAD (LINKED LIST) ===\n");
        printf("Isi: ");
        
        Node *temp = head;
        while (temp != NULL) {
            printf("%c", temp->data);
            temp = temp->next;
        }
        
        // printf %s tetap bekerja dengan pointer char*
        printf("\nFile: %s | Status: %s\n", namaFile, BelumSimpan ? "Belum di save" : "Belum ada teks");
        printf("---------------------------------\n");
        printf("1. Isi Teks\n2. Save\n3. Baru\n4. Keluar\n");
        printf("Pilih: ");
        
        if (scanf("%d", &menu) != 1) break;

        if (menu == 1) {
            printf("Ketik ('0' selesai, '<' kiri, '>' kanan): ");
            while (1) {
                scanf(" %c", &inputChar);
                if (inputChar == '0') break; 

                if (inputChar == '<') {
                    if (cursor != NULL && cursor->prev != NULL) {
                        cursor = cursor->prev;
                    }
                } 
                else if (inputChar == '>') {
                    if (cursor != NULL && cursor->next != NULL) {
                        cursor = cursor->next;
                    }
                } 
                else {
                    SisipTeks(inputChar); 
                    BelumSimpan = true; 
                }
            }
        } 
        else if (menu == 2) SimpanKeFile();
        else if (menu == 3) JalankanFiturNew();
        else if (menu == 4) break;
    }

    HapusSemuaNode(); 
    free(namaFile);   
    return 0;          
}