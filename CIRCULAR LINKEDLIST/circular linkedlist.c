#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **list);
void tambahTengah(node **list);
void tranverse(node *list);
void tambahAkhir(node **list);
void hapusAwal(node **list);
void hapusTengah(node **list);
void hapusAkhir(node **list);
void cariData(node *list);
void jumlahData(node *list);
void jumlahtotalData(node *list);

//========================================================

int main() {
    node *list;
    char pilih;

    list = NULL;
    do {
        system("cls");
        printf("masukkan pilihan\n");
        printf("1. tambah data di awal\n");
        printf("2. tambah data di tengah list\n");
        printf("3. tambah data di akhir list\n");
        printf("4. menghapus data di awal\n");
        printf("5. menghapus data di tengah\n");
        printf("6. menghapus data di akhir\n");
        printf("7. mencari data\n");
        printf("8. menampilkan informasi jumlah data\n");
        printf("9. menampilkan hasil penjumlahan total seluruh data\n");
        printf("0. cetak isi list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &pilih);

        switch (pilih) {
            case '1': tambahAwal(&list); break;
            case '2': tambahTengah(&list); break;
            case '3': tambahAkhir(&list); break;
            case '4': hapusAwal(&list); break;
            case '5': hapusTengah(&list); break;
            case '6': hapusAkhir(&list); break;
            case '7': cariData(list); break;
            case '8': jumlahData(list); break;
            case '9': jumlahtotalData(list); break;
            case '0': tranverse(list); getch(); break;
        }
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **list) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;

        if (*list == NULL) {
            *list = pNew;
            pNew->next = pNew;
        } else {
            pCur = *list;
            while (pCur->next != *list) {
                pCur = pCur->next;
            }
            pNew->next = *list;
            pCur->next = pNew;
            *list = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahTengah(node **list) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*list);
    printf("\nposisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*list == NULL) {
        printf("List masih kosong, tambahkan di awal terlebih dahulu\n");
        getch();
        return;
    }

    pCur = *list;

    do {
        if (pCur->data == pos)
            break;
        pCur = pCur->next;
    } while (pCur != *list);

    if (pCur->data != pos) {
        printf("\nNode tidak ditemukan\n");
        getch();
    } else {
        pNew = (node *)malloc(sizeof(node));
        if (pNew == NULL) {
            printf("\nAlokasi memori gagal\n");
            getch();
        } else {
            pNew->data = bil;
            pNew->next = pCur->next;
            pCur->next = pNew;
        }
    }
}

//========================================================

void tranverse(node *list) {
    node *pWalker;

    if (list == NULL) {
        printf("List kosong\n");
        return;
    }

    pWalker = list;
    printf("List berisi:\n");

        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;

    while (pWalker != list){
    printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    }

    printf("%d\n",list->data);
}

//========================================================

void tambahAkhir(node **list) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;

        if (*list == NULL) {
            pNew->next = pNew;
            *list = pNew;
        } else {
            pCur = *list;
            while (pCur->next != *list) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *list;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **list) {
    node *pDel, *pCur;

    if (*list == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    pDel = *list;
    if (pDel->next == *list) {
        free(pDel);
        *list = NULL;
    } else {
        pCur = *list;
        while (pCur->next != *list) {
            pCur = pCur->next;
        }
        *list = (*list)->next;
        pCur->next = *list;
        free(pDel);
    }
    printf("Node di awal berhasil dihapus");
    getch();
}

//========================================================

void hapusTengah(node **list) {
    int target;
    node *pCur, *pPrev;

    system("cls");
    tranverse(*list);
    printf("\nMasukkan nilai data yang ingin dihapus: ");
    scanf("%d", &target);

    if (*list == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }   x1

    pCur = *list;
    pPrev = NULL;

    do {
        if (pCur->data == target) {
            break;
        }
        pPrev = pCur;
        pCur = pCur->next;
    } while (pCur != *list);

    if (pCur->data != target) {
        printf("Node dengan data %d tidak ditemukan\n", target);
        getch();
    } else {
        if (pCur == *list) {
            hapusAwal(list);
        } else {
            pPrev->next = pCur->next;
            free(pCur);
            printf("Node dengan data %d berhasil dihapus\n", target);
            getch();
        }
    }
}

//========================================================

void hapusAkhir(node **list) {
    node *pCur, *pPrev;

    if (*list == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    pCur = *list;
    pPrev = NULL;

    if (pCur->next == *list) {
        free(pCur);
        *list = NULL;
    } else {
        while (pCur->next != *list) {
            pPrev = pCur;
            pCur = pCur->next;
        }

        pPrev->next = *list;
        free(pCur);
    }
    printf("Node terakhir berhasil dihapus\n");
    getch();
}

//========================================================

void cariData(node *list) {
    int target, posisi = 1;
    node *pCur;

    if (list == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    system("cls");
    printf("Masukkan nilai data yang ingin dicari: ");
    scanf("%d", &target);
    pCur = list;

    do {
        if (pCur->data == target) {
            printf("Data %d ditemukan pada posisi %d\n", target, posisi);
            getch();
            return;
        }
        pCur = pCur->next;
        posisi++;
    } while (pCur != list);

    printf("Data %d tidak ditemukan dalam linked list\n", target);
    getch();
}

//========================================================

void jumlahData(node *list) {
    int count = 0;
    node *pCur = list;

    if (list == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    system("cls");
    do {
        count++;
        pCur = pCur->next;
    } while (pCur != list);

    printf("Jumlah data dalam linked list: %d\n", count);
    getch();
}

//========================================================

void jumlahtotalData(node *list) {
    int total = 0;
    node *pCur = list;

    if (list == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    system("cls");
    do {
        total += pCur->data;
        pCur = pCur->next;
    } while (pCur != list);

    printf("Jumlah total seluruh data dalam linked list: %d\n", total);
    getch();
}
