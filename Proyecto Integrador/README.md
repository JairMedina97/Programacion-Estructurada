### Financial Valuation in C
#### Data analysis on Financial Statements :dollar:
Financial Statement analysis in C language of a given company
- Income statement & Balance Sheet analysis

The numerical analysis run in C can calculate financial ratios, run statistical analysis to perform valuations of small business or even a company listed on the stock exchange.

In finance, valuation is the process of determining the present value of an asset. Valuations can be done on assets or on liabilities.

Valuation guide
- Fundamental Analysis <a id="2">[1]</a>
- Ratio calculations <a id="2">[2]</a>
- Valuation
- Output


## Estructura
Here we can see the flow structure of the program. 
<p align="center">
  <div align="left"><img src="Images/Title.PNG" width="400" >
</p>

<div align="left"><img src="Images/Welcome1.PNG" width="400" >
<div align="left"><img src="Images/structures.PNG" width="400" >
<div align="left"><img src="Images/programflow.PNG" width="400" >
<div align="left"><img src="Images/addataflow.PNG" width="400" >
<div align="left"><img src="Images/menuflow.PNG" width="400" >
<div align="left"><img src="Images/menuflow2.PNG" width="400" >
<div align="left"><img src="Images/ratiosflow.PNG" width="400" >
<div align="left"><img src="Images/valuationflow.PNG" width="400" >

## Funcionalidad

Our main program first has an introduction. 
<div align="left"><img src="Images/welcome.PNG" width="600" >
  
We'll use this financial data examples to have an input data.
<div align="left"><img src="Images/Finance-example.PNG" width="600" >  
  
We first need to upload the data into the Balance sheet. 
<div align="left"><img src="Images/AddBS.PNG" width="600" >

Then upload the data into the Income Statement. 
<div align="left"><img src="Images/AddIS.PNG" width="400" >

After the info has been updated we enter the menu section
<div align="left"><img src="Images/Menu.PNG" width="400" >
  
In option 1 we can modify, update our data. Manipulate is a function where we can modify our .txt files to overwrite the actual data with a new one if something has to be done different we have the option to upload a new entry.
  
We can display the financial statements in option 2. Two display functions one for each financial statement to print in a table format.
<div align="left"><img src="Images/Balancesheet.PNG" width="400" >
<div align="left"><img src="Images/Incomestatement.PNG" width="400" >
  
In option 3 we perform the logic structure of the conditional statements.The function ratios will evaluate the info from both balance sheet and income statement to return values such as current ratio, profitability, Debt ratio, Return on Equity, liabilities levels and more.
To have a better sense how is our performance.

<div align="left"><img src="Images/ratios().PNG" width="600" >
  
Option number 4 performs the valuation with a given stock price.Valuation as the name implies will evaluate “Valuation multiples” to give a better interpretation how the performance is and what to expect.

<div align="left"><img src="Images/valuation().PNG" width="600" >
  

## Video

La URL a [YouTube](https://youtube.com)

## Referencias

- <a id="1">[1]</a> Subramanyam, K. R. and Wild, John J. (2009) Financial statement analysis. 10th ed. Boston, Mass: McGraw-Hill Irwin. ISBN-10: 0073379433

- <a id="2">[2]</a> Corporate Finance Institute (2018) Financial Ratios eBook. 1st ed. Vancouver, CAN: CFI.
  
- <a id="3">[3]</a> Kernighan, B. W., & Ritchie, D. M. (1988). The C programming language. ISBN-13: 9780131103627
