#ifndef __STORE_H
#define __STORE_H

#include "tool.h"
#include "plant.h"
#include "mulch.h"

#include "customer.h"
#include "order.h"

#include <vector>

class Store {
  public:
    Store(std::string name);
    Store(std::istream& ist);
    void save(std::ostream& ost);
    std::string name();

    void add_product(const Tool& product);
    void add_product(const Plant& product);
    void add_product(const Mulch& product);
    int products();
    Product& product(int index);
    
    void add_customer(const Customer& customer);
    int customers();
    const Customer& customer(int index);
    
    int add_order(const Customer& customer);
    void add_item(int order, Product& product, int quantity);
    int orders();
    const Order& order(int index);
  private:
    std::string _name;
    std::vector<Product*> _products;
    std::vector<Customer*> _customers;
    std::vector<Order*> _orders;
};

#endif
