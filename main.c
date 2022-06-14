//
//  main.c
//  TradingFrormulaApp2
//
//  Created by shanego416
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void calculateProfit(void);
void calculateProfitPercentage(void);
void calculateLossPercentage(void);
void calculateStopLossPrice(void);
void calculateSellPointPrice(void);
void calculateNewAvg(void);
void calculatePercentage(void);

int main() {
    
    int menuSelection;
    int yesOrNo;
    
    do {
        printf("\n");
        printf("\n                  Trading Calculater              \n");
        printf("           ------------------------------\n\n");
        printf("                        MENU                       \n");
        printf("|--------------------------------------------------|\n");
        printf("|    1. Calculate Profit                           |\n");
        printf("|    2. Calculate Profit Percentage                |\n");
        printf("|    3. Calculate Loss Percentage                  |\n");
        printf("|    4. Calculate Stop Loss Sell Point             |\n");
        printf("|    5. Calculate Profit Sell Point / Limit Sell   |\n");
        printf("|    6. Calculate Average Price After New Purchase |\n");
        printf("|    7. Calculate a Percentage of a Number         |\n");
        printf("|    0. Quit                                       |\n");
        printf("|--------------------------------------------------|\n");
        printf("\nEnter a number from the menu to make a selction: >");
        scanf("%d", &menuSelection);
        
        if (menuSelection == 1) {
            calculateProfit();
        }
        else if (menuSelection == 2){
            calculateProfitPercentage();
        }
        else if (menuSelection == 3){
            calculateLossPercentage();
        }
        else if (menuSelection == 4){
            calculateStopLossPrice();
        }
        else if (menuSelection == 5){
            calculateSellPointPrice();
        }
        else if (menuSelection == 6){
            calculateNewAvg();
        }
        else if (menuSelection == 7){
            calculatePercentage();
        }
        else if (menuSelection == 0){
            printf("\nAre you sure?\n");
        }
        else{
            printf("\nInvalid Input. Please enter a number from the menu.\n");
        }
        
        getchar(); // gets an accidental input of a char from the stdin buffer
        while ((getchar()) != '\n'); // This clears the input buffer upto '\n' to prevent buffer overflow
        
        printf("\nAnother calculation? 1 for YES and 2 for N0: >");
        scanf(" %d", &yesOrNo);
        
    } while (menuSelection != 0 && yesOrNo != 2);

    return 0;
}

void calculateProfit(void){
    float avg, sellPrice, shares, profit;
    printf("\nCalculate Profit\n");
    printf("\nEnter average price: >$");
    scanf("%f", &avg);
    printf("\nEnter sell price: >$");
    scanf("%f", &sellPrice);
    printf("\nEnter the number of shares in this trade: >");
    scanf("%f", &shares);
    profit = sellPrice - avg;
    profit = profit * shares;
    printf("\n\n----->Your profit on this trade is $%.2f<-----\n", profit);
}

void calculateProfitPercentage(void){
    float avg, sellPrice, profit, profitPercentage;
    printf("\nCalculate Profit Percentage\n");
    printf("\nEnter average price per share: >$");
    scanf("%f", &avg);
    printf("\nEnter sell price per share: >$");
    scanf(" %f", &sellPrice);
    profit = sellPrice - avg;
    profitPercentage = 100 * profit / avg;
    printf("\n---->You made %.0f%% on this trade.<-----\n", profitPercentage);
}

void calculateLossPercentage(void){
    float avg, sellPrice, profit, lossPercentage;
    printf("\nCalculate Loss Percentage\n");
    printf("\nEnter average price per share: >$");
    scanf(" %f", &avg);
    printf("\n\nEnter the average SELL price per share: >$");
    scanf(" %f", &sellPrice);
    profit = sellPrice - avg;
    lossPercentage = 100 * profit / avg;
    if (lossPercentage < 0) {
        printf("\n\n----->You lost %.2f%% on this trade.<-----\n", lossPercentage);
    } else {
        printf("\n\n----->You made %.2f%% on this trade.<-----\n", lossPercentage);
    }
}

void calculateStopLossPrice(void)
{
    float avg, lossPercentage, lossPrice, stopLossPrice;
    printf("\nCalculate Stop Loss Price\n");
    printf("\nEnter average price per share: >$");
    scanf(" %f", &avg);
    printf("\n\nEnter the percent you're willing to lose: >");
    scanf(" %f", &lossPercentage);
    lossPercentage = lossPercentage / 100;
    lossPrice = avg * lossPercentage;
    lossPercentage = lossPercentage * 100;
    stopLossPrice = avg - lossPrice;
    printf("\n\n---->To stop your losses at %.2f%%, set your stoploss price at $%.2f<-----\n", lossPercentage, stopLossPrice);
}

void calculateSellPointPrice(void){
    float avg, profitPercentage, profitVar, sellPrice;
    printf("\nCalculate Profit Sell Price / Limit Sell Price\n");
    printf("\nEnter average price per share: >$");
    scanf(" %f", &avg);
    printf("\n\nEnter the percentage you would like to make: >");
    scanf(" %f", &profitPercentage);
    profitVar = profitPercentage / 100 + 1;
    sellPrice = profitVar * avg;
    printf("\n\n----->In order to make %.2f%% on this trade, sell shares at $%.2f<-----\n", profitPercentage, sellPrice);
}

void calculateNewAvg(void){
    float avg, shareNum, price, shares, shares1, shares2, newAvg, total, totalShares;
    printf("\nCalculate New Average Price After New Purchase.\n");
    printf("\nEnter you current avg price: >$");
    scanf(" %f", &avg);
    printf("\nEnter the amount of shares owned: >");
    scanf(" %f", &shareNum);
    printf("\nEnter price per share of new purchase: >$");
    scanf(" %f", &price);
    printf("\nEnter the amount of shares in new purchase: >");
    scanf(" %f", &shares);
    shares1 = avg * shareNum;
    shares2 = price * shares;
    totalShares = shareNum + shares;
    total = shares1 + shares2;
    newAvg = total / totalShares;
    printf("\nAfter this purchase your new average price would be %.2f", newAvg);
}

void calculatePercentage(void){
    float number, percentage, percentagePoint;
    printf("\nCalculate a Percentage of a Number\n");
    printf("\nEnter a number: >");
    scanf(" %f", &number);
    printf("\n\nEnter the percentage of that number you would like to find: >%%");
    scanf(" %f", &percentage);
    percentagePoint = percentage / 100 * number;
    printf("\n\n----->%.2f%% of %.2f is %.2f<-----\n", percentage, number, percentagePoint);
}




