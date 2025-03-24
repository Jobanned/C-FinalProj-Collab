#include <stdio.h>
#include <stdlib.h>

void displayWelcomeScreen();
void displayMainMenu();
void inventoryMenu();
void supplierMenu();
void salesMenu();
void searchByName();

int main() {
    int choice;
    
    while (1) {
        system("cls"); // Clear the screen (use "clear" for Linux/MacOS)
        displayWelcomeScreen();
        displayMainMenu();
        
        printf("Please select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
        
        switch (choice) {
            case 1:
                system("cls");
                searchByName();
                break;
            case 2:
                inventoryMenu();
                break;
            case 3:
                supplierMenu();
                break;
            case 4:
                salesMenu();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        
        printf("\nPress Enter to return to the main menu...");
        getchar();
    }
    return 0;
}

void displayWelcomeScreen() {
    printf("\n==========================================\n");
    printf("  Supply Chain Management System\n");
    printf("==========================================\n\n");
}

void displayMainMenu() {
    printf("1. Search\n");
    printf("2. Inventory\n");
    printf("3. Suppliers\n");
    printf("4. Sales\n");
    printf("0. Exit\n");
}

void inventoryMenu() {
    int choice;
    while (1) {
        system("cls");
        printf("\nInventory Menu\n");
        printf("1. View All Inventory\n");
        printf("2. Add Inventory Item\n");
        printf("3. Delete Inventory Item\n");
        printf("4. Update Inventory Item\n");
        printf("0. Back to Main Menu\n");
        printf("Please select an option: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Viewing all inventory...\n");
                break;
            case 2:
                printf("Adding inventory item...\n");
                break;
            case 3:
                printf("Deleting inventory item...\n");
                break;
            case 4:
                printf("Updating inventory item...\n");
                break;
            case 0:
                return;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\nPress Enter to return...");
        getchar();
    }
}

void supplierMenu() {
    int choice;
    while (1) {
        system("cls");
        printf("\nSupplier Menu\n");
        printf("1. View All Suppliers\n");
        printf("2. Add Supplier\n");
        printf("3. Delete Supplier\n");
        printf("4. Update Supplier\n");
        printf("0. Back to Main Menu\n");
        printf("Please select an option: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Viewing all suppliers...\n");
                break;
            case 2:
                printf("Adding supplier...\n");
                break;
            case 3:
                printf("Deleting supplier...\n");
                break;
            case 4:
                printf("Updating supplier...\n");
                break;
            case 0:
                return;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\nPress Enter to return...");
        getchar();
    }
}

void salesMenu() {
    int choice;
    while (1) {
        system("cls");
        printf("\nSales Menu\n");
        printf("1. View All Sales\n");
        printf("2. Add Sale\n");
        printf("3. Weekly Sales Report\n");
        printf("4. Monthly Sales Report\n");
        printf("5. Yearly Sales Report\n");
        printf("0. Back to Main Menu\n");
        printf("Please select an option: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Viewing all sales...\n");
                break;
            case 2:
                printf("Adding sale...\n");
                break;
            case 3:
                printf("Generating weekly sales report...\n");
                break;
            case 4:
                printf("Generating monthly sales report...\n");
                break;
            case 5:
                printf("Generating yearly sales report...\n");
                break;
            case 0:
                return;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\nPress Enter to return...");
        getchar();
    }
}

void searchByName() {
    printf("Searching by name... (Functionality to be implemented)\n");
}
