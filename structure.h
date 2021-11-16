
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

