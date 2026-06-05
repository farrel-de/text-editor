#include <stdio.h>
#include <stdlib.h>
#include "editor.h"
#include "fileio.h"
#include "newfile.h"


bool BelumSimpan;
Node *head;
Node *cursor;
char *namaFile;

void salinTeks(char *tujuan, const char *sumber) {
    while (*tujuan++ = *sumber++); 
}

int main() {
    // 1. Alokasi memori untuk pointer namaFile
    namaFile = (char*)malloc(100);
    
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


        printf("\nFile: %s | Status: %s\n", namaFile, BelumSimpan ? "Belum di save" : "Belum ada teks/Aman");
        printf("---------------------------------\n");
        printf("1. Isi Teks\n");
        printf("2. Save File (Cepat)\n");
        printf("3. Save As (Nama Baru)\n");
        printf("4. Open File\n");
        printf("5. Lembar Baru\n");
        printf("6. Keluar\n");
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
                }
            }
        } 
        else if (menu == 2) {
            SimpanKeFile();
        }
        else if (menu == 3) {
            SaveAs();        
        }
        else if (menu == 4) {
            BukaDariFile();  
        }
        else if (menu == 5) {
            JalankanFiturNew();
        }
        else if (menu == 6) {
            break;
        }
    }

    HapusSemuaNode(); 
    free(namaFile);   
    return 0;          
}