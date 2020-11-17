#include "order.h"

Order::Order(Customer customer) : _customer{customer} { }
Order::Order(std::istream& ist) : _customer{ist} {
    int items;
    ist >> items; ist.ignore(32767, '\n');
    while(items--) _items.push_back(Item{ist});
}
void Order::save(std::ostream& ost) {
    _customer.save(ost);
    ost << _items.size() << '\n';
    for(Item& i : _items) i.save(ost);
}
void Order::add_item(Item item) {
    _items.push_back(item);
}
double Order::total() const {
    double sum = 0.0;
    for(Item i : _items) sum += i.subtotal();
    return sum;
}

std::ostream& operator<<(std::ostream& ost, const Order& order) {
    ost << "For Customer " << order._customer << "   $" << order.total() << "\n";
    for(int i=0; i<order._items.size(); ++i)
        ost << order._items[i] << "\n";
    return ost;
}
