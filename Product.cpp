#include "Product.h"
#include <iomanip>
using namespace std;

void Product::calcSales(vector<Product>& products, int num){
    for (int index = 0; index < num; index++)
        products[index].sales = products[index].units * products[index].prices;
}

void Product::swap(vector<Product>& products, int& a, int& b){
    Product tempprod = products[a];
    products[a] = products[b];
    products[b] = tempprod;
}

void Product::dualSort(vector<Product>& products, int size) {
    int start, maxIndex;
    double maxValue;

    for (start = 0; start < (size - 1); start++) {
        maxIndex = start;
        maxValue = products[start].sales;

        for (int index = start + 1; index < size; index++) {
            if (products[index].sales > maxValue) {
                maxValue = products[index].sales;
                maxIndex = index;
            }
        }
        swap(products, maxIndex, start);
    }
}


void Product::showOrder(const vector<Product>& products, int size) {
    cout << "Product Number\tSales\n";
    cout << "--------------------------\n";
    for (int index = 0; index < size; index++) {
        cout << products[index].id << "\t\t$";
        cout << setw(8) << products[index].sales << endl;
    }
    cout << endl;
}

void Product::showTotals(const vector<Product>& products, int size) {
    int totalUnits = 0;
    double totalSales = 0.0;

    for (int index = 0; index < size; index++) {
        totalUnits += products[index].units;
        totalSales += products[index].sales;
    }
    cout << "Total units Sold: " << totalUnits << endl;
    cout << "Total Sales: $" << totalSales << endl;
}