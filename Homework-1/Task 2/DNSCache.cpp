
#include "DNSCache.h"
#include <cstring>
#include <iostream>
DNSCache::DNSCache(int capacity)
{
    size=0;
    array=nullptr;
    grow(capacity);
}

DNSCache::DNSCache(DNSCache const &other):DNSCache(other.size)
{
    this->size=other.size;
    for(int i=0;i<this->size;i++)
        this->array[i]=other.array[i];
}

DNSCache& DNSCache::operator=(DNSCache const &other)
{
    if (this != &other) {
        this->size = other.size;
        grow(other.size);
        for(int i=0;i<this->size;i++)
            this->array[i]=other.array[i];
    }
    
    return *this;
}

DNSCache::~DNSCache()
{
    if(array)
        delete[] array;
}

void DNSCache::grow(int capacity)
{
    DNSRecord *array2 = new DNSRecord[capacity];
    if(array){
        for(int i=0;i<this->size;i++)
            array2[i]=array[i];
        delete[] array;
    }
    array=array2;
    this->capacity=capacity;
}
void DNSCache::add(DNSRecord const &record)
{
    if(size==capacity)
        grow(2*capacity);
    array[size++]=record;
}

const char* DNSCache::lookup(const char*domainName)
{
    for(int i=0;i<size;i++)
        if(strcmp(array[i].domainName, domainName)==0)
            return array[i].ipAddress;
    return nullptr;
}

void DNSCache::flush()
{
    if(array)
        delete[] array;
    size=0;
    capacity=0;
    array=nullptr;
}
void DNSCache::print()
{
    for(int i=0;i<size;i++)
        std::cout<<array[i].domainName<<" : "<<array[i].ipAddress<<std::endl;
    if(size==0)
        std::cout<<"Empty"<<std::endl;
    
}
