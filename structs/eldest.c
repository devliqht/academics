#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
} Sibling;

int main() {
    int n;
    Sibling *siblings;
    FILE *siblingsFile, *eldestFile;

    // Ask for the number of siblings
    printf("Enter the number of siblings: ");
    scanf("%d", &n);
    getchar(); // Consume newline character left by scanf

    // Handle case where number of siblings is 0 or negative
    if (n <= 0) {
        printf("No siblings to record.\n");
        return 0;
    }

    // Allocate memory for siblings
    siblings = (Sibling *)malloc(n * sizeof(Sibling));
    if (siblings == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Collect sibling details
    for (int i = 0; i < n; i++) {
        printf("Enter sibling %d details:\n", i + 1);
        printf("Name: ");
        fgets(siblings[i].name, NAME_LENGTH, stdin);
        // Remove newline character if present
        siblings[i].name[strcspn(siblings[i].name, "\n")] = '\0';
        printf("Age: ");
        scanf("%d", &siblings[i].age);
        getchar(); // Consume newline character left by scanf
    }

    // Save sibling details to siblings.txt
    siblingsFile = fopen("siblings.txt", "w");
    if (siblingsFile == NULL) {
        fprintf(stderr, "Error opening file siblings.txt\n");
        free(siblings);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(siblingsFile, "%s, Age: %d\n", siblings[i].name, siblings[i].age);
    }
    fclose(siblingsFile);

    // Identify the eldest sibling
    Sibling eldest = siblings[0];
    for (int i = 1; i < n; i++) {
        if (siblings[i].age > eldest.age) {
            eldest = siblings[i];
        }
    }

    // Save the eldest sibling's name to eldest.txt
    eldestFile = fopen("eldest.txt", "w");
    if (eldestFile == NULL) {
        fprintf(stderr, "Error opening file eldest.txt\n");
        free(siblings);
        return 1;
    }
    fprintf(eldestFile, "%s\n", eldest.name);
    fclose(eldestFile);

    // Display the list of siblings and the eldest sibling
    printf("\nList of Siblings:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s, Age: %d\n", i + 1, siblings[i].name, siblings[i].age);
    }
    printf("The eldest sibling is %s.\n", eldest.name);

    // Free allocated memory
    free(siblings);

    return 0;
}