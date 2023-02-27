#ifndef SAQUESEMLIMITE_HPP_
#define SAQUESEMLIMITE_HPP_
#include <stdexcept>
#include <iostream>
#include "Banco.hpp"

using namespace std;

class SaqueSemLimite : public runtime_error{ 
    public:
        SaqueSemLimite();
};
#endif