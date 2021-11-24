#ifndef __FIXED__
#define __FIXED__
#include <iostream>
#include <cmath>

class Fixed
{

    // Private Members ----- //
    private:

    int _fixedPoint;
    static const int    _nBitFractional;

    // Public Members ------ //
    public:

    // ---------------- Constructors & Destructors ------------- //
    Fixed();
    Fixed(int const raw);
    Fixed(float const raw);
    ~Fixed();
    Fixed(const Fixed &fixed);

    // --------------  Operator Overload ----------- //
    Fixed    &operator = (Fixed const &fixed) ;


    // ----------------- Getters & Setters --------------------- //
    int     getRawBits( void ) const;
    void    setRawBits( int const raw);

    // ------------------- Members Public functions ------------------------- //
    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream & operator<<(std::ostream & os , const Fixed & fixed);
#endif