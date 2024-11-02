#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_MAHASISWA 20

struct Mahasiswa {
    char nama[20];
    char jeniskelamin[5];
    struct Mahasiswa *right;
    struct Mahasiswa *left;
};

void transverse(struct Mahasiswa *tail);
void tambahMhsCindy(struct Mahasiswa **tail);
void tambahMhs(struct Mahasiswa **tail, int *count);
void hapusMhs(struct Mahasiswa **tail, int *count);
void lingkaranMahasiswa(struct Mahasiswa *tail);
void lingkaranMahasiswi(struct Mahasiswa *tail);
int pilih();

int main() {
    pilih();
    return 0;
}

int pilih() {
    int pilih;
    struct Mahasiswa *tail = NULL;
    int count = 0;

    do {
        system("cls");
        printf("1. Menambah Mahasiswa\n");
        printf("2. Mengeluarkan Mahasiswa\n");
        printf("3. Lingkaran Mahasiswa\n");
        printf("4. Lingkaran Mahasiswi\n");
        printf("5. Lingkaran Mahasiswa-Mahasiswi\n");
        printf("Masukkan Pilihan (tekan 0 untuk keluar): ");
        scanf(" %d", &pilih);

        switch (pilih) {
        case 1: tambahMhs(&tail, &count); break;
        case 2: hapusMhs(&tail, &count); break;
        case 3: lingkaranMahasiswa(tail); getch(); break;
        case 4: lingkaranMahasiswi(tail); getch(); break;
        case 5: transverse(tail); getch(); break;
        case 0: break;
        default:
            printf("Pilihan tidak valid. Coba lagi.\n");
            getch();
            break;
        }
    } while (pilih != 0);

    return 0;
}

void transverse(struct Mahasiswa *tail) {
    if (tail == NULL) {
        printf("List Kosong\n");
        return;
    }

    struct Mahasiswa *pWalker = tail->right;

    printf("Lingkaran Mahasiswa-Mahasiswi:\n");
    do {
        printf("%s (%s) -> ", pWalker->nama, pWalker->jeniskelamin);
        pWalker = pWalker->right;
    } while (pWalker != tail->right);

    printf("%s (%s)\n", tail->right->nama, tail->right->jeniskelamin);
}



void tambahMhsCindy(struct Mahasiswa **tail) {
    struct Mahasiswa *pCur = *tail, *pNew = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));

    if (*tail == NULL) {
        printf("\nCindy tidak dapat ditambahkan karena tidak ada mahasiswa perempuan.\n");
        free(pNew);
        return;
    }
    int found = 0;
    while (pCur->right != *tail) {
        if (strcmp(pCur->jeniskelamin, "P") == 0 && strcmp(pCur->right->jeniskelamin, "P") == 0) {
            found = 1;
            strcpy(pNew->nama, "Cindy");
            strcpy(pNew->jeniskelamin, "P");

            pNew->right = pCur->right;
            pNew->left = pCur;
            pCur->right->left = pNew;
            pCur->right = pNew;
            break;
        }
        pCur = pCur->right;
    }

    if (!found) {
        free(pNew);
        printf("\nTidak memenuhi syarat yang diinginkan Cindy\n");
        getch();
    }
}

void tambahMhs(struct Mahasiswa **tail, int *count) {
    if (*count >= MAX_MAHASISWA) {
        printf("\nSudah mencapai batas maksimum mahasiswa (20). Tidak dapat menambah mahasiswa baru.\n");
        getch();
        return;
    }

    struct Mahasiswa *pNew = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));

    printf("\nMasukkan Nama Mahasiswa: ");
    scanf(" %s", pNew->nama);
    printf("Masukkan Jenis Kelamin Mahasiswa L/P: ");
    scanf(" %s", pNew->jeniskelamin);

    if (strcmp(pNew->nama, "Cindy") == 0) {
        free(pNew);
        tambahMhsCindy(tail);
        return;
    }

    if (strcmp(pNew->nama, "Irsyad") == 0 || strcmp(pNew->nama, "Arsyad") == 0) {
        struct Mahasiswa *pKembar = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
        strcpy(pKembar->nama, (strcmp(pNew->nama, "Irsyad") == 0) ? "Arsyad" : "Irsyad");
        strcpy(pKembar->jeniskelamin, "L");

        if (*tail == NULL) {
            pNew->right = pNew;
            pNew->left = pNew;
            (*tail) = pNew;

            pKembar->right = pNew;
            pKembar->left = pNew;
            return;
        }

        pNew->right = (*tail)->right;
        pNew->left = *tail;
        (*tail)->right->left = pNew;
        (*tail)->right = pNew;

        pKembar->right = pNew->right;
        pKembar->left = pNew;
        pNew->right->left = pKembar;
        pNew->right = pKembar;
    } else {
        if (*tail == NULL) {
            pNew->right = pNew;
            pNew->left = pNew;
            (*tail) = pNew;
        } else {
            pNew->right = (*tail)->right;
            pNew->left = *tail;
            (*tail)->right->left = pNew;
            (*tail)->right = pNew;
        }
    }

    (*count)++;
}

void hapusMhs(struct Mahasiswa **tail, int *count) {
    struct Mahasiswa *pCur = (*tail);

    if (pCur == NULL) {
        printf("List Kosong, tidak ada yang dapat dihapus.\n");
        getch();
        return;
    }

    char pos[20];
    transverse(*tail);
    printf("\nMasukkan nama yang ingin dihapus: ");
    scanf(" %s", pos);

    do {
        pCur = pCur->right;
    } while (strcmp(pos, pCur->nama) != 0 && pCur != (*tail));

    if (pCur == (*tail)) {
        if (pCur->left == pCur) {
            free(pCur);
            *tail = NULL;
        } else {
            (*tail) = pCur->left;
        }
    }

    pCur->left->right = pCur->right;
    pCur->right->left = pCur->left;
    free(pCur);
    (*count)--;
}

void lingkaranMahasiswa(struct Mahasiswa *tail) {
    if (tail == NULL) {
        printf("List Kosong\n");
        return;
    }
    struct Mahasiswa *pWalker = tail->right;
    do {
        if (strcmp(pWalker->jeniskelamin, "L") == 0) {
            printf(" %s (%s) -> ", pWalker->nama, pWalker->jeniskelamin);
        }
        pWalker = pWalker->right;
    } while (pWalker != tail->right);

     printf("%s (%s)\n", tail->right->nama, tail->right->jeniskelamin);
}

void lingkaranMahasiswi(struct Mahasiswa *tail) {
    if (tail == NULL) {
        printf("List Kosong\n");
        return;
    }
    struct Mahasiswa *pWalker = tail->right;
    do {
        if (strcmp(pWalker->jeniskelamin, "P") == 0) {
            printf(" %s (%s) -> ", pWalker->nama, pWalker->jeniskelamin);
        }
        pWalker = pWalker->right;
    } while (pWalker != tail->right);

    printf("%s (%s)\n", tail->right->nama, tail->right->jeniskelamin);
}
