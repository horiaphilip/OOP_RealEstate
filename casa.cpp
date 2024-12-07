
#include "casa.h"
#include <iostream>

Casa::Casa(const std::string& adresa, double pret, double suprafata, int numarEtaje)
    : Imobil(adresa, pret, suprafata), m_numarEtaje(numarEtaje) {}

void Casa::afiseazaDetalii() const
{
    std::cout << "Adresa: " << getAdresa() << "\n";
    std::cout << "Suprafata: " << getSuprafata() << " mp\n";
    std::cout << "Pret (/m^2): " << calculeazaPretPeMetruPatrat() << " euro\n";
    std::cout << "Numar etaje: " << m_numarEtaje << "\n";
}

double Casa::calculeazaPretPeMetruPatrat() const
{
    return getPret() / getSuprafata();
}

double Casa::calculeazaComision() const
{
    return getPret() * 0.04 + m_numarEtaje * 200;
}

Casa& Casa::operator=(const Casa& other)
{
    if (this != &other)
    {
        m_numarEtaje = other.m_numarEtaje;
        Imobil::operator=(other);
    }
    return *this;
}
