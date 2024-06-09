

#include <stdio.h>

// Define a structure for representing menu items
typedef struct {
    int id;
    char name[20];
    double price;
} MenuItem;

// Function prototypes
void displayMenu(MenuItem menu[], int size);
void orderCoffee(MenuItem menu[], int choice, int quantity, double payment);

int main() {
    // Define menu items
    MenuItem menu[] = {
        {1, "Espresso", 3.0},
        {2, "Cappuccino", 4.0},
        {3, "Cafe Latte", 5.0},
        {4, "Milkshake", 8.0},
        {5, "Americano", 7.0}
    };

    // Display menu
    displayMenu(menu, sizeof(menu) / sizeof(menu[0]));

    // Get user choice
    int choice, quantity;
    double payment;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter payment amount: ");
    scanf("%lf", &payment);

    // Order coffee
    orderCoffee(menu, choice, quantity, payment);

    return 0;
}

// Function to display the menu
void displayMenu(MenuItem menu[], int size) {
    printf("-----STARBUCKS MENU-----\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// Function to process the order
void orderCoffee(MenuItem menu[], int choice, int quantity, double payment) {
    if (choice >= 1 && choice <= 5) {
        printf("\n-----Your Order-----\n");
        printf("Item: %s\n", menu[choice - 1].name);
        printf("Quantity: %d\n", quantity);
        printf("Total Price: $%.2f\n", menu[choice - 1].price * quantity);
        printf("Payment: $%.2f\n", payment);
        printf("Change: $%.2f\n", payment - (menu[choice - 1].price * quantity));
    } else {
        printf("Invalid choice.\n");
    }
}