#include "Fixed.hpp"

const int    Fixed::_nBitFractional = 8;

    // ---------------- Constructors & Destructors ------------- //

Fixed::Fixed()
{
    this->_fixedPoint = 0;
}

Fixed::Fixed(int const raw)
{
    this->_fixedPoint = raw * (1 << _nBitFractional);
}

Fixed::Fixed(float const raw)
{  
    //1 << 8 = 2^8
    this->_fixedPoint = roundf(raw * (1 << _nBitFractional));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

    // --------------  Operator Overload -------------- //
            //  ***** Assignement ********* //
Fixed   &Fixed::operator = ( Fixed const &fixed )
{
    this->_fixedPoint = fixed._fixedPoint;
    return (*this);
}

            // ******* Comparison  ******** //
bool    Fixed::operator > (Fixed const &fixed) const
{
    if (this->toFloat() > fixed.toFloat())
        return (true);
    return (false);
}

bool    Fixed::operator < (Fixed const &fixed) const
{
    if (this->toFloat() < fixed.toFloat())
        return (true);
    return (false);
}

bool    Fixed::operator <= (Fixed const &fixed) const
{
    if (this->toFloat() <= fixed.toFloat())
        return (true);
    return (false);
}

bool    Fixed::operator >= (Fixed const &fixed) const
{
    if (this->toFloat() >= fixed.toFloat())
        return (true);
    return (false);
}

bool    Fixed::operator == (Fixed const &fixed) const
{
    if (this->toFloat() == fixed.toFloat())
        return (true);
    return (false);
}

bool    Fixed::operator != (Fixed const &fixed) const
{
    if (this->toFloat() != fixed.toFloat())
        return (true);
    return (false);
}

            // *******  Arithmetic ********* //
Fixed   Fixed::operator + (Fixed const &fixed) const
{
    Fixed f(this->toFloat() + fixed.toFloat());
    return (f);
}

Fixed   Fixed::operator - (Fixed const &fixed) const
{
     Fixed f(this->toFloat() - fixed.toFloat());
    return (f);
}

Fixed   Fixed::operator * (Fixed const &fixed) const
{
    Fixed f(fixed.toFloat() * this->toFloat());
    return (f);
}

Fixed   Fixed::operator / (Fixed const &fixed) const
{
    Fixed f(this->toFloat() / fixed.toFloat());
    return (f);
}

            // ****** Increment && Decriment ****//
Fixed   Fixed::operator ++ () // ++obj
{
    this->_fixedPoint++;
    return (*this);
}

Fixed   Fixed::operator ++ (int) // obj++
{
    const Fixed old(*this);
    ++(*this);
    return old;
}

Fixed   Fixed::operator -- () // Pre-Decr
{
    this->_fixedPoint--;
    return (*this);
}

Fixed   Fixed::operator -- (int)  //Post-Decr
{
    const Fixed old(*this);
    --(*this);
    return old;
}
    // ----------------- Getters & Setters --------------------- //


int     Fixed::getRawBits( void ) const
{
    return( this->_fixedPoint );
}

void    Fixed::setRawBits( int const raw)
{
    this->_fixedPoint = raw;
}


// ------------------- Members Public functions ------------------------- //

float   Fixed::toFloat( void ) const
{
    return ((float)this->_fixedPoint / (float)(1 << 8));
}

int     Fixed::toInt( void ) const
{
    return (this->_fixedPoint / (1 << 8));
}

// ------------------- Static functions ------------------------- //

Fixed   &Fixed::min( Fixed &f1, Fixed &f2)
{
    if (f1 <= f2)
        return (f1);
    else
        return (f2);
}

const Fixed   &Fixed::min( Fixed const &f1, Fixed const &f2)
{
    if (f1 <= f2)
        return (f1);
    else
        return (f2);
}

Fixed   &Fixed::max( Fixed &f1, Fixed &f2)
{
    if (f1 >= f2)
        return (f1);
    else
        return (f2);
}

const Fixed   &Fixed::max( Fixed const &f1, Fixed const &f2)
{
    if (f1 >= f2)
        return (f1);
    else
        return (f2);
}


// ---------------- Overloading << operation -------------------  //
std::ostream & operator << (std::ostream & os , const Fixed & fixed)
{
    os << fixed.toFloat();
    return (os);
}