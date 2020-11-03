#ifndef __PLANT_H
#define __PLANT_H

#include "product.h"

enum class Exposure {
  SHADE,
  PARTSUN,
  SUN,
};

std::string to_string(Exposure exposure);
Exposure exposure_from_string(std::string s);

std::ostream& operator<<(std::ostream& ost, const Exposure& exposure);

class Plant : public Product {
  public:
    Plant(std::string name, double price, std::string description, std::string species, Exposure exposure);
    Plant(std::istream& ist);
    void save(std::ostream& ost) override;
  protected:
    std::string to_string() const override;
  private:
    std::string _species;
    Exposure _exposure;
};

#endif
