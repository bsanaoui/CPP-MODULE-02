#include "Fixed.hpp"

const int    Fixed::_nBitFractional = 8;

    // ---------------- Constructors & Destructors ------------- //
    
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPoint = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

    // -------------- Assignation Operator Overload ----------- //
void    Fixed::operator = (Fixed const &fixed)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_fixedPoint = fixed.getRawBits();
}

    // ----------------- Getters & Setters --------------------- //
int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return( this->_fixedPoint );
}

void    Fixed::setRawBits( int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPoint = raw;
}
