#pragma once
#include <iostream>


class Kompleks
{
    private:
    double re;
    double im;

    public:
    Kompleks (double i=0, double j=0):re(i),im(j){}
    double getRe()const{return this->re;}
    void setRe(int i){this->re=i;}
    double getIm()const{return this->im;}
    void setIm(int i){this->im=i;}
    Kompleks operator+ (const Kompleks& drugi)const;
    Kompleks operator- (const Kompleks& drugi)const;
    Kompleks& operator+= (const Kompleks& drugi);
    bool operator==(const Kompleks& drugi)const;
    bool operator!=(const Kompleks& drugi)const;
    

};
std::ostream& operator<<( std::ostream& os, const Kompleks& obj)
{
    std::cout<<obj.getRe()<<"+ i"<<obj.getIm()<<std::endl;
    return os;
}
Kompleks Kompleks::operator+(const Kompleks& drugi) const
{
    return Kompleks(this->re+drugi.re,this->im+drugi.im);
}

Kompleks Kompleks::operator-(const Kompleks& drugi) const
{
    return Kompleks(this->re-drugi.re,this->im-drugi.im);
}

Kompleks& Kompleks::operator+= (const Kompleks& drugi)
{
    this->re+=drugi.re;
    this->im+=drugi.im;
    return *this;
}

bool Kompleks::operator==(const Kompleks& drugi)const
{
    if(this->re==drugi.re && this->im==drugi.im)
        return true;
    return false;

}

bool Kompleks::operator!=(const Kompleks& drugi)const
{
    return !(*this==drugi);
}