#pragma once

#include <string>

class Client
{
protected:
    std::string nume;
    std::string recenzie;
public:
    Client(const std::string& nume,const std::string& recenzie);
    virtual ~Client();
    virtual std::string getRecenzie() const;
    virtual std::string getNume() const;
    static void feedback();

};

class ClientMultumit : public Client
{
public:
    ClientMultumit(const std::string& nume,const std::string& recenzie);


};

class ClientNemultumit : public Client
{
public:
    ClientNemultumit(const std::string& nume,const std::string& recenzie);


};

