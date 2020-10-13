#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>

class Product {
  public: 
    Product(std::string name, double price, std::string description);
    friend std::ostream& operator<<(std::ostream& ost, const Product& product);
  protected:
    virtual std::string to_string() const;
  private:
    static int _nextsn;
    std::string _name;
    int _stocknum;
    double _price;
    std::string _description;
};

#endif
