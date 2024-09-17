// This program produces a sales report for DLC，Inc.
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Product.h"
using namespace std;

void readFile(const string& file_name, vector<Product>& products, int NUM_PRODS){
    ifstream file(file_name);
    if (!file.is_open()) {
        cout << "Error: File not found." << endl;
        return;
    }

    Product product;
    string line;
    while (getline(file, line) && products.size() < NUM_PRODS) {
        if (line.find("ID:") != string::npos) {
            product.id = stoi(line.substr(line.find(":") + 1));
        } else if (line.find("Units:") != string::npos) {
            product.units = stoi(line.substr(line.find(":") + 1));
        } else if (line.find("Price:") != string::npos) {
            product.prices = stod(line.substr(line.find(":") + 1));
        } else if (line.find("Description:") != string::npos) {
            product.description = line.substr(line.find(":") + 1);
        } else if (line.find("TaxExempt:") != string::npos) {
            product.taxExempt = (line.substr(line.find(":") + 1) == "True");
            products.push_back(product);
        }
    }

    if (products.empty()) {
        cout << "Error: Empty file." << endl;
    }
}




int main()
{
    //NUM PRODSis the number of products produced.
    const int NUM_PRODS = 9;
    string filename;
    cout << "Enter the name of the file: ";
    getline(cin, filename);

    vector<Product> products;
    readFile(filename, products, NUM_PRODS);

    int size = products.size();
    
    
   

    // Calculate each product’s sales.
    Product::calcSales(products, size);

    // Sort the elements in the sales array in descending
    //order and shuffle the ID numbers in the id array to
    // keep themin para11e1.
    Product::dualSort(products, size);

    // Set the numeric output formatting.
    cout << setprecision(2) << fixed << showpoint;

    // Display the products and sales amounts.
    Product::showOrder(products, size);

    // Display total units sold and total sales
    Product::showTotals(products, size);


    return 0;
}


