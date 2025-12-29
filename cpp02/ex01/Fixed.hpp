#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // roundf fonksiyonu için gerekli

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        // Orthodox Canonical Form
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        // Yeni Eklenen Kurucular (Ex01)
        Fixed(const int n);   // Tam sayıdan sabit noktalıya
        Fixed(const float n); // Ondalıklıdan sabit noktalıya

        // Member Functions (Dönüşüm Fonksiyonları)
        float   toFloat(void) const;
        int     toInt(void) const;

        // Raw Bits Fonksiyonları (Ex00'dan devam)
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

// Sınıfın Dışında: << Operatörünün Aşırı Yüklenmesi
std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif