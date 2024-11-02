#include <stdio.h>
#include <stdlib.h>

//========================================================

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* createNode(int data);
void pushStack(node** top, int data, int maxSize);
int popStack(node** top);
int stackTop(node* top);
int isEmpty(node* top);
int fullStack(node* top, int maxSize);
int stackCount(node* top);
void destroyStack(node** top);
void traverse(node* top);

//========================================================

int main() {
    node *top = NULL;
    char pilih;
    int data;
    int maxSize = 20;

    do {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. tambah data di paling atas (Push Stack)\n");
        printf("2. hapus data di paling atas (Pop Stack)\n");
        printf("3. tampilkan data paling atas (Stack Top)\n");
        printf("4. cek stack kosong atau terisi (Empty Stack)\n");
        printf("5. cek stack penuh atau belum (Full Stack)\n");
        printf("6. hitung jumlah data (Stack Count)\n");
        printf("7. kosongkan semua data (Destroy Stack)\n");
        printf("0. cetak isi data\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");

        fflush(stdin);
        scanf(" %c", &pilih);

        switch (pilih) {
            case '1':
                printf("Masukkan data ke atas: ");
                scanf("%d", &data);
                getchar();
                pushStack(&top, data, maxSize);
                break;
            case '2':
                data = popStack(&top);
                if (data != -1) {
                    printf("Data paling atas (%d) telah dihapus!\n", data);
                } else {
                    printf("Stack kosong, tidak ada data yang dapat dihapus!\n");
                }
                getchar();
                break;
            case '3':
                data = stackTop(top);
                if (data != -1) {
                    printf("Data paling atas adalah: %d\n", data);
                } else {
                    printf("Stack kosong!\n");
                }
                getchar();
                break;
            case '4':
                if (isEmpty(top)){
                    printf("Stack kosong!\n");
                } else {
                    printf("Stack terisi!\n");
                }
                getchar();
                break;
            case '5':
                if (fullStack(top, maxSize)) {
                    printf("Stack penuh!\n");
                } else {
                    printf("Stack tidak penuh!\n");
                }
                getchar();
                break;
            case '6':
                printf("Jumlah data dalam stack: %d\n", stackCount(top));
                getchar();
                break;
            case '7':
                destroyStack(&top);
                getchar();
                break;
            case '0':
                traverse(top);
                getchar();
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi!\n");
                break;
        }

        if (pilih != 'q') {
            printf("Klik enter untuk menjalankan fungsi selanjutnya!");
            getchar();
        }
    } while (pilih != 'q');

    return 0;
}

//========================================================

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//========================================================

void pushStack(node** top, int data, int maxSize) {
    if (stackCount(*top) >= maxSize) {
        printf("Stack penuh, %d tidak ditambahkan\n", data);
        return;
    }
    node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Alokasi memori gagal\n");
        return;
    }
    newNode->next = *top;
    *top = newNode;
    printf("%d telah ditambahkan ke stack paling atas\n", data);
}

//========================================================

int popStack(node** top) {
    if (*top == NULL) {
        printf("Stack kosong, tidak ada data untuk dihapus\n");
        return -1; // Mengembalikan -1 jika stack kosong
    }
    node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("%d dihapus dari stack\n", popped);
    return popped;
}

//========================================================

int stackTop(node* top) {
    if (top == NULL) {
        return -1;
    }
    return top->data;
}

//========================================================

int isEmpty(node* top) {
    return top == NULL;
}

//========================================================

int fullStack(node* top, int maxSize) {
    return stackCount(top) >= maxSize;
}

//========================================================

int stackCount(node* top) {
    int count = 0;
    node* current = top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

//========================================================

void destroyStack(node** top) {
    while (!isEmpty(*top)) {
        popStack(top);
    }
    printf("Stack telah dikosongkan!\n");
}

//========================================================

void traverse(node* top) {
    if (isEmpty(top)) {
        printf("Stack kosong!\n");
        return;
    }
    node* current = top;
    printf("Isi stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
