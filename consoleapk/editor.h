#ifndef EDITOR_H
#define EDITOR_H
#include <stdbool.h>

typedef struct Node {
    char data;
    struct Node *next;
    struct Node *prev;
} Node;

extern bool BelumSimpan;
extern Node *head;
extern Node *cursor; // Pointer kursor untuk navigasi
extern char *namaFile;

void SisipTeks(char c);

#endif