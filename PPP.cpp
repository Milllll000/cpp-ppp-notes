#include "PPP.h"
#include <stdexcept>

void error(std::string message)
{
    throw std::runtime_error{message};
}