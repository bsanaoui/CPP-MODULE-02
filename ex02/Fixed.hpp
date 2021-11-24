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

    // ------------------  Operator Overload ----------------------- //
            //  ***** Assignement ********* //
    Fixed    &operator = (Fixed const &fixed) ;

            // ******* Comparison  ******** //
    bool    operator > (Fixed const &fixed) const;
    bool    operator < (Fixed const &fixed) const;
    bool    operator <= (Fixed const &fixed) const;
    bool    operator >= (Fixed const &fixed) const;
    bool    operator == (Fixed const &fixed) const;
    bool    operator != (Fixed const &fixed) const;

            // *******  Arithmetic ********* //
    Fixed   operator + (Fixed const &fixed) const;
    Fixed   operator - (Fixed const &fixed) const;
    Fixed   operator * (Fixed const &fixed) const;
    Fixed   operator / (Fixed const &fixed) const;

           // ****** increment && Decriment ****//
    Fixed   operator ++ (); // Pre-Incr
    Fixed   operator ++ (int); //Post-Inc
    Fixed   operator -- (); // Pre-Decr
    Fixed   operator -- (int); //Post-Decr
    

    // ----------------- Getters & Setters ------------------------ //
    int     getRawBits( void ) const;
    void    setRawBits( int const raw);

    // ------------------- Members Public functions ---------------- //
    float   toFloat( void ) const;
    int     toInt( void ) const;

    // ------------------- Static functions ------------------------- //
    static Fixed   &min( Fixed &f1, Fixed &f2);
    static const Fixed   &min( Fixed const &f1, Fixed const &f2);
    static Fixed   &max( Fixed &f1, Fixed &f2);
    static const Fixed   &max( Fixed const &f1, Fixed const &f2);

};

std::ostream & operator << (std::ostream & os , const Fixed & fixed);

#endif