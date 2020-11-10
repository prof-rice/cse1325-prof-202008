#ifndef __ORDER_H
#define __ORDER_H

#include "customer.h"
#include "item.h"
#include <vector>

class Order {
  public:
    Order(Customer customer);
    Order(std::istream& ist);
    void save(std::ostream& ost);
    void add_item(Item item);
    double total() const;
    friend std::ostream& operator<<(std::ostream& ost, const Order& order);
  private:
    Customer _customer;
    std::vector<Item> _items;
};
#endif
