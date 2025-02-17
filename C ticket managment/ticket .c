#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nyje {
    char emer[50];
    int bileta;
    struct Nyje* tj;
} Nyje;

Nyje* fillimi = NULL;
Nyje* fundi = NULL;
int biletaTotale = 0;

void shto(char emer[], int bileta) {
    Nyje* eRe = (Nyje*)malloc(sizeof(Nyje));
    if (eRe == NULL) {
        printf("Gabim në alokimin e memories!\n");
        return;
    }

    strcpy(eRe->emer, emer);
    eRe->bileta = bileta;
    eRe->tj = NULL;

    if (fundi == NULL) {
        fillimi = fundi = eRe;
    } else {
        fundi->tj = eRe;
        fundi = eRe;
    }

    printf("%s u shtua ne radhe me %d bileta.\n", emer, bileta);
}

// Heq personin e parë nga radha
void hiq() {
    if (fillimi == NULL) {
        printf("Radha eshtë bosh!\n");
        return;
    }

    Nyje* temp = fillimi;
    biletaTotale += temp->bileta;

    printf("%s mori biletat dhe doli nga radha.\n", temp->emer);

    fillimi = fillimi->tj;
    if (fillimi == NULL) {
        fundi = NULL;
    }

    free(temp);
}

void kerko(char emer[]) {
    Nyje* temp = fillimi;
    while (temp != NULL) {
        if (strcmp(temp->emer, emer) == 0) {
            printf("%s eshte ne radhe me %d bileta.\n", temp->emer, temp->bileta);
            return;
        }
        temp = temp->tj;
    }
    printf("%s nuk eshtw nw radhe.\n", emer);
}

void biletaShitura() {
    printf("Bileta totale të shitura: %d\n", biletaTotale);
}

void shfaqRadhen() {
    if (fillimi == NULL) {
        printf("Radha eshte bosh!\n");
        return;
    }

    Nyje* temp = fillimi;
    printf("Personat ne radhe:\n");
    while (temp != NULL) {
        printf("%s (%d bileta)\n", temp->emer, temp->bileta);
        temp = temp->tj;
    }
}

int main() {
    int zgjedhje, bileta;
    char emer[50];
    printf("arbri metaj 2025");
    while (1) {
        printf("\nMenaxhimi i Radhes se Biletave:\n");
        printf("1. Shto person ne radhe\n");
        printf("2. Hiq personin e pare\n");
        printf("3. Kerko nje person\n");
        printf("4. Shfaq biletat e shitura\n");
        printf("5. Shfaq radhen\n");
        printf("6. Dil\n");
        printf("Zgjedhja juaj: ");
        scanf("%d", &zgjedhje);
        getchar();

        switch (zgjedhje) {
            case 1:
                printf("Emri: ");
                fgets(emer, sizeof(emer), stdin);
                emer[strcspn(emer, "\n")] = 0;
                printf("Numri i biletave: ");
                scanf("%d", &bileta);
                shto(emer, bileta);
                break;

            case 2:
                hiq();
                break;

            case 3:
                printf("Emri per te kerkuar: ");
                fgets(emer, sizeof(emer), stdin);
                emer[strcspn(emer, "\n")] = 0;
                kerko(emer);
                break;

            case 4:
                biletaShitura();
                break;

            case 5:
                shfaqRadhen();
                break;

            case 6:
                printf("Dalje...\n");
                return 0;

            default:
                printf("Zgjedhje e pavlefshme! Provo perseri.\n");
        }
    }
}
