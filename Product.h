#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Product {
public:
    int id;
    int units;
    double prices;
    double sales;
    string description;
    bool taxExempt;

    static void calcSales(vector<Product>& products, int num);
    static void showOrder(const vector<Product>& products, int size);
    static void dualSort(vector<Product>& products, int size);
    static void showTotals(const vector<Product>& products, int num);
    static void swap(vector<Product>& products, int& a, int& b);
};

#endif 



