#include "Niz.h"
#include <iostream>

int main()
{
    Kompleks a(1,2);
    Kompleks b(3,6);
    Kompleks c(6,4);
    Kompleks d(5,5);
    Kompleks f;
    f=a+b;
    std::cout<<"a "<<a<<std::endl;
    std::cout<<"b "<<b<<std::endl;
    std::cout<<"c "<<c<<std::endl;
    std::cout<<"d "<<a<<std::endl;
    std::cout<<"f "<<f<<std::endl;
    a+=b;
    std::cout<<"a+=b "<<a<<std::endl;
    if(a!=b)
        std::cout<<"razlicito"<<std::endl;
    Niz are(10);
    are.add(a);
    are.add(b);
    are.add(c);
    are.add(d);
    are.add(f);
    are.forEach([] (Kompleks& drugi)
    {
        Kompleks es;
        es.setRe(2*drugi.getRe());
        es.setIm(drugi.getIm());
        return es;
    });

}