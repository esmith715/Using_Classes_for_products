// This program produces a sales report for DLC，Inc.
#include <iostream>
#include<iomanip>
using namespace std;

//sturct
struct product
{

    int id;
    int units;
    double prices;
    double sales;


};

//Function prototypes
void calcSales(product productArray[], int);
void showOrder(product productArray[], int);
void dualSort(product productArray[], int);
void showTotals(product productArray[], int);
void swap(product productArray[], int&, int&);
//void swap(int&, int&);




int main()
{
    //NUM PRODSis the number of products produced.
    
    const int NUM_PRODS = 9;

    product productArray[NUM_PRODS];

    // Array withproduct IDnumber
    int id[NUM_PRODS] = { 914, 915, 916, 917, 918,
                          919, 920, 921, 922 };

    // Array with number of units sold for each produc
    int units[NUM_PRODS] = { 842, 416, 127, 514, 437,
                             269, 97, 492, 212 };

    // Array with product prices
    double prices[NUM_PRODS] = { 12.95, 14.95, 18.95, 16.95, 21.95,
                                 31.95, 14.95, 14.95, 16.95 };

    // Array to hold the computed sales amounts
    double sales[NUM_PRODS];

    for (int i = 0; i < NUM_PRODS; i++)
    {
        productArray[i].id = id[i];
        productArray[i].units = units[i];
        productArray[i].prices = prices[i];
        productArray[i].sales = sales[i];
    }
    
    
   

    // Calculate each product’s sales.
    calcSales(productArray, NUM_PRODS);

    // Sort the elements in the sales array in descending
    //order and shuffle the ID numbers in the id array to
    // keep themin para11e1.
    dualSort(productArray, NUM_PRODS);

    // Set the numeric output formatting.
    cout << setprecision(2) << fixed << showpoint;

    // Display the products and sales amounts.
    showOrder(productArray, NUM_PRODS);

    // Display total units sold and total sales
    showTotals(productArray, NUM_PRODS);
    return 0;
}

//***************************************************************
// Definition of calcSales. Accepts units，prices，and sales     *
// arrays as arguments. The size of these arrays is passed      *
// into the num parameter. This function calculates each        *
// product’s sales by multiplying its units sold by each unit’s *
// price. The result is stored in the sales array               *
//***************************************************************

void calcSales(product productArray[], int num)
{
    for (int index = 0; index < num; index++)
        productArray[index].sales = productArray[index].units * productArray[index].prices;
}

//******************************************************************
// Definition of function dualSort，Accepts id and sales arrays    *
// as arguments，The size of these arrays is passed into size.     *
// This function performs a descending order selection sort on     *
// the sales array. The elements of the id array are exchanged     *
// identica7ly as those of the sales array.size is the number      *
//of elementsin each array.                                        *
//******************************************************************

void dualSort(product productArray[], int size)
{
    int start, maxIndex;
    //product tempProduct;
    double maxValue;

    for (start = 0; start < (size - 1); start++)
    {
        maxIndex = start;
        maxValue = productArray[start].sales;
        
        
        for (int index = start + 1; index < size; index++)
        {
            if (productArray[index].sales > maxValue)
            {
                maxValue = productArray[index].sales;
                
                maxIndex = index;
            }
        }
        swap(productArray, maxIndex, start);
        //swap(id[maxIndex], id[start]);
    }
}

//*****************************************************
// The swap function swaps doubles a and bin memory.  *
//*****************************************************
void swap(product productArray[], int& a, int& b)
{
    product tempprod = productArray[a];
    productArray[a] = productArray[b];
    productArray[b] = tempprod;
}

//**************************************************
// The swap function swaps ints a and b in memory. *
//**************************************************
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//***************************************************************
//Definition of showOrder function.Accepts sales and id arrays  *
// as arguments. The size of these arrays is passed into num.   *
// The function first displays a heading, then the sorted list  *
// of product numbers and sales.                                *
//***************************************************************

void showOrder(product productArray[], int num)
{
    cout << "ProductNumber\tSales\n";
    cout << "--------------------------\n";
    for (int index = 0; index < num; index++)
    {
        cout << productArray[index].id << "\t\t$";
        cout << setw(8) << productArray[index].sales << endl;
    }
    cout << endl;
}

//********************************************************************* 
//Definition of showTotals function. Accepts sales and id arrays      *
//as arguments. The size of these arrays is passed into num.          *
// The function first calculates the total units (of a11              *  
// products) sold and the total sales. It then displays these         * 
// amounts.                                                           *
//********************************************************************* 

void showTotals(product productArray[], int num)
{
    int totaUnits = 0;
    double totalSales = 0.0;

    for (int index = 0; index < num; index++)
    {
        totaUnits += productArray[index].units;
        totalSales += productArray[index].sales;
    }
    cout << "Total units Sold: " << totaUnits << endl;
    cout << "Total sales: $" << totalSales << endl;
}
