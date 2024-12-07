#pragma once
#include "imobil.h"

class Apartament : public Imobil
{
public:
    Apartament(const std::string& adresa, double pret, double suprafata, int numarCamere);
    virtual void afiseazaDetalii() const override;
    virtual double calculeazaPretPeMetruPatrat() const override;
    virtual double calculeazaComision() const override;
    virtual Apartament& operator=(const Apartament& other) ;
    static void afiseazaTipul();
private:
    int m_numarCamere;
};


