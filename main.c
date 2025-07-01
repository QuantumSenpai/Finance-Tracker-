/* 
   Kisu's Finance Tracker - Clean Edition
   --------------------------------------
   Created to manage personal expenses using C.
   Focused on simplicity, terminal-based interface, and practical logic.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[30];
    float amount;
    char date[20];
};

int addExpense() {
    FILE *fp = fopen("kisu_expenses.txt", "a");
    struct Expense e;
    printf("\nEnter category: ");
    scanf(" %[^
]", e.category);
    printf("Enter amount: ");
    scanf("%f", &e.amount);
    printf("Enter date (DD-MM-YYYY): ");
    scanf(" %[^
]", e.date);
    fprintf(fp, "%s,%.2f,%s\n", e.category, e.amount, e.date);
    fclose(fp);
    printf("Expense added successfully.\n");
    return 0;
}

int viewSummary() {
    FILE *fp = fopen("kisu_expenses.txt", "r");
    struct Expense e;
    float total = 0;
    char line[100];
    printf("\nExpense Summary:\n");
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%f,%[^
]", e.category, &e.amount, e.date);
        printf("%s | ₹%.2f | %s\n", e.date, e.amount, e.category);
        total += e.amount;
    }
    fclose(fp);
    printf("\nTotal Spent: ₹%.2f\n", total);
    return 0;
}

int checkBudget() {
    float budget, spent = 0;
    FILE *fp = fopen("kisu_expenses.txt", "r");
    struct Expense e;
    char line[100];
    printf("Enter your monthly budget (₹): ");
    scanf("%f", &budget);
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%f,%[^
]", e.category, &e.amount, e.date);
        spent += e.amount;
    }
    fclose(fp);
    printf("\nTotal Spent: ₹%.2f\n", spent);
    if (spent > budget) {
        printf("Over Budget by ₹%.2f\n", spent - budget);
    } else {
        printf("Within Budget! Remaining: ₹%.2f\n", budget - spent);
    }
    return 0;
}

int generateReport() {
    FILE *in = fopen("kisu_expenses.txt", "r");
    FILE *out = fopen("kisu_report.txt", "w");
    struct Expense e;
    float total = 0;
    char line[100];
    fprintf(out, "Kisu's Expense Report\n--------------------------\n");
    while (fgets(line, sizeof(line), in)) {
        sscanf(line, "%[^,],%f,%[^
]", e.category, &e.amount, e.date);
        fprintf(out, "%s | ₹%.2f | %s\n", e.date, e.amount, e.category);
        total += e.amount;
    }
    fprintf(out, "\nTotal Spent: ₹%.2f\n", total);
    fclose(in);
    fclose(out);
    printf("Report generated: kisu_report.txt\n");
    return 0;
}

int main() {
    int choice;
    do {
        printf("\n--- KISU FINANCE TRACKER ---\n");
        printf("1. Add Expense\n");
        printf("2. View Summary\n");
        printf("3. Check Budget\n");
        printf("4. Generate Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewSummary(); break;
            case 3: checkBudget(); break;
            case 4: generateReport(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
    return 0;
}
