#include "plant.h"

Plant::Plant(std::string name, double price, std::string description, std::string species, Exposure exposure)
    : Product(name, price, description), _species{species}, _exposure{exposure} { }
Plant::Plant(std::istream& ist) : Product(ist) {
    std::getline(ist, _species);
    std::string s;
    std::getline(ist, s);
    _exposure = exposure_from_string(s);
}
void Plant::save(std::ostream& ost) {
    ost << "plant\n";
    Product::save(ost);
    ost << _species << '\n'
        << ::to_string(_exposure) << '\n';
}

std::string Plant::to_string() const {
    return Product::to_string() + "\n  Species: " + _species + "\n  Exposure: " + ::to_string(_exposure);
}
std::ostream& operator<<(std::ostream& ost, const Exposure& exposure) {
    ost << to_string(exposure);
    return ost;
}
std::string to_string(Exposure exposure) {
    if(exposure == Exposure::SHADE) return "shade";
    else if(exposure == Exposure::PARTSUN) return "part sun";
    else if(exposure == Exposure::SUN) return "full sun";
    else throw std::out_of_range("Invalid Exposure value");
}
Exposure exposure_from_string(std::string s) {
    if(s == "shade")        return Exposure::SHADE;
    else if(s == "part sun") return Exposure::PARTSUN;
    else if(s == "full sun")     return Exposure::SUN;
    else throw std::runtime_error{"Invalid Exposure from string"};
}
