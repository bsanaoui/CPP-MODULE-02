#include "Fixed.hpp"

const int    Fixed::_nBitFractional = 8;

    // ---------------- Constructors & Destructors ------------- //

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPoint = 0;
}

Fixed::Fixed(int const raw)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = raw * (1 << _nBitFractional);
}
Fixed::Fixed(float const raw)
{
    std::cout << "Float constructor called" << std::endl;   //1 << 8 = 2^8
    this->_fixedPoint = roundf(raw * (1 << _nBitFractional));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

    // --------------  Operator Overload ----------- //

Fixed   & Fixed::operator = ( Fixed const &fixed )
{
    std::cout << "Assignation operator called" << std::endl;
    this->_fixedPoint = fixed._fixedPoint;
    return (*this);
}

    // ----------------- Getters & Setters --------------------- //


int     Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return( this->_fixedPoint );
}

void    Fixed::setRawBits( int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPoint = raw;
}

// ------------------- Members Public functions ------------------------- //

float   Fixed::toFloat( void ) const
{
    return ((float)this->_fixedPoint / (float)(1 << _nBitFractional));
}

int     Fixed::toInt( void ) const
{
    return (this->_fixedPoint / (1 << _nBitFractional));
}

// ---------------- Overloading << operation -------------------  //
std::ostream & operator<<(std::ostream & os , const Fixed & fixed)
{
    os << fixed.toFloat();
    return (os);
}