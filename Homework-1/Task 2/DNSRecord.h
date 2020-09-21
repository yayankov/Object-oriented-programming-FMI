#pragma once

struct DNSRecord
{
    char *domainName;
    char *ipAddress;
    
    DNSRecord(const char *domainName,const char *ipAddress);
    DNSRecord();
    DNSRecord(const DNSRecord &);
    ~DNSRecord();
    DNSRecord &operator =(const DNSRecord &);
    
    private :
    static void CopyString(const char* src,char* &destination);
    
};
