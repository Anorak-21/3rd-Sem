#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coef, int exp) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->coefficient = coef;
    term->exponent = exp;
    term->next = NULL;
    return term;
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* tail = NULL;

    while (poly1 && poly2) {
        if (poly1->exponent > poly2->exponent) {
            if (result == NULL) {
                result = createTerm(poly1->coefficient, poly1->exponent);
                tail = result;
            } else {
                tail->next = createTerm(poly1->coefficient, poly1->exponent);
                tail = tail->next;
            }
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            if (result == NULL) {
                result = createTerm(poly2->coefficient, poly2->exponent);
                tail = result;
            } else {
                tail->next = createTerm(poly2->coefficient, poly2->exponent);
                tail = tail->next;
            }
            poly2 = poly2->next;
        } else {
            int sum_coef = poly1->coefficient + poly2->coefficient;
            if (sum_coef != 0) {
                if (result == NULL) {
                    result = createTerm(sum_coef, poly1->exponent);
                    tail = result;
                } else {
                    tail->next = createTerm(sum_coef, poly1->exponent);
                    tail = tail->next;
                }
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        if (result == NULL) {
            result = createTerm(poly1->coefficient, poly1->exponent);
            tail = result;
        } else {
            tail->next = createTerm(poly1->coefficient, poly1->exponent);
            tail = tail->next;
        }
        poly1 = poly1->next;
    }

    while (poly2) {
        if (result == NULL) {
            result = createTerm(poly2->coefficient, poly2->exponent);
            tail = result;
        } else {
            tail->next = createTerm(poly2->coefficient, poly2->exponent);
            tail = tail->next;
        }
        poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    while (poly) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Term* poly1 = createTerm(3, 2);
    poly1->next = createTerm(4, 1);
    poly1->next->next = createTerm(5, 0);

    struct Term* poly2 = createTerm(1, 2);
    poly2->next = createTerm(2, 1);
    poly2->next->next = createTerm(3, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Term* sum = addPolynomials(poly1, poly2);

    printf("Sum of the polynomials: ");
    displayPolynomial(sum);

    return 0;
}
