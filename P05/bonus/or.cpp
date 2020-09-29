#include "or.h"

Signal Or::output() {
    return input1 || input2;
}
