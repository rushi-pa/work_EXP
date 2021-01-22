//Rushi Patel

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include "List.h"
#include "Element.h"
#include <memory>

namespace sdds {
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
}

#endif