#include "apartament.h"
#include <iostream>

Apartament::Apartament(const std::string& adresa, double pret, double suprafata, int numarCamere)
    : Imobil(adresa, pret, suprafata), m_numarCamere(numarCamere) {}

void Apartament::afiseazaDetalii() const
{
    std::cout << "Adresa: " << getAdresa() << "\n";
    std::cout << "Suprafata: " << getSuprafata() << " mp\n";
    std::cout << "Pret (/m^2): " << calculeazaPretPeMetruPatrat() << " euro\n";
    std::cout << "Numar camere: " << m_numarCamere << "\n";
}

double Apartament::calculeazaPretPeMetruPatrat() const
{
    return getPret() / getSuprafata();
}

double Apartament::calculeazaComision() const
{
    return getPret() * 0.03 + m_numarCamere * 100;
}

Apartament& Apartament::operator=(const Apartament& other)
{
    if (this != &other)
    {
        m_numarCamere = other.m_numarCamere;
        Imobil::operator=(other);
    }
    return *this;
}
