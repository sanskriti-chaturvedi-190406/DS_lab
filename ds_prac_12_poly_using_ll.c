#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;           // Coefficient
    int pow;             // Power (exponent)
    struct Node* next;   // Pointer to next term
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial (in descending order of power)
void insertTerm(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);

    // If list is empty or new term has higher power
    if (*poly == NULL || pow > (*poly)->pow) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        struct Node* prev = NULL;

        while (temp != NULL && temp->pow > pow) {
            prev = temp;
            temp = temp->next;
        }

        // If same power, add coefficients
        if (temp != NULL && temp->pow == pow) {
            temp->coeff += coeff;
            free(newNode);
            return;
        }

        // Otherwise insert new term
        newNode->next = temp;
        if (prev != NULL)
            prev->next = newNode;
    }
}

// Function to display a polynomial
void displayPoly(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertTerm(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            insertTerm(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // If any terms left in poly1
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    // If any terms left in poly2
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Function to create polynomial by user input
struct Node* createPolynomial() {
    struct Node* poly = NULL;
    int n, coeff, pow;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power of term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertTerm(&poly, coeff, pow);
    }

    return poly;
}

// Main function
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    printf("Enter first polynomial:\n");
    poly1 = createPolynomial();

    printf("\nEnter second polynomial:\n");
    poly2 = createPolynomial();

    printf("\nFirst Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    sum = addPolynomials(poly1, poly2);
    printf("\nResultant Polynomial after Addition: ");
    displayPoly(sum);

    return 0;
}
