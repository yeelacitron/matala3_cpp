#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>

namespace ariel{
    class Fraction{
        private:
            int numer;
            int denom;
            void gcd();
            void check_overflow(long numerator, long denominator) const;
            static const int max_int = std::numeric_limits<int>::max();
            static const int min_int = std::numeric_limits<int>::min();
        public:

            //operators
            Fraction(int num, int den);
            Fraction(float flo);
            Fraction();
            Fraction operator+(const Fraction  &other) const;
            Fraction operator-(Fraction const &other) const;
            Fraction operator*(Fraction const &other) const;
            Fraction operator/(Fraction const &other) const;
            Fraction& operator++();
            const Fraction operator++(int);
            Fraction& operator--();
            const Fraction operator--(int);
            Fraction operator-() const;

            //get function
            int getNumerator() const;
            int getDenominator() const;

            
            //friend fuction
            friend std::ostream& operator<<(std::ostream& output, const Fraction& frac);
            friend std::istream& operator>>(std::istream& input, Fraction& frac);
            friend Fraction operator*(const float &flo,const Fraction &other);
            friend Fraction operator*(const Fraction &frac,const float &other);
            friend Fraction operator+(const float &flo,const Fraction &other);
            friend Fraction operator+(const Fraction &frac,const float &other);
            friend Fraction operator-(const float &flo,const Fraction  &other);
            friend Fraction operator-(const Fraction &frac,const float &other);
            friend Fraction operator/(const float &flo,const Fraction &other);
            friend Fraction operator/(const Fraction &frac,const float &other);
            friend bool operator==(const Fraction& frac1, const float& flo);
            friend bool operator==(const float& flo,const Fraction& frac1);
            friend bool operator==(const Fraction& flo,const Fraction& frac1);
            friend bool operator<=(const Fraction& frac1, const float& flo);
            friend bool operator<=(const float& flo,const Fraction& frac1);
            friend bool operator<=(const Fraction& flo,const Fraction& frac1);
            friend bool operator>=(const Fraction& frac1, const float& flo);
            friend bool operator>=(const float& flo,const Fraction& frac1);
            friend bool operator>=(const Fraction& flo,const Fraction& frac1);
            friend bool operator<(const Fraction& frac1, const float& flo);
            friend bool operator<(const float& flo,const Fraction& frac1);
            friend bool operator<(const Fraction& flo,const Fraction& frac1);
            friend bool operator>(const Fraction& frac1, const float& flo);
            friend bool operator>(const float& flo,const Fraction& frac1);
            friend bool operator>(const Fraction& flo,const Fraction& frac1);
                    
             

    };

}