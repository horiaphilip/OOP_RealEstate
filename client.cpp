#include "client.h"
#include <iostream>

Client::Client(const std::string& nume,const std::string& recenzie) : nume(nume),recenzie(recenzie) {}

Client::~Client() {}

ClientMultumit::ClientMultumit(const std::string& nume,const std::string& recenzie) : Client(nume,recenzie) {}

std::string Client::getRecenzie() const
{
    return recenzie;
}
std::string Client::getNume() const
{
    return nume;
}
ClientNemultumit::ClientNemultumit(const std::string& nume,const std::string& recenzie) : Client(nume,recenzie) {}


