#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_SUPPLIERS "suppliers.txt"
#define FILE_SALES "sales.txt"
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} InventoryItem;
//testing
typedef struct {
    int id;
    char name[50];
    char contact[30];
} Supplier;

typedef struct {
    int id;
    char itemName[50];
    int quantitySold;
    float totalPrice;
    char date[20];
    float amount;
} Sale;

void displayWelcomeScreen();
void displayMainMenu();
void inventoryMenu();
void supplierMenu();
void salesMenu();
void searchByName();

void viewInventory() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No inventory records found.\n");
        return;
    }

    InventoryItem item;
    printf("\nID\tName\t\tQuantity\tPrice\n");
    printf("----------------------------------------\n");
    while (fscanf(file, "%d %s %d %f", &item.id, item.name, &item.quantity, &item.price) != EOF) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", item.id, item.name, item.quantity, item.price);
    }

    fclose(file);
}
void addInventoryItem() {
    FILE *file = fopen("inventory.txt", "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    InventoryItem item;
    printf("Enter Item ID: ");
    while (scanf("%d", &item.id) != 1) {
        printf("Invalid input. Enter a valid ID: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    printf("Enter Name: ");
    getchar(); // To clear newline left by previous scanf
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strcspn(item.name, "\n")] = 0; // Remove newline
    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter Price: ");
    scanf("%f", &item.price);

    fprintf(file, "%d %s %d %.2f\n", item.id, item.name, item.quantity, item.price);
    fclose(file);

    printf("Item added successfully!\n");
}
void deleteInventoryItem(int deleteID) {
    FILE *file = fopen("inventory.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file) {
        printf("No inventory records found.\n");
        fclose(temp);
        return;
    }
    /*if (!file || !temp) {
        printf("Error opening file!\n");
        return;
    }*/

    InventoryItem item;
    int found = 0;

    while (fscanf(file, "%d %s %d %f", &item.id, item.name, &item.quantity, &item.price) != EOF) {
        if (item.id != deleteID) {
            fprintf(temp, "%d %s %d %.2f\n", item.id, item.name, item.quantity, item.price);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found)
        printf("Item deleted successfully!\n");
    else
        printf("Item not found!\n");
}
void viewSuppliers() {
    FILE *file = fopen("suppliers.txt", "r");
    if (!file) {
        printf("No supplier records found.\n");
        return;
    }

    Supplier sup;
    printf("\nID\tName\t\tContact\n");
    printf("--------------------------------\n");
    while (fscanf(file, "%d %s %s", &sup.id, sup.name, sup.contact) != EOF) {
        printf("%d\t%s\t\t%s\n", sup.id, sup.name, sup.contact);
    }

    fclose(file);
}
void addSupplier() {
    FILE *file = fopen("suppliers.txt", "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Supplier sup;
    printf("Enter Supplier ID: ");
    scanf("%d", &sup.id);
    printf("Enter Name: ");
    scanf("%s", sup.name);
    printf("Enter Contact: ");
    scanf("%s", sup.contact);

    fprintf(file, "%d %s %s\n", sup.id, sup.name, sup.contact);
    fclose(file);

    printf("Supplier added successfully!\n");
}
void deleteSupplier() {
    FILE *file = fopen(FILE_SUPPLIERS, "r");
    FILE *temp = fopen("temp.txt", "w");
    
    if (!file || !temp) {
        printf("Error opening file!\n");
        return;
    }
    
    int targetId, found = 0;
    printf("Enter Supplier ID to delete: ");
    scanf("%d", &targetId);
    
    Supplier supplier;
    while (fscanf(file, "%d %49s %49s", &supplier.id, supplier.name, supplier.contact) != EOF) {
        if (supplier.id == targetId) {
            found = 1;
            continue;
        }
        fprintf(temp, "%d %s %s\n", supplier.id, supplier.name, supplier.contact);
    }
    
    fclose(file);
    fclose(temp);
    
    if (found) {
        remove(FILE_SUPPLIERS);
        rename("temp.txt", FILE_SUPPLIERS);
        printf("Supplier deleted successfully!\n");
    } else {
        printf("Supplier not found!\n");
    }
}
void updateSupplier() {
    FILE *file = fopen(FILE_SUPPLIERS, "r");
    FILE *temp = fopen("temp.txt", "w");
    
    if (!file || !temp) {
        printf("Error opening file!\n");
        return;
    }
    
    int targetId, found = 0;
    printf("Enter Supplier ID to update: ");
    scanf("%d", &targetId);
    
    Supplier supplier;
    while (fscanf(file, "%d %49s %49s", &supplier.id, supplier.name, supplier.contact) != EOF) {
        if (supplier.id == targetId) {
            found = 1;
            printf("Enter new Name: ");
            scanf("%s", supplier.name);
            printf("Enter new Contact: ");
            scanf("%s", supplier.contact);
        }
        fprintf(temp, "%d %s %s\n", supplier.id, supplier.name, supplier.contact);
    }
    
    fclose(file);
    fclose(temp);
    
    if (found) {
        remove(FILE_SUPPLIERS);
        rename("temp.txt", FILE_SUPPLIERS);
        printf("Supplier updated successfully!\n");
    } else {
        printf("Supplier not found!\n");
    }
}

void viewSales() {
    FILE *file = fopen("sales.txt", "r");
    if (!file) {
        printf("No sales records found.\n");
        return;
    }

    Sale sale;
    printf("\nID\tItem Name\tQuantity\tTotal Price\n");
    printf("------------------------------------------------\n");
    while (fscanf(file, "%d %s %d %f", &sale.id, sale.itemName, &sale.quantitySold, &sale.totalPrice) != EOF) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", sale.id, sale.itemName, sale.quantitySold, sale.totalPrice);
    }

    fclose(file);
}
void addSale() {
    FILE *file = fopen("sales.txt", "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Sale sale;
    printf("Enter Sale ID: ");
    scanf("%d", &sale.id);
    printf("Enter Item Name: ");
    scanf("%s", sale.itemName);
    printf("Enter Quantity Sold: ");
    scanf("%d", &sale.quantitySold);
    printf("Enter Total Price: ");
    scanf("%f", &sale.totalPrice);

    fprintf(file, "%d %s %d %.2f\n", sale.id, sale.itemName, sale.quantitySold, sale.totalPrice);
    fclose(file);

    printf("Sale recorded successfully!\n");
}
void generateSalesReport(const char *period) {
    FILE *file = fopen(FILE_SALES, "r");
    if (!file) {
        printf("Error opening sales file!\n");
        return;
    }
    
    Sale sale;
    float total = 0;
    printf("Sales Report (%s)\n", period);
    printf("--------------------------------\n");
    while (fscanf(file, "%d %19s %f", &sale.id, sale.date, &sale.amount) != EOF) {
        // In real implementation, filter sales based on the period (week/month/year)
        total += sale.amount;
    }
    fclose(file);
    printf("Total Sales: ₱%.2f\n", total);
}

void weeklySalesReport() { generateSalesReport("Weekly"); }
void monthlySalesReport() { generateSalesReport("Monthly"); }
void yearlySalesReport() { generateSalesReport("Yearly"); }

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
        printf("\nInventory Menu\n");
        printf("1. View All Inventory\n");
        printf("2. Add Inventory Item\n");
        printf("3. Delete Inventory Item\n");
        printf("0. Back to Main Menu\n");
        printf("Please select an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                viewInventory();
                break;
            case 2:
                addInventoryItem();
                break;
            case 3:
                printf("Enter Item ID to delete: ");
                int id;
                scanf("%d", &id);
                deleteInventoryItem(id);
                break;
            case 0:
                return;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
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
               viewSuppliers();
                break;
            case 2:
               addSupplier();
                break;
            case 3:
               deleteSupplier();
                break;
            case 4:
             updateSupplier();
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
                viewSales();
                break;
            case 2:
                addSale();
                break;
            case 3:
              weeklySalesReport();
                break;
            case 4:
                monthlySalesReport();
                break;
            case 5:
               yearlySalesReport();
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
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No inventory records found.\n");
        return;
    }

    char searchName[50];
    printf("Enter item name to search: ");
    scanf("%s", searchName);

    InventoryItem item;
    int found = 0;

    while (fscanf(file, "%d %s %d %f", &item.id, item.name, &item.quantity, &item.price) != EOF) {
        if (strcmp(item.name, searchName) == 0) {
            printf("\nFound: %d %s %d %.2f\n", item.id, item.name, item.quantity, item.price);
            found = 1;
        }
    }

    fclose(file);

    if (!found)
        printf("Item not found!\n");
}
