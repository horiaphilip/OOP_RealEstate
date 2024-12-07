
#include "imobil.h"

Imobil::Imobil(const std::string& adresa, double pret, double suprafata)
    : m_adresa(adresa), m_pret(pret), m_suprafata(suprafata) {}

std::string Imobil::getAdresa() const
{
    return m_adresa;
}

void Imobil::setAdresa(const std::string& adresa)
{
    m_adresa = adresa;
}

double Imobil::getPret() const
{
    return m_pret;
}

void Imobil::setPret(double pret)
{
    m_pret = pret;
}

double Imobil::getSuprafata() const
{
    return m_suprafata;
}

void Imobil::setSuprafata(double suprafata)
{
    m_suprafata = suprafata;
}
Imobil& Imobil::operator=(const Imobil& other)
{
    if (this != &other)
    {
        m_adresa = other.m_adresa;
        m_pret = other.m_pret;
        m_suprafata = other.m_suprafata;
    }
    return *this;
}
