#include <stdio.h>
#include <string.h>

void ComputePetAge(float age, char* petType);
void PetServiceIdentifier(char* petType);

int main() {
    float age, finalAge = 0;
    char petType[20];
    printf("Enter your pet's age in years: "); scanf("%f", &age);
    printf("Enter your pet type: "); scanf("%s", &petType);
    ComputePetAge(age, petType);
    PetServiceIdentifier(petType);

    return 0;
}

void ComputePetAge(float age, char* petType) {
    float finalAge = 0;
    if (strcmp(petType, "dog") == 0) {
        if (age <= 2) {
            finalAge = age*10.5;
        } else if (age > 2) {
            finalAge = 21+(age-2)*4;
        }
    } else if (strcmp(petType, "cat") == 0) {
        if (age <= 20) {
            finalAge = age * 12.5;
        } else if (age > 2) {
            finalAge = 25+(age-2)*4;
        }
    } else if (strcmp(petType, "bird") == 0) {
        finalAge = ((age*5)+2) + (4 * (age-1));
    } else if (strcmp(petType, "rabbit") == 0) {
        finalAge = ((age*6)+1) + (4 * (age-1));
    } else {
        printf("Invalid type of pet.");
    }
    if (finalAge > 0)
        printf("Your pet in human age is: %.2lf", finalAge);
}

void PetServiceIdentifier(char* petType) {
    printf("\nRecommended Services: ");
    if (strcmp(petType, "dog") == 0) {
        printf("\nGrooming\nTraining\nVaccinations\nDog walking");
    } else if (strcmp(petType, "cat") == 0) {
        printf("\nGrooming\nLitter box training\nVaccinations\nFlea Treatment");
    } else if (strcmp(petType, "bird") == 0) {
        printf("\nCage Cleaning\nNail Clipping\nHealth Check-ups\nSocial Interaction");
    } else if (strcmp(petType, "rabbit") == 0) {
        printf("\nGrooming\nHealth Check-ups\nProper Habitat setup");
    } else {
        printf("\nNo recommended services. Pet type is invalid.");
    }
}