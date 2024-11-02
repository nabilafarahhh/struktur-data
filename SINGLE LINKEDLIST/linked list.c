#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
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


//Kode untuk menambahkan nodenya memakai struct
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

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

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
      //add before first logical node or to an empty list
	  pNew -> next = *head;
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
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
}

//========================================================

void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d\t", pWalker -> data);
   	pWalker = pWalker -> next;
      printf(" -> ");
	}
   printf("NULL");
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


        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
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
    *head = (*head)->next;
    free(pDel);
    printf("Node di awal berhasil dihapus");
    getch();
}

//========================================================

void hapusTengah(node **head) {
    int target,pos;
    node *pCur, *pPrev;

    system("cls");
    tranverse(*head);
    printf("\nposisi penghapusan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &target);

    pCur = *head;
    pPrev = NULL;
    while (pCur != NULL && pCur->data != target) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Node dengan data %d tidak ditemukan\n", target);
    } else {
        pPrev->next = pCur->next;
        free(pCur);
        printf("Node dengan data %d berhasil dihapus\n", target);
    }

    getch();
}

//========================================================

void hapusAkhir (node **head){
     node *pCur, *pPrev;
     system("cls");

     pCur = *head;
     pPrev = NULL;

     while (pCur->next != NULL) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    free(pCur);
    pPrev->next = NULL;
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
