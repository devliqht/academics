#include <stdio.h>
#include <string.h>

typedef enum {
    BASIC,
    STANDARD,
    PREMIUM,
    FAMILY,
    UNKNOWN
} SubscriptionPlan;

const char* getInclusions(SubscriptionPlan plan) {
    switch (plan) {
        case BASIC:
            return "Basic Plan: Access to standard-definition content, 1 screen at a time.";
        case STANDARD:
            return "Standard Plan: Access to high-definition content, 2 screens at a time.";
        case PREMIUM:
            return "Premium Plan: Access to ultra-high-definition content, 4 screens at a time.";
        case FAMILY:
            return "Family Plan: Access to all content, 6 screens at a time, includes parental controls.";
        default:
            return "Unknown plan";
    }
}

SubscriptionPlan parseSubscriptionPlan(const char* input) {
    if (strcmp(input, "Basic") == 0) return BASIC;
    if (strcmp(input, "Standard") == 0) return STANDARD;
    if (strcmp(input, "Premium") == 0) return PREMIUM;
    if (strcmp(input, "Family") == 0) return FAMILY;
    return UNKNOWN;
}

int main() {
    char input[50];
    printf("Enter subscription plan (Basic, Standard, Premium, Family): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    SubscriptionPlan plan = parseSubscriptionPlan(input);
    printf("In the %s plan: %s\n", input, getInclusions(plan));

    return 0;
}