#include "xor.h"

Signal Xor::output() {
    return input1 ^ input2;
}
