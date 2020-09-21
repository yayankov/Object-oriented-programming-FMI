#include <iostream>
#include "DNSCache.h"
int main()
{
    DNSCache cache;
    
    cache.add(DNSRecord("Todor","323232"));
    cache.add(DNSRecord("Pesho","123123123"));
    
    std::cout<<cache.lookup("Pesho")<<std::endl;
    
    cache.print();
    cache.flush();
    cache.print();
    
    return 0;
}
