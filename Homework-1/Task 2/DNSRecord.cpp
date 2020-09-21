#include "DNSRecord.h"
#include<cstring>
void DNSRecord::CopyString(const char* src,char* &destination)
{
    if(src==nullptr){return;}
    if(destination)
        delete[] destination;
    
    unsigned long length = strlen(src)+1;
    destination = new char[length];
    strcpy(destination, src);
    destination[length-1]='\0';
    
}

DNSRecord::DNSRecord(const char*domainName ,const char*ipAddress)
{
    this->domainName=nullptr;
    this->ipAddress=nullptr;
    CopyString(domainName, this->domainName);
    CopyString(ipAddress, this->ipAddress);
}
DNSRecord::DNSRecord():DNSRecord(nullptr,nullptr)
{
    
}
DNSRecord::DNSRecord(const DNSRecord &other):DNSRecord(other.domainName,other.ipAddress)
{
    
}

DNSRecord::~DNSRecord(){
    if(domainName)
        delete[] domainName;
    
    if(ipAddress)
        delete[] ipAddress;
}
DNSRecord& DNSRecord::operator=(const DNSRecord &other)
{
    CopyString(other.domainName, this->domainName);
    CopyString(other.ipAddress, this->ipAddress);
    return *this;
}
