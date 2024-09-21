#include<stdio.h>
#include<stdlib.h>

struct node {
    int a;
    struct node *next;
};

node *makeNode(int x) {
    node *b = (node*)malloc(sizeof(node));
    b->a = x;
    b->next = NULL;
    return b;
}

void Duyet(node* head) {
    while (head != NULL) {
        printf("%d ", head->a);
        head = head->next;
    }
    printf("\n");
}

void count(node *head) {
    int dem = 0;
    while (head != NULL) {
        ++dem;
        head = head->next;
    }
    printf("\n%d\n", dem);
}

void ThemDau(node **head, int x) {
    node *newnode = makeNode(x);
    newnode->next = *head;
    *head = newnode;
}

void ThemCuoi(node **head, int x) {
    node *temp = *head;
    node *b = makeNode(x);
    if (*head == NULL) {
        *head = b;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = b;
}

void themgiua(node **head, int k, int x) {
    int n = 0;
    node *temp = *head;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    if (k < 1 || k > n + 1) return;
    if (k == 1) {
        ThemDau(head, x);
        return;
    }

    temp = *head;
    for (int i = 1; i <= k - 2; i++) {
        temp = temp->next;
    }
    node *b = makeNode(x);
    b->next = temp->next;
    temp->next = b;
}

int main() {
    int i;
    node *head = NULL;
    while (1) {
        printf("1. Them Dau\n");
        printf("2. Them Cuoi\n");
        printf("3. Them Giua\n");
        printf("4. Dem\n");
        printf("5. In\n");

        int chon;
        printf("\nNhap vao lua chon: ");
        scanf("%d", &chon);
        if (chon == 1) {
            int x;
            printf("\nNhap vao x: ");
            scanf("%d", &x);
            ThemDau(&head, x);
        } else if (chon == 2) {
            int x;
            printf("\nNhap vao x: ");
            scanf("%d", &x);
            ThemCuoi(&head, x);
        } else if (chon == 3) {
            int x;
            printf("\nNhap vao x: ");
            scanf("%d", &x);
            int k;
            printf("\nNhap vao vitri k: ");
            scanf("%d", &k);
            themgiua(&head, k, x);
        } else if (chon == 4) {
            count(head);
        } else if (chon == 5) {
            Duyet(head);
        } else {
            break;
        }
    }
}

