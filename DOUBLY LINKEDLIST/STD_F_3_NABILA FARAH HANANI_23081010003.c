#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
void tambahAkhir (node **head);
void hapusAwal (node **head);
void hapusTengah (node **head);
void hapusAkhir (node **head);
void cariData (node *head);
void jumlahData (node *head);
void jumlahtotalData (node *head);

//========================================================

int main()
{
    node *head;
    char pilih;

    head = NULL;
    do{
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
        if (pilih == '1')
                tambahAwal(&head);
        else if (pilih == '2')
                tambahData(&head);
        else if (pilih == '3')
                tambahAkhir(&head);
        else if (pilih == '4')
                hapusAwal (&head);
        else if (pilih == '5')
                hapusTengah (&head);
        else if (pilih == '6')
                hapusAkhir (&head);
        else if (pilih == '7')
                cariData (head);
        else if (pilih == '8')
                jumlahData (head);
        else if (pilih == '9')
                jumlahtotalData (head);
        else if (pilih == '0'){
                tranverse(head);
            getch();
        }
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head){
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL){
        pNew->data = bil;
        pNew->next = NULL;
        pNew->prev = NULL;

        if (*head != NULL) {
            (*head)->prev = pNew;
        }

        pNew->next = *head;
        *head = pNew;
    }
    else{
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head){
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL){
        printf("\nnode tidak ditemukan");
        getch();
    }
    else if (pNew == NULL){
        printf("\nalokasi memori gagal");
        getch();
    }
    else{
        pNew->data = bil;
        pNew->next = pCur->next;
        pNew->prev = pCur;

        if (pCur->next != NULL) {
            pCur->next->prev = pNew;
        }

        pCur->next = pNew;
    }
}

//========================================================

void tranverse(node *list) {
    node *pWalker = list;

    if (list == NULL) {
        printf("List kosong!\n");
        return;
    }

    printf("NULL <- ");
    while (pWalker != NULL) {
        printf("%d", pWalker->data);
        pWalker = pWalker->next;
        if (pWalker != NULL) {
            printf(" <-> ");
        }
    }
    printf(" -> NULL\n");
}
//========================================================

void tambahAkhir(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL){
        pNew->data = bil;
        pNew->next = NULL;
        pNew->prev = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->prev = pCur;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal (node **head){
    node *pDel;
    pDel = *head;

    if (*head != NULL) {
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(pDel);
    }
    printf("Node di awal berhasil dihapus");
    getch();
}

//========================================================

void hapusTengah(node **head) {
    int target;
    node *pCur;

    system("cls");
    tranverse(*head);
    printf("\nbilangan yang akan dihapus: ");
    fflush(stdin);
    scanf("%d", &target);

    pCur = *head;

    while (pCur != NULL && pCur->data != target) {
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Node dengan data %d tidak ditemukan\n", target);
    } else {
        if (pCur->prev != NULL) {
            pCur->prev->next = pCur->next;
        } else {
            *head = pCur->next;
        }

        if (pCur->next != NULL) {
            pCur->next->prev = pCur->prev;
        }

        free(pCur);
        printf("Node dengan data %d berhasil dihapus\n", target);
    }

    getch();
}

//========================================================

void hapusAkhir (node **head){
    node *pCur;

    system("cls");

    if (*head == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    pCur = *head;

    while (pCur->next != NULL) {
        pCur = pCur->next;
    }

    if (pCur->prev != NULL) {
        pCur->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(pCur);
    printf("Node terakhir berhasil dihapus\n");
    getch();
}

//========================================================

void cariData(node *head) {
    int target, posisi = 1;
    node *pCur;

    system("cls");
    printf("Masukkan nilai data yang ingin dicari: ");
    fflush(stdin);
    scanf("%d", &target);
    pCur = head;

    while (pCur != NULL) {
        if (pCur->data == target) {
            printf("Data %d ditemukan pada posisi %d\n", target, posisi);
            getch();
            return;
        }
        pCur = pCur->next;
        posisi++;
    }

    printf("Data %d tidak ditemukan dalam linked list\n", target);
    getch();
}

//========================================================

void jumlahData(node *head) {
    int count = 0;
    system("cls");
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah data dalam linked list: %d\n", count);
    getch();
}

//========================================================

void jumlahtotalData(node *head) {
    int total = 0;
    system("cls");
    node *pCur = head;
    while (pCur != NULL) {
        total += pCur->data;
        pCur = pCur->next;
    }
    printf("Hasil penjumlahan semua data di linked list: %d\n", total);
    getch();
}
