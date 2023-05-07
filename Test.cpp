#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/Fraction.hpp"


using namespace std;
using namespace ariel;
TEST_CASE("constractor"){
    CHECK_NOTHROW(Fraction a(1,8));
    CHECK_NOTHROW(Fraction a(9,2));
    CHECK_NOTHROW(Fraction a(3,3));
    CHECK_NOTHROW(Fraction a(-1,-8));
    CHECK_NOTHROW(Fraction a(-1,8));
    CHECK_NOTHROW(Fraction a(1,-8));
    CHECK_NOTHROW(Fraction a(0,8));
    CHECK_THROWS_AS(Fraction a(1,0),std::exception);
    CHECK_THROWS_AS(Fraction a(-2,0),std::exception);
}

TEST_CASE("+"){
    Fraction a(1,3), b(2,3),c(1,3),d(3,4);
    CHECK_EQ(a+b,1);
    CHECK_EQ(b+a,a+b);
    CHECK_EQ(a+c,b);
    CHECK_EQ(b+d,17.0/12);
    CHECK_EQ(a+b+c,4.0/3);
    CHECK_EQ(a+b+c,c+b+a);
    CHECK_EQ(a+0,c);
    CHECK_EQ(a+0,a);
    CHECK_EQ(b+0.2,13.0/15);
    CHECK_EQ(0.2+b,13.0/15);
}   
TEST_CASE("-"){
    Fraction a(1,3), b(2,3),c(1,3),d(3,4);
    CHECK_EQ(a-b,-1.0/3);
    CHECK_EQ(a-b,-c);
    CHECK_EQ(a-a,0);
    CHECK_EQ(a-c,0);
    CHECK_EQ(b-d,1.0/12);
    CHECK_EQ(a-b-c,-2.0/3);
    CHECK_EQ(a-0,c);
    CHECK_EQ(a-0,a);
    CHECK_EQ(b-0.2,7.0/15);
    CHECK_EQ(0.2-b,-7.0/15);
    CHECK_EQ(0-a,-a);
}   
TEST_CASE("*"){
    Fraction a(1,3), b(2,3),c(6,4),d(3,4);
    CHECK_EQ(a*b,2.0/3);
    CHECK_EQ(a*b,b*a);
    CHECK_EQ(a*-b,-2.0/3);
    CHECK_EQ(a*0,0);
    CHECK_EQ(b*c,1.0);
    CHECK_EQ(a*(b*c),(a*b)*c);
    CHECK_EQ(b*0.2,2.0/15);
    CHECK_EQ(0.2*b,2.0/15);
    CHECK_EQ(1.0*-a,-a);
} 
TEST_CASE("/"){
    Fraction a(1,3), b(2,3),c(6,4),d(3,4);
    CHECK_EQ(a/b,1.0/2);
    CHECK_EQ(b/a,2.0);
    CHECK_EQ(a/-b,-1.0/2);
    CHECK_EQ(0/a,0);
    CHECK_NOTHROW(0/a);
    CHECK_THROWS(a/0);
    CHECK_EQ(b/1.0,b);
    CHECK_EQ(b/-1.0,-b);
    CHECK_EQ(a/(b/c),3.0/4);
    CHECK_EQ(b/0.2,10.0/3);
    CHECK_EQ(0.2/b,3.0/10);
}  
TEST_CASE("++"){
    Fraction a(1,3), b(2,3),c(6,4),d(3,4);
    CHECK_EQ(a++,1.0/3);
    CHECK_EQ(++d,7.0/4);
    CHECK_EQ(2+(++b),11.0/3);
    CHECK_EQ((c++)+3,9.0/2);
}    
TEST_CASE("--"){
    Fraction a(1,3), b(2,3),c(6,4),d(3,4);
    CHECK_EQ(a--,1.0/3);
    CHECK_EQ(--d,-1.0/4);
    CHECK_EQ(2+(--b),5.0/3);
    CHECK_EQ((c--)+3,9.0/2);
} 
TEST_CASE("==,<=,>="){
    Fraction a(1,3), b(2,3),c(6,4),d(3,4),e(3,9);
    CHECK(a==a);
    CHECK(a<=a);
    CHECK(a>=a);
    CHECK(a<=b);
    CHECK_FALSE(a>=b);
    CHECK(c>=d);
    CHECK(a==e);
    CHECK(-a==-e);
    CHECK(a==1.0/3);
    CHECK(a==0.333);
    CHECK(a<=1);
    CHECK_FALSE(a>=1);

}
TEST_CASE("<,>"){
    Fraction a(1,3), b(2,3),c(6,4),d(3,4),e(-1,2);
    CHECK_FALSE(a<a);
    CHECK_FALSE(a>a);
    CHECK(a<b);
    CHECK_FALSE(a>b);
    CHECK(c>d);
    CHECK(e<a);
    CHECK(e<0);

}
TEST_CASE("<<,>>"){
    Fraction a(1,3), b(2,3),c(6,4),d(3,4);
    istringstream is1("5 9");
    istringstream is2("-5 -9"); 
    CHECK_NOTHROW(is1 >> b);
    CHECK_NOTHROW(is2 >> b);
    CHECK_NOTHROW(cout << c << endl);
    CHECK_NOTHROW(cout << c+a << endl);
    CHECK_NOTHROW(cout << c << endl);
}
TEST_CASE("combinatoin"){
    Fraction a(1,3), b(2,3),c(6,4),d(3,4);
    CHECK_EQ(a*b-c,-23.0/18);
    CHECK_EQ(b/a*d,3.0/8);
    CHECK_EQ(a+-b-c,-11.0/6);
    CHECK_EQ(0/a,0);
}
