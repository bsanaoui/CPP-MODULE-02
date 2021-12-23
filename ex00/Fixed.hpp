#ifndef __FIXED__
#define __FIXED__
#include <iostream>

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
    ~Fixed();
    Fixed(Fixed const &fixed);

    // -------------- Assignation Operator Overload ----------- //
    void    operator = (Fixed const &fixed);

    // ----------------- Getters & Setters --------------------- //
    int     getRawBits( void ) const ;
    void    setRawBits( int const raw);
};
#endif