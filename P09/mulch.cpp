#include "mulch.h"

Mulch::Mulch(std::string name, double price, std::string description, int volume, Material material)
    : Product(name, price, description), _volume{volume}, _material{material} { }
Mulch::Mulch(std::istream& ist) : Product(ist) {
    ist >> _volume; ist.ignore(65535, '\n');
    std::string s;
    std::getline(ist, s);
    _material = material_from_string(s);
}
void Mulch::save(std::ostream& ost) {
    ost << "mulch\n";
    Product::save(ost);
    ost << _volume << '\n'
        << ::to_string(_material) << '\n';
}
std::string Mulch::to_string() const {
    return Product::to_string() + "\n  Volume: " + std::to_string(_volume) + " ft³\n  Material: " + ::to_string(_material);
}
std::ostream& operator<<(std::ostream& ost, const Material& material) {
    ost << to_string(material);
    return ost;
}
std::string to_string(Material material) {
    if(material == Material::RUBBER) return "rubber";
    else if(material == Material::PINE) return "pine";
    else if(material == Material::CEDAR) return "cedar";
    else if(material == Material::HARDWOOD) return "hardwood";
    else throw std::out_of_range("Invalid Material value");
}

Material material_from_string(std::string s) {
    if(s == "rubber") return Material::RUBBER;
    else if(s == "pine") return Material::PINE;
    else if(s == "cedar") return Material::CEDAR ;  
    else if(s == "hardwood") return Material::HARDWOOD;
    else throw std::out_of_range("Invalid Material from string");
}

