#ifndef __STORE_H
#define __STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"

#include "customer.h"

#include <vector>

class Store {
  public:
    Store(std::string name);
    Store(std::istream& ist);
    void save(std::ostream& ost);

    void add_product(const Tool& product);
    void add_product(const Plant& product);
    void add_product(const Mulch& product);
    int products();
    const Product& product(int index);
    
    void add_customer(const Customer& customer);
    int customers();
    const Customer& customer(int index);
  private:
    std::string _name;
    std::vector<Product*> _products;
    std::vector<Customer*> _customers;
};

#endif
