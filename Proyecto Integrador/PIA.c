#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creation of variables for .txt files
FILE *fpbs, *ftbs, *fpis, *ftis; 

// Balance Sheet as a structure
    struct BALANCESHEET {
    char ED[50];  
    int year;
    float assets, liabilities, debt, equity;
};
    struct BALANCESHEET BS;

// Income Statement as a structure
    struct INCOMESTATEMENT {
    char ED[50];  
    int year;
    float revenue, cost, gross, sga, interest, tax, profit;
};
    struct INCOMESTATEMENT IS;

    long int sizeBS = sizeof(BS);
    long int sizeIS = sizeof(IS);

// Create Balance sheet .txt file or read if exists
void openbalance(){
    // opening the file
    fpbs = fopen("dataBS.txt", "rb+");
    // showing error if file is unable to open.
    if (fpbs == NULL) {
        fpbs = fopen("dataBS.txt", "wb+");
        if (fpbs == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }     
}

// Create Income statement .txt file or read if exists
void openincome(){
    // opening the file
    fpis = fopen("dataIS.txt", "rb+");
    // showing error if file is unable to open.
    if (fpis == NULL) {
        fpis = fopen("dataIS.txt", "wb+");
        if (fpis == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }     
}

// Add Data to Balance Sheet
void addBS(){

    printf("Add Data to Balance Sheet\n");
    fseek(fpbs, 0, SEEK_END);

    char another = 'y';
    while (another == 'y'){
        printf("\n\t\t\tEdition of Balance Sheet: ");
        scanf("%s", BS.ED);
  
        printf("\n\t\t\tType Year: ");
        scanf("%d", &BS.year);

        printf("\n\t\t\tAssets in millions usd: ");
        scanf("%f", &BS.assets);

        printf("\n\t\t\tLiabilities in millions usd: ");
        scanf("%f", &BS.liabilities); 

        printf("\n\t\t\tTotal debt in millions usd: ");
        scanf("%f", &BS.debt); 

    while (BS.debt > BS.liabilities){
        printf("\n\t\t\tERROR: Debt value greater than liabilities, please type again... ");
        scanf("%f", &BS.debt);
    }

        BS.equity = BS.assets - BS.liabilities;

        fwrite(&BS, sizeBS, 1, fpbs);

        fflush(stdin);
        printf("\n\t\t\tDo you want to change data ? (Y/N): ");
        
        scanf("%c", &another);
    }
}

// Display to console the Balance Sheet
void displayBS(){
    system("cls");    

    rewind(fpbs);

    printf("\n \t\t   Balance Sheet Statement \t\t\n");
    printf("=============================================\n");
    printf("Edition:             %s\nYear:                %d\nTotal Assets:      %6.2f\nTotal liabilities: %6.2f\nTotal debt:        %6.2f\nEquity:            %6.2f\n", BS.ED, BS.year, BS.assets, BS.liabilities, BS.debt, BS.equity);
    printf("=============================================\n");
    system("pause");

}

// Add Data to Income Statement
void addIS(){
    printf("\t\t\tAdd Data to Income Statement\n");
    fseek(fpis, 0, SEEK_END);

    char other = 'y';
    while (other == 'y'){

        printf("\n\t\t\tEdition of the Income Statement: ");
        scanf("%s", IS.ED);
        printf("\n\t\t\tType Year: ");
        scanf("%d", &IS.year);
        printf("\n\t\t\tTotal Revenue: ");
        scanf("%f", &IS.revenue);
        printf("\n\t\t\tCost of sales: ");
        scanf("%f", &IS.cost);

        IS.gross = IS.revenue - IS.cost;
        printf("\n\t\t\tGross profit: %6.2f\n", IS.gross); 

        printf("\n\t\t\tSales and General Administrative (SG&A): ");
        scanf("%f", &IS.sga);
        printf("\n\t\t\tInterest Expense: ");
        scanf("%f", &IS.interest);
        printf("\n\t\t\tTaxes in '%%': ");
        scanf("%f", &IS.tax);

        IS.tax = IS.tax/100;
        IS.profit = (IS.gross - IS.sga - IS.interest) * (1-IS.tax);


        fwrite(&IS, sizeIS, 1, fpis);  

        fflush(stdin);

        printf("\n\t\t\tDo you want to change data ? (Y/N): ");
        scanf("%c", &other);
    }
}

// Display to console the Income Statement
void displayIS(){
    system("cls");

    printf("=============================================\n");
    printf("\n \t Net Income Statement \t\t\n");
    printf("Year:            %d\nEdition:       %s\nRevenue:       %6.2f\nCost of sales: %6.2f\nGross Profit:  %6.2f\nSG&A:          %6.2f\nInterest:      %6.2f\nTax:           %6.2f\nNet Income:    %6.2f\n", IS.year, IS.ED, IS.revenue, IS.cost, IS.gross, IS.sga, IS.interest, IS.tax, IS.profit); 
    printf("=============================================\n");
    system("pause"); 
}

// Modify Balance Sheet
void modifyBS()
{
    system("cls");
    char empname[50];
    char condicion = 'y';
  
    while (condicion == 'y') {

        printf("\nType Balance Sheet edition: ");
        scanf("%s", empname);
  
        rewind(fpbs);

        // While File is open        
        while (fread(&BS, sizeBS, 1, fpbs) == 1) {
            // Compare the employee name with ename
            if (strcmp(BS.ED, empname) == 0) {

                printf("\n\t\t\tEdition of Balance Sheet: ");
                scanf("%s", BS.ED);
  
                printf("\n\t\t\tType Year: ");
                scanf("%d", &BS.year);

                printf("\n\t\t\tAssets in millions usd: ");
                scanf("%f", &BS.assets);

                printf("\n\t\t\tLiabilities in millions usd: ");
                scanf("%f", &BS.liabilities); 

                printf("\n\t\t\tTotal debt in millions usd: ");
                scanf("%f", &BS.debt); 

                while (BS.debt > BS.liabilities){
                    printf("\n\t\t\tERROR: Debt value greater than liabilities, please type again... ");
                    scanf("%f", &BS.debt);
                }

                BS.equity = BS.assets - BS.liabilities;

                fwrite(&BS, sizeBS, 1, fpbs);   
                fseek(fpbs, -sizeBS, SEEK_CUR);
                fwrite(&BS, sizeBS, 1, fpbs);
                break;
            } 
        }

        printf("\nIs the data INCORRECT (Y/N): ");
        fflush(stdin);
        scanf("%c", &condicion);
    }
}

// Modify Income Statement
void modifyIS()
{
    system("cls");
    char empname[50];
    char condicion = 'y';
  
    while (condicion == 'y') {

        printf("\nType Income Statement edition: ");
        scanf("%s", empname);
  
        rewind(fpis);

        // While File is open        
        while (fread(&IS, sizeIS, 1, fpis) == 1) {
            // Compare the employee name with ename
            if (strcmp(IS.ED, empname) == 0) {

                printf("\n\t\t\tEdition of the Income Statement: ");
                scanf("%s", IS.ED);
                printf("\n\t\t\tType Year: ");
                scanf("%d", &IS.year);
                printf("\n\t\t\tTotal Revenue: ");
                scanf("%f", &IS.revenue);
                printf("\n\t\t\tCost of sales: ");
                scanf("%f", &IS.cost);

                IS.gross = IS.revenue - IS.cost;
                printf("\n\t\t\tGross profit: %6.2f\n", IS.gross); 

                printf("\n\t\t\tSales and General Administrative (SG&A): ");
                scanf("%f", &IS.sga);
                printf("\n\t\t\tInterest Expense: ");
                scanf("%f", &IS.interest);
                printf("\n\t\t\tTaxes in '%%': ");
                scanf("%f", &IS.tax);

                IS.tax = IS.tax/100;
                IS.profit = (IS.gross - IS.sga - IS.interest) * (1-IS.tax);

                fwrite(&IS, sizeIS, 1, fpis);   
                fseek(fpis, -sizeIS, SEEK_CUR);
                fwrite(&IS, sizeIS, 1, fpis);
                break;
            } 
        }

        printf("\nIs the data INCORRECT (Y/N): ");
        fflush(stdin);
        scanf("%c", &condicion);
    }
}

// Calculation of Ratios
// Also I created an Integer named Index, as a method (sum) of evaluation of the business performance
void ratios(){
    int index = 0; 
    system("cls");
    printf("Ratio analysis is a quantitative method of gaining insight into a company's liquidity, operational efficiency, and profitability by studying its financial statements such as the balance sheet and income statement. Ratio analysis is a cornerstone of fundamental equity analysis.\n\n");
    float current, profitability, leverage, ROE;    
    current = BS.assets / BS.liabilities;           // Current ratio assets/liabilities
    profitability = IS.profit / IS.revenue;         // Profit margin
    leverage = BS.debt / BS.assets;                 // Debt %
    ROE = IS.profit / BS.equity;                    // Return on Equity
    printf("\t\t\tThe current ratio is:    %6.2f\n\t\t\tProfitability margin is: %6.2f\n\t\t\tDebt ratio is:           %6.2f\n\t\t\tROE ratio is:          %6.2f\n", current, profitability, leverage, ROE); 

    // LOGIC OF FINANCIAL RATIOS
    printf("\n\t\t\t%s\n", BS.assets > BS.liabilities ? "Business has more assets than liabilities" : "Business has more liabilities than assets");
    printf("\n\t\t\t%s\n", IS.profit < IS.interest ? "The payment in Interest expense is large" : "The payment in Interest expense is low");

    if (profitability >= 0.1){
        printf("\n\t\t\tNet Income results creates value to business. \n");
        index += index + 2;
    } else if (profitability >= 0 && profitability < 0.1){
        printf("\n\t\t\tProfitability is low. \n");  
        index += index + 0.5;   
    } else {
        printf("\n\t\t\tThe business is not profitable. \n");
    }


    if (current > 1.5){
        printf("\n\t\t\tBusiness Assets can pay liabilities by a margin greather than 1.5x\n");
        index += index + 2;
    } else if (current >= 0.75 && current <= 1.5){
        printf("\n\t\t\tAssets have to pay Liabilities.\n"); 
        index += index + 0.5;    
    } else {
        printf("\n\t\t\tLiabilities are a great threat to business.\n");
    }


    if (leverage > 0.7){
        printf("\n\t\t\tYour business has too much DEBT!\n");
    } else if (leverage >= 0.4 && leverage <= 0.7){
        printf("\n\t\t\tDebt levels are average\n"); 
        index += index + 0.5;    
    } else {
        printf("\n\t\t\tDebt levels are great, you can consider more capital expenditures to grow.\n");
        index += index + 1;
    }


    if(ROE >= 0.15 && (IS.profit >= 0 || BS.equity >= 0)){
        printf("\n\t\t\tReturn on Equity is excellent, good management of cash reserves.\n");
        index += index + 2;
    } else {
        printf("\n\t\t\tReturn on Equity is low, cash management is not properly invested.\n");       
    }

    if(IS.profit <= 0 || BS.equity <= 0 ){
        printf("\n\t\t\tThe business is burning cash\n");
        index += index - 2;       
    }

    printf("\n\t\t\tIndex value is %d\n", index);

    if(index >= 20){
        printf("\n\t\t\tBusiness has positive results\n\n");
    } else if (index >= 12 && index<20){
        printf("\n\t\t\tBusiness needs Due diligence\n\n");
    } else {
        printf("\n\t\t\tBusiness may be in the need to declare BANKRUPTCY\n\n");
    }


}

// Final valuation of the business
void valuation(){

    float price, PE, EV, EBITDA; // Valuation multiples
    printf("Valuation is the analytical process of determining the current (or projected) worth of an asset or a company. There are many techniques used for doing a valuation. An analyst placing a value on a company looks at the business's management, the composition of its capital structure, the prospect of future earnings, and the market value of its assets, among other metrics. \n");

    printf("\n\t\t\tPrice of the stock $: ");
    scanf("%f", &price); 

    PE = price / IS.revenue ; // Price to earnings multiple
    EV = BS.assets + BS.equity + IS.profit; // Enterprise Value
    EBITDA = IS.gross * 0.9; // Earnings Before Interest Depreciation & Amortization

    printf("============================================================================\n");
    printf("\nYear\tPrice $\tEarnings\t EV \tEV/sales\tEV/EBITDA\tP/E \n");
    printf("\n%d\t%6.2f\t%6.2f\t\t%6.2f\t%6.2fx\t\t%6.2fx\t%6.2fx\n", BS.year, price, IS.profit, EV, EV/IS.profit, EV/EBITDA, PE);
    printf("============================================================================\n");


}

// Main program in C
int main(){    

    int choice, a;    

    printf("\n\t\t\t\t=====================================================");
    printf("\n\t\t\t\t[              Financial Valuation Software         ]\t");
    printf("\n\t\t\t\t=====================================================\n");
    printf("\n Welcome to the 1st edition of my financial software with a range of applications for small business to corporate world, you only need to type your accounting data and I ll perform numerical analysis.");
    printf("\nFor more info send me an email jairmedinaortiz@outlook.com\n");
    printf("\n\t\t\t\t              @JairMedina97 Github profile \n");
    system("pause");

    // Open Balance Sheet .txt file
    openbalance();
    // Add Info to the Balance Sheet
    addBS(); 
    // Display data of the Balance Sheet
    displayBS();
    // Open Income Statement .txt file
    openincome();
    // Add Info to the Income Statement   
    addIS();
    // Display data of the Balance Sheet
    displayIS();


    char otro = 'y';
    while (otro == 'y'){
        system("cls");
        
        printf("\n1. MANIPULATE DATA OF FINANCIAL STATEMENTS\n");

        printf("\n2. VISUALIZE DATA\n");

        printf("\n3. RATIO CALCULATIONS\n");

        printf("\n4. FINANCIAL VALUATION\n");

        printf("\n5. EXIT\n");

        printf("\nTYPE...\n");

        scanf("%d", &choice);
        //system("pause"); 
        // Switch Case
        switch (choice) {
        case 1: 
            // Manipulate Data
            printf("Type 1 for Balance Sheet or something else for Income statement\n");
            scanf("%d", &a);
            if(a == 1){
                modifyBS();
                displayBS();
            } else {
                modifyIS();
                displayIS(); 
            }
            break;
  
        case 2:  
            // Visualize
            displayBS();
            displayIS();
            break;
  
        case 3:  
            // Ratio calculations 
            ratios();
            break;
  
        case 4:
            //Valuation;
            valuation();
            break;

        case 5:
            fclose(fpis);
            fclose(fpis);
            printf("\nThank you for using my financial software\n");
            printf("For more info send me an email jairmedinaortiz@outlook.com");
            exit(0);
            break;
  
        default:
            printf("\nType range only 1 - 5 ...\n");
        }
        
        printf("\n\t\t\tDeseas Hacer otro procedimiento (Y/N): ");
        fflush(stdin);
        scanf("%c", &otro);    
    }
    fclose(fpis);
    fclose(fpis);
    printf("\nThank you for using my financial software\n");
    printf("For more info send me an email jairmedinaortiz@outlook.com");
    return 0;
}

