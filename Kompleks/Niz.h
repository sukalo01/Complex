#pragma once
#include "Kompleks.h"


class Niz
{
    private:
    int cap;
    int size;
    Kompleks* arr;

    public:
    Niz(int capacity=1):cap(capacity), size(0), arr(new Kompleks[cap]){}
    ~Niz(){delete[] this->arr;}
    Niz(const Niz&);
    Niz(Niz&&);
    Niz& operator=(const Niz&);
    Niz& operator=(Niz&&);
    void add(const Kompleks&);
    //void del();
    void addat(const Kompleks&, int i);
    void forEach(Kompleks (*f)(Kompleks&));

};
Niz::Niz(const Niz& drugi)
{
    this->cap=drugi.cap;
    this->size=drugi.size;
    for(int i=0; i<size; i++)
        this->arr[i]=drugi.arr[i];
}

Niz::Niz(Niz&& drugi)
{
    this->cap=drugi.cap;
    this->size=drugi.size;
    this->arr=drugi.arr;
    drugi.arr=nullptr;
}

Niz& Niz::operator= (const Niz& drugi)
{
    /*if(*this==drugi)
        return *this;*/
    this->cap=drugi.cap;
    this->size=drugi.size;
    for(int i=0; i<size; i++)
        this->arr[i]=drugi.arr[i];
    return *this;
}

Niz& Niz::operator= (Niz&& drugi)
{
    /*if(*this==drugi)
        return *this;*/
    this->cap=drugi.cap;
    this->size=drugi.size;
    this->arr=drugi.arr;
    drugi.arr=nullptr;
    return *this;
}

void Niz::add(const Kompleks& trg)
{
    if(this->cap==this->size)
    {
        //this->realloc();
    }
    this->arr[size]=trg;
    this->size+=1;

}

/*void Niz::del()
{
    this->size-=1;
}*/

void Niz::addat(const Kompleks& trg, int i)
{
    if(this->cap==this->size)
    {
        //this->realloc();
    }
    for(int j=this->size;j>i;j--)
    {
        this->arr[j]=this->arr[j-1];
    }
    this->arr[i]=trg;
    this->size+=1;
}

void Niz::forEach(Kompleks (*f)(Kompleks& ))
{
    Kompleks a;
    for(int i=0;i<this->size;i++)
    {
        a=f(this->arr[i]);
        std::cout<<a<<std::endl;

    }
    
}