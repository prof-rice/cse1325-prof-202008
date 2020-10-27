#include "store.h"
#include <iostream>

Store::Store(std::string name) : _name{name} { }
Store::Store(std::istream& ist) {
    std::getline(ist, _name);
    std::string s;
    while(ist) {
        std::getline(ist, s);
        if(s == "tool") _products.push_back(new Tool(ist));
        else if(s == "plant") _products.push_back(new Plant(ist));
        else if(s == "mulch") _products.push_back(new Mulch(ist));
        else if(s.size()) throw std::runtime_error{"Invalid product type on input: " + s};
    }
}
void Store::save(std::ostream& ost) {
    ost << _name << '\n';
    for(Product* p : _products) p->save(ost);
}
void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
const Product& Store:: product(int index) {return *_products.at(index);}

