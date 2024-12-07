#pragma once

#include "imobil.h"

class Teren : public Imobil
{
public:
    Teren(const std::string& adresa, double pret, double suprafata, bool esteIntravilan);
    virtual void afiseazaDetalii() const override;
    virtual double calculeazaPretPeMetruPatrat() const override;
    virtual double calculeazaComision() const override;
    virtual Teren& operator=(const Teren& other) ;
    static void afiseazaTipul();
private:
    bool m_esteIntravilan;
};


