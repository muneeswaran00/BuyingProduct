#include <stdio.h>

int cid = 0;
int pid = 0; 
int bid = 0;

struct Customer {
    char cusName[50];
    char cusPhno[15];
    int cusId;
} cus[100];
struct Product {
    char prodName[50];
    float prodPrice;
    int prodId;
    int stock;
} prod[100];
struct Bill {
    int billId;
    int cusId;
    int prodId;
    int quantity;
    float totalCost;
} bill[100];
void createCustomer() {
    printf("Enter Your Name: ");
    scanf("%s", cus[cid].cusName);
    printf("Enter Your Number: ");
    scanf("%s", cus[cid].cusPhno);
    cus[cid].cusId = cid + 1;
    printf("=====> Data Entered Successfully <====\n");
    printf("Your Customer ID is: %d\n", cus[cid].cusId);
    cid++;
}
void displayCustomers() {
    for (int i = 0; i < cid; i++) {
        printf("\nCustomer ID: %d\n", cus[i].cusId);
        printf("Customer Name: %s\n", cus[i].cusName);
        printf("Customer Phone Number: %s\n", cus[i].cusPhno);
    }
}
void createProduct() {
    printf("Enter Product Name: ");
    scanf("%s", prod[pid].prodName);
    printf("Enter Product Price: ");
    scanf("%f", &prod[pid].prodPrice);
    printf("Enter Stock Quantity: ");
    scanf("%d", &prod[pid].stock);
    prod[pid].prodId = pid + 1;
    printf("=====> Product Entered Successfully <====\n");
    printf("Product ID: %d\n", prod[pid].prodId);
    pid++;
}
void displayProducts() {
    for (int i = 0; i < pid; i++) {
        printf("\nProduct ID: %d\n", prod[i].prodId);
        printf("Product Name: %s\n", prod[i].prodName);
        printf("Product Price: %.2f\n", prod[i].prodPrice);
        printf("Product Stock: %d\n", prod[i].stock);
    }
}
int verifyCustomer(int id) {
    for (int i = 0; i < cid; i++) {
        if (cus[i].cusId == id)
            return 1;
    }
    return 0;
}
void createBill() {
    int id, prodId, qty;
    printf("Enter Customer ID: ");
    scanf("%d", &id);

    if (!verifyCustomer(id)) {
        printf("Invalid Customer ID\n");
        return;
    }

    displayProducts();
    printf("Enter Product ID: ");
    scanf("%d", &prodId);
    printf("Enter Quantity: ");
    scanf("%d", &qty);

    if (prod[prodId - 1].stock < qty) {
        printf("Insufficient Stock!\n");
        return;
    }

    bill[bid].billId = bid + 1;
    bill[bid].cusId = id;
    bill[bid].prodId = prodId;
    bill[bid].quantity = qty;
    bill[bid].totalCost = qty * prod[prodId - 1].prodPrice;
    prod[prodId - 1].stock -= qty;

    printf("=====> Bill Created Successfully <====\n");
    printf("Total Cost: %.2f\n", bill[bid].totalCost);
    printf("Remaining Stock: %d\n", prod[prodId - 1].stock);
    bid++;
}



void displayBills() {
    for (int i = 0; i < bid; i++) {
        printf("\nBill ID: %d\n", bill[i].billId);
        printf("Customer Name: %s\n", cus[bill[i].cusId - 1].cusName);
        printf("Product Name: %s\n", prod[bill[i].prodId - 1].prodName);
        printf("Quantity: %d\n", bill[i].quantity);
        printf("Total Cost: %.2f\n", bill[i].totalCost);
    }
}

int main() {
    while (1) {
        int n;
        printf("1) Create Customer\n 2) Display Customers\n 3) Create Product\n 4) Display Products\n 5) Buy Product\n 6) Display Bills\n Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1: {
                createCustomer(); 
                break;
                }
            case 2: {
                displayCustomers(); 
                break;
            }
            case 3:{ 
                createProduct(); 
                break;
            }
            case 4: {
                displayProducts(); 
                break;
            }
            case 5: {
                createBill(); 
                break;
            }
            case 6: {
                displayBills(); 
                break;
            }
            
        }
    }

    return 0;
}
