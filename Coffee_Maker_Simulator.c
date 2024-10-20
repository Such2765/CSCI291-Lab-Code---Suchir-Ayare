    // Coffee Maker Simulator Task
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Constant Coffee Quantity Requirements (ml)
#define espresso_Beans 8
#define espresso_Water 30

#define cappuccino_Beans 8
#define cappuccino_Water 30
#define cappuccino_Milk 70

#define mocha_Beans 8
#define mocha_Water 39
#define mocha_Milk 160
#define mocha_ChocoSyrup 30

// Variable Coffee Prices (AED) (Can Be Changed)
float espresso_Price = 3.50;
float cappuccino_Price = 4.50;
float mocha_Price = 5.50;
float total_amount = 0.00;

// Admin Details 
#define admin_Password "8488071"

// Threshold Value For Coffee Ingredients (ml)
#define threshold_Beans 10
#define threshold_Water 50
#define threshold_Milk 200
#define threshold_ChocoSyrup 50

// Current Avaliable Machine Ingredient (ml)
int coffeeBeans = 300;
int water = 500;
int milk = 1000;
int chocoSyrup = 200;

// Predefined Functions Used In Main Code
void adminInterface();
void customerInterface();
void displayIngredients();
void replenishIngredients();
void changePrices();
void resetSales();
void checkLowIngredients();

int main() {
    // Predefined Variables Used In Main Code
    int entry;
    
    // WHILE Loop To Execute Recurring Interface 
    while (1){
        printf("\nWelcome To Molly's Cafe!");
        printf("\nInput 1 If You Are An Admin & 2 If You Would Like To Order A Coffee.\n");
        scanf("%d", &entry);
        
        switch(entry) {
            case 1: adminInterface();
                break;
            case 2: customerInterface();
                break;
            default:
                printf("Invalid Choice Please Try Again!\n\n");
        }
    }
    return 0;
}

// Function For Admin Interface
void adminInterface() { 
    char adminKey[7];
    int adminTask;
    
    // Admin Key Verifier
    printf("\nEnter Admin Key - ");
    scanf("%s", adminKey);
    if (strcmp(adminKey, admin_Password) != 0) {
        printf("Incorrect Key! Access Denied!.\n\n");
        return;
    }
    
    // Choosing Admin Task With Infinite Loop
    while (1){
        printf("\nWelcome Admin! Choose Task Based On Its Corresponding Numbers.");
        printf("\n--------------- ADMIN TASKS ---------------");
        printf("\n1: Display current ingredient quantity and total sale amount");
        printf("\n2: Replenish ingredients in the machine");
        printf("\n3: Change coffee price");
        printf("\n4: Reset Total Sales");
        printf("\n0: Exit the Admin Mode function");
        printf("\nChosen Task - ");
        scanf("%d", &adminTask);
        
        switch (adminTask) {
            case 1: displayIngredients(); 
                break;
            case 2: replenishIngredients(); 
                break;
            case 3: changePrices(); 
                break;
            case 4: resetSales(); 
                break;
            case 0: 
                return;
            default: 
                printf("Invalid Task Selection! Please Try Again.\n\n");
        }
    }
}

// Function For Displaying Ingredients To Admin
void displayIngredients() {
    printf("\nYou Have Chosen To See Current Amount Of Coffee Ingredients.");
    printf("\n------------ Coffee Ingredients Avaliable ------------");
    printf("\nCurrent Quantity Of Coffee Beans:  %d ml",coffeeBeans);
    printf("\nCurrent Quantity Of Water:  %d ml",water);
    printf("\nCurrent Quantity Of Milk:  %d ml",milk);
    printf("\nCurrent Quantity Of Chocolate Syrup: %d ml\n\n",chocoSyrup);
}

// Function For Replenishing Ingredients (Admin Task)
void replenishIngredients() {
    int replenIng;
    
    printf("\nWhich Ingredient Would You Like To Replenish? Input The Corresponding Integer To Represent Your Choice.");
    printf("\n1 - Coffee, 2 - Water, 3 - Milk, 4 - Chocolate Syrup, 5 - All Of Them, 0 - Choose Another Admin Task.\n");
    scanf("%d", &replenIng);
        
        switch (replenIng) {
            //Value changed by random. Range set between 2 numbers using %
            case 1: coffeeBeans = rand() % 301 + 450; 
                break;
            case 2: water = rand() % 501 + 750; 
                break;
            case 3: milk = rand() % 751 + 1000; 
                break;
            case 4: chocoSyrup = rand() % 201 + 300;
                break;
            case 5: 
                coffeeBeans = rand() % 301 + 450;
                water = rand() % 501 + 750;
                milk = rand() % 751 + 1000;
                chocoSyrup = rand() % 201 + 300;
                break;
            default: 
                printf("You Haven't Chosen An Ingredient To Replenish. Returning To Main Screen.");
                return;
        }
        
    printf("\n------------ Replenished Coffee Ingredients ------------");
    printf("\nCurrent Quantity Of Coffee Beans:  %d ml",coffeeBeans);
    printf("\nCurrent Quantity Of Water:  %d ml",water);
    printf("\nCurrent Quantity Of Milk:  %d ml",milk);
    printf("\nCurrent Quantity Of Chocolate Syrup: %d ml\n\n",chocoSyrup);
    return;
}

// Function For Changing Coffee Prices 
void changePrices() {
    printf("\nEnter Prices Following A Decimal With Two Decimal Point Fromat, Example - 4.50, And Must Be Set In A Price That Can Be Paid With Only AED 1 And AED 0.5 Coins.");
    printf("\nInput New Price For Espresso - ");
    scanf("%f", &espresso_Price);
    printf("\nInput New Price For Cappuccino - ");
    scanf("%f", &cappuccino_Price);
    printf("\nInput New Price For Mocha - ");
    scanf("%f", &mocha_Price);
    
    printf("\n ----- Updated Prices Coffee Menu -----");
    printf("\n1) Espresso      %.2f AED",espresso_Price);
    printf("\n2) Cappuccino    %.2f AED",cappuccino_Price);
    printf("\n3) Mocha         %.2f AED\n",mocha_Price);
    }

// Function For Reset Total Sales Made
void resetSales() {
    char resetSales;
    
    printf("You Have Chosen To Reset The Total Sales.");
    printf("Current Total Sales: %.2f AED\n", total_amount);
    printf("Would you like to reset the sales amount to 0? (y/n): ");
    scanf(" %c", &resetSales);

    if (resetSales == 'y' || resetSales == 'Y') {
        total_amount = 0.0;
        printf("Total Sales Have Been Reset, Please Remove Today's In From The Dispenser Below.\n");
    } else {
        printf("Total Sales Amount Was Not Reset.\n");
    }
}

// Function For Customer Interface
void customerInterface() {
    int coffeeChoice;
    char confirmChoice;
    float balancePrice;
    float coins;
    float userInputPrice = 0.0;
    float change;
    char recipt;
    
    //Conditions To Provide User Information Whether Their Preferred Coffee Is Avaliable Or Not
    printf("\nWelcome Customer! Please Select Your Preferred Coffee By Inputting 1 For Expresso, 2 For Cappuccino And 3 For Mocha.");
    printf("\n ----- COFFEE MENU -----");
    if (coffeeBeans >= espresso_Beans && water >= espresso_Water){
        printf("\n1) Espresso      %.2f AED",espresso_Price);
    } else {
        printf("Sorry! Espresso Is Currently Unavailable Due To Temporarily Insuﬃcient Ingredients\n");
        }
    if (coffeeBeans >= cappuccino_Beans && water >= cappuccino_Water && milk >= cappuccino_Milk){
        printf("\n2) Cappuccino    %.2f AED",cappuccino_Price);
    } else {
        printf("Sorry! Cappuccino Is Currently Unavailable Due To Temporarily Insuﬃcient Ingredients\n");
    }
    if (coffeeBeans >= mocha_Beans && water >= mocha_Water && milk >= mocha_Milk && chocoSyrup >= mocha_ChocoSyrup){
        printf("\n3) Mocha         %.2f AED",mocha_Price);
    } else {
        printf("Sorry! Mocha Is Currently Unavailable Due To Temporarily Insuﬃcient Ingredients\n");
    }
    
    // Allow User To Input Their Preferred Coffee Choice
    printf("\nEnter Your Coffee Choice: ");
    scanf("%d", &coffeeChoice);
    
    //A switch statement to provide a specific and general value for the balance price the user has to pay to get the coffee.
    switch (coffeeChoice) {
        case 1:balancePrice = espresso_Price; 
        case 2:balancePrice = cappuccino_Price; 
        case 3:balancePrice = mocha_Price; 
    }   
    
    // Allows Confimation Of Choice Of Coffee
    printf("You have Choosen Coffee Option %d.",coffeeChoice);
    printf("Would You Like To Change Your Choice? (Y/N): \n");
    scanf(" %c", &confirmChoice);
    
    if (confirmChoice == 'Y'||confirmChoice == 'y'){
        printf("You Have Chosen To Change Your Decision!\n");
        customerInterface();
    } else if (confirmChoice == 'N'||confirmChoice == 'n'){
        printf("\nYou Have Not Chosen To Change Your Decision!\n");
        printf("Your Balance For Your Chosen Coffee Is %.2f AED\n",balancePrice);
    
        
        //Continuous Loop To Allow User To Make Full Payment Assiming User Is Going TO Exact Amount.
        while (userInputPrice < balancePrice) {
            printf("Input 1.0 to enter 1.00 AED and 0.5 to enter 0.50 AED\n");
            scanf("%f",&coins);
                if (coins == 1 || coins == 0.5) {
                    userInputPrice += coins;
                    printf("You Have Inserted: %.2f AED\n", userInputPrice);
                } else {
                    printf("Invalid Input! Please Collect The Incorrect Coins And Continue With Valid Coins.\n");
                }
            }
            
        // Once The Payment Is Completed   
        if (userInputPrice == balancePrice){
            printf("Enjoy your coffee! You paid %.2f AED.\n", userInputPrice);
            total_amount = total_amount + userInputPrice;//Update total sales amount
            
        } else if (userInputPrice > balancePrice){
            change = userInputPrice - balancePrice;
            printf("\nEnjoy your coffee! You paid %.2f AED.\n", userInputPrice);
            printf("And here is your remaining change of %.2f AED.\n",change);
            total_amount = total_amount + userInputPrice;
        }
        
        // Set Of Commands That Will Update The Current Amount Of Ingredients Used After The Payment Has Been Made. 
        if (coffeeChoice == 1 && ((userInputPrice == balancePrice)||(userInputPrice > balancePrice))){
            //Subtracting The Amount Used To Make This Coffee By Current Total Amount Of Ingredient
            coffeeBeans = coffeeBeans - espresso_Beans;
            water = water - espresso_Water;
        
        } else if (coffeeChoice == 2 && ((userInputPrice == balancePrice)||(userInputPrice > balancePrice))){
            coffeeBeans = coffeeBeans - cappuccino_Beans;
            water = water - cappuccino_Water;
            milk = milk - cappuccino_Milk;
            
        } else if (coffeeChoice == 3 && ((userInputPrice == balancePrice)||(userInputPrice > balancePrice))){
            coffeeBeans = coffeeBeans - mocha_Beans;
            water = water - mocha_Water;
            milk = milk - mocha_Milk;
            chocoSyrup = chocoSyrup - mocha_ChocoSyrup;
        }
        
        // Allows The User To Choose Whether Or Not They Would Like A Transcipt Of Their Purchase
        printf("\nHere Is A Transcript Of Your Purchase: :\n");
        printf("--------- RECIPT ----------");
            if (coffeeChoice == 1){
                printf("\nCoffee Type -     Espresso");
            } else if (coffeeChoice == 2){
                printf("\nCoffee Type -   Cappuccino");
            } else if (coffeeChoice == 3){
                printf("\nCoffee Type -        Mocha");
            }
        printf("\nPrice -           %.2f AED",balancePrice);
        printf("\nAmount Paid -     %.2f AED ",userInputPrice);         
        printf("\nChange Recieved - %.2f AED\n",change);            
        printf("\nThank You For Choosing To Purchase From Molly's Cafe, Please Come Again!\n");
    
    } else {
        printf("You Have Inputted An Incorrect Choice, Input Either Y or N!\n");
        return;
    }
}

//WARNINGS Provided To The User When The Ingredients Are Less Than The Threshold Value Set.
void checkLowIngredients() {
    if (coffeeBeans <= threshold_Beans)
        printf("WARNING - COFFEE BEANS VOLUME LOW!\n");
    if (water <= threshold_Water)
        printf("WARNING - COFFEE WATER LEVEL LOW!\n");
    if (milk <= threshold_Milk)
        printf("WARNING - COFFEE MILK LEVEL LOW!\n");
    if (chocoSyrup <= threshold_ChocoSyrup)
        printf("WARNING - COFFEE CHOCOLATE SYRUP LEVEL LOW!\n");
}
