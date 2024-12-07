#include "teren.h"
#include <iostream>

Teren::Teren(const std::string& adresa, double pret, double suprafata, bool esteIntravilan)
    : Imobil(adresa, pret, suprafata), m_esteIntravilan(esteIntravilan) {}

void Teren::afiseazaDetalii() const {
    std::cout << "Adresa: " << getAdresa() << "\n";
    std::cout << "Suprafata: " << getSuprafata() << " mp\n";
    std::cout << "Pret (/m^2): " << calculeazaPretPeMetruPatrat() << " euro\n";
    std::cout << "Este intravilan: " << (m_esteIntravilan ? "Da" : "Nu") << "\n";
}

double Teren::calculeazaPretPeMetruPatrat() const {
    return getPret() / getSuprafata();
}

double Teren::calculeazaComision() const {
    return getPret() * 0.02 + (m_esteIntravilan ? 1000 : 500);
}

Teren& Teren::operator=(const Teren& other) {
    if (this != &other) {
        m_esteIntravilan = other.m_esteIntravilan;
        Imobil::operator=(other);
    }
    return *this;
}

void Teren::afiseazaTipul() {
    std::cout << "Tip: Teren\n";
}
