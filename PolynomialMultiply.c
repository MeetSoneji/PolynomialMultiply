#include <stdio.h>
#include <stdlib.h>
struct Term {
    int coefficient;
    int exponentX;
    int exponentY;
    struct Term* next;
};
struct Term* createTerm(int coefficient, int exponentX, int exponentY) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponentX = exponentX;
    newTerm->exponentY = exponentY;
    newTerm->next = NULL;
    return newTerm;
}
void insertTerm(struct Term** polynomial, int coefficient, int exponentX, int exponentY) {
    struct Term* newTerm = createTerm(coefficient, exponentX, exponentY);
    if (*polynomial == NULL) {
        *polynomial = newTerm;
    } else {
        struct Term* temp = *polynomial;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}
void displayPolynomial(struct Term* polynomial) {
    if (polynomial == NULL) {
        printf("Polynomial is empty!\n");
        return;
    }
    struct Term* temp = polynomial;
    printf("Polynomial: ");
    while (temp != NULL) {
        printf("%d", temp->coefficient);
        if (temp->exponentX > 0) {
            printf("x^%d", temp->exponentX);
        }
        if (temp->exponentY > 0) {
            printf("y^%d", temp->exponentY);
        }
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}
struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL) {
        struct Term* temp = poly2;
        while (temp != NULL) {
            int coefficient = poly1->coefficient * temp->coefficient;
            int exponentX = poly1->exponentX + temp->exponentX;
            int exponentY = poly1->exponentY + temp->exponentY;
            insertTerm(&result, coefficient, exponentX, exponentY);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }

    return result;
}
int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    insertTerm(&poly1, 3, 2, 3);
    insertTerm(&poly1, 2, 1, 4);
    insertTerm(&poly1, 1, 0, 0);
    insertTerm(&poly2, 2, 1, 4);
    insertTerm(&poly2, -1, 2, 3);
    insertTerm(&poly2, 5, 0, 2);
    printf("First ");
    displayPolynomial(poly1);
    printf("Second ");
    displayPolynomial(poly2);
    struct Term* result = multiplyPolynomials(poly1, poly2);
    printf("Result ");
    displayPolynomial(result);

    return 0;
}
 