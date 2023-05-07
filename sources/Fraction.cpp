#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm> 
#include "Fraction.hpp"

using namespace std;
 namespace ariel{
    Fraction::Fraction(int num, int den): numer(num),denom(den){
        if(den==0){
            throw invalid_argument("Denominator must not be 0");
        }
        gcd();
        if(this->denom<0){
            this->numer*=-1;
            this->denom*=-1;
        }
    }
    Fraction::Fraction(float flo){
        int numerator= int(flo* 1000);
        this->numer= numerator;
        this->denom= 1000;
        gcd();
    }
    Fraction::Fraction():numer(0),denom(1){}
    void Fraction:: gcd(){
        int gcd = __gcd(numer,denom);
        if(gcd<0){
            gcd*=-1;
        }
        if(gcd!=1){
            this->numer= numer/gcd;
            this->denom= denom/gcd;
        }
    }
    void Fraction::check_overflow_of_multi(int left, int right) const {
        if (((left==max_int) && (abs(right)>1) && (right=!0))||((right==max_int) && (abs(left)>1) && (left=!0))) {
            throw overflow_error("Error: integer overflow detected.");
        }
    }
    Fraction Fraction::operator+(const Fraction  &other) const{
        
        int up = (this->numer*other.denom)+(other.numer*this->denom);
        int down= this->denom*other.denom;
        
        return Fraction(up,down);
    }
    Fraction Fraction::operator-(const Fraction  &other) const{
        int up = (this->numer*other.denom)-(other.numer*this->denom);
        int down= this->denom*other.denom;
        
        return Fraction(up,down);
    }
    Fraction Fraction::operator*(const Fraction  &other) const{
        check_overflow_of_multi(this->numer,other.numer);
        int up =this->numer*other.numer;
        check_overflow_of_multi(this->denom,other.denom);
        int down =this->denom*other.denom;
       
        Fraction a(up,down);
        return a;
    }
    Fraction Fraction::operator/(const Fraction  &other) const{
        if(other.numer==0){
            throw runtime_error("can't divide by 0");
        }
        int up = this->numer*other.denom;
        int down =this->denom*other.numer;
        
        Fraction a(up,down);
        return a;
    }
    Fraction& Fraction::operator++(){
        this->numer += this->denom;
        return *this;
    }
    const Fraction Fraction::operator++(int){
        Fraction copy =* this;
        this->numer += this->denom;
        return copy;
    }
    Fraction& Fraction::operator--(){
        this->numer -= this->denom;
        return *this;
    }
    const Fraction Fraction::operator--(int){
        Fraction copy =* this;
        this->numer -= this->denom;
        return copy;
    }
    Fraction Fraction::operator-() const{
        return  Fraction(-this->numer,this->denom);
    }
    ostream& operator<<(std::ostream& output, const Fraction& frac){
        return (output<<to_string(frac.numer)<<"/"<<to_string(frac.denom));
    }



    istream& operator>>(std::istream& input,  Fraction& frac){
        int new_nu = 0, new_de = 0;
        input>>new_nu>>new_de;
        if(!input){
            throw runtime_error("invalid input");
        }
        if(new_de==0){
            throw runtime_error("Denominator must not be 0");
        }
        Fraction a(new_nu,new_de);
        frac=a;
        return input;
    }

   
    Fraction operator*(const float &flo,const Fraction &other){
        Fraction a(flo);
        return a*other;
    }
    Fraction operator*(const Fraction &frac,const float  &other){
        return other*frac;
    }
    Fraction operator+(const float& flo,const Fraction &other){
        Fraction a(flo);
        return a+other;
    }
    Fraction operator+(const Fraction &frac,const float &other){
        return other+frac;
    }
    Fraction operator-(const float &flo,const Fraction &other){
        Fraction a(flo);
        return a-other;  
    }
    Fraction operator-(const Fraction &frac,const float &other){
        Fraction a(other);
        return frac-a; 
    }
    Fraction operator/(const float &flo,const Fraction &other){
        Fraction a(flo);
        return a/other;  
    }
    Fraction operator/(const Fraction &frac,const float &other){
        Fraction a(other);
        return frac/a; 
    }
    int Fraction::getNumerator() const{
        return this->numer;
    }
    int Fraction::getDenominator() const{
        return this->denom;
    }
    bool operator==(const Fraction& frac1, const float& frac2){
        return (frac1<=frac2 && frac1>=frac2);
    }
    bool operator==(const float& frac1,const Fraction& frac2){
        return (frac1<=frac2 && frac1>=frac2);
    }
    bool operator==(const Fraction& frac1,const Fraction& frac2){
        return (frac1<=frac2 && frac1>=frac2);
    }

    bool operator<=(const Fraction& frac1, const float& frac2){
        return frac2>=frac1;
    }
    bool operator<=(const float& frac1,const Fraction& frac2){
        return frac2>=frac1;
    }
    bool operator<=(const Fraction& frac1,const Fraction& frac2){
        return frac2>=frac1;
    }

    bool operator>=(const Fraction& frac1, const float& frac2){
        return !(frac1<frac2);
    }
    bool operator>=(const float& frac1,const Fraction& frac2){
        return !(frac1<frac2);
    }
    bool operator>=(const Fraction& frac1,const Fraction& frac2){
        return !(frac1<frac2);
    }
    // to execute
    bool operator<(const Fraction& frac1, const float& frac2){
        Fraction a(frac2);
        return frac1<a;
    }
    bool operator<(const float& frac1,const Fraction& frac2){
        Fraction a(frac1);
        return a<frac2;
    }
    bool operator<(const Fraction& frac1,const Fraction& frac2){
        int frac1_numer = frac1.numer*frac2.denom;
        int f2_numer = frac2.numer*frac1.denom;
        if(frac1_numer<f2_numer){
            return (true); 
        }
        else{
            return (false);
        }
    }

    bool operator>(const Fraction& frac1, const float& frac2){
        return frac2<frac1;
    }
    bool operator>(const float& frac1,const Fraction& frac2){
        return frac2<frac1;
    }
    bool operator>(const Fraction& frac1,const Fraction& frac2){
        return frac2<frac1;
    }
}