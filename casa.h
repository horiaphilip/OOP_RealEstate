#pragma once

#include "imobil.h"

class Casa : public Imobil
{
public:
    Casa(const std::string& adresa, double pret, double suprafata, int numarEtaje);
    virtual void afiseazaDetalii() const override;
    virtual double calculeazaPretPeMetruPatrat() const override;
    virtual double calculeazaComision() const override;
    virtual Casa& operator=(const Casa& other) ;
private:
    int m_numarEtaje;
};

