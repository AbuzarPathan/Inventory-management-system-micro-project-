#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
// Structure to store product information
struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Function prototypes
void addProduct(struct Product *inventory, int *numProducts);
void updateProduct(struct Product *inventory, int numProducts);
void deleteProduct(struct Product *inventory, int *numProducts);
void displayProducts(struct Product *inventory, int numProducts);

int main() {
clrscr();
    struct Product inventory[100]; // Assuming max 100 products
    int numProducts = 0;
    int choice;

    do {
        // Display menu
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Display Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                updateProduct(inventory, numProducts);
                break;
            case 3:
                deleteProduct(inventory, &numProducts);
                break;
            case 4:
                displayProducts(inventory, numProducts);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void addProduct(struct Product *inventory, int *numProducts) {
    if (*numProducts >= 100) {
        printf("Inventory full. Cannot add more products.\n");
        return;
    }

    printf("Enter product details:\n");
    printf("ID: ");
    scanf("%d", &inventory[*numProducts].id);
    printf("Name: ");
    scanf("%s", inventory[*numProducts].name);
    printf("Quantity: ");
    scanf("%d", &inventory[*numProducts].quantity);
    printf("Price: ");
    scanf("%f", &inventory[*numProducts].price);

    (*numProducts)++;
}

void updateProduct(struct Product *inventory, int numProducts) {
    int id, found = 0;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            found = 1;
            printf("Product updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

void deleteProduct(struct Product *inventory, int *numProducts) {
    int id, found = 0;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *numProducts; i++) {
        if (inventory[i].id == id) {
            // Shift elements to the left to overwrite the deleted product
            for (int j = i; j < *numProducts - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*numProducts)--;
            found = 1;
            printf("Product deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

void displayProducts(struct Product *inventory, int numProducts) {
    printf("Product ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}
    