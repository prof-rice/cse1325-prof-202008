#include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email) 
    : _name{name}, _phone{phone}, _email{email} { }
Customer::Customer(std::istream& ist) {
    std::getline(ist, _name);
    std::getline(ist, _phone);
    std::getline(ist, _email);
}    
void Customer::save(std::ostream& ost) {
    ost << _name  << '\n'
        << _phone << '\n'
        << _email << '\n';
}
std::string Customer::name() const {return _name;}
std::ostream& operator<<(std::ostream& ost, const Customer& customer) {
    ost << customer._name << " (" << customer._phone << ", " << customer._email << ")";
    return ost;
}

