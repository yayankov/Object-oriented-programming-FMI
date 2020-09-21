#pragma once

#include "DNSRecord.h"

class DNSCache{
private:
    DNSRecord *array;
    int size;
    int capacity;
    void grow(int capacity);

    
public:
    DNSCache(int capacity=16);
    DNSCache(DNSCache const &);
    ~DNSCache();
    DNSCache &operator=(DNSCache const &);
    void add(const DNSRecord &);
    const char* lookup(const char*);
    void flush();
    void print();
};
