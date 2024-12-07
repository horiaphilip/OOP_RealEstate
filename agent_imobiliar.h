// agent_vanzari.h
#ifndef AGENT_VANZARI_H
#define AGENT_VANZARI_H

#include <string>
#include <vector>
#include "casa.h"
#include "teren.h"
#include "apartament.h"
a
class AgentVanzari {
public:
    AgentVanzari(const std::string& nume, const std::string& prenume, const std::string& cod);
    void adaugaCasa(const Casa& casa);
    void adaugaTeren(const Teren& teren);
    void adaugaApartament(const Apartament& apartament);
    void afiseazaCase() const;
    void afiseazaTerenuri() const;
    void afiseazaApartamente() const;
    void afiseazaDetaliiImobile() const;
    double calculeazaPretFinal() const;
    void setProcentCastigPersonal(double procent);
    double calculeazaPretFinalImobil(size_t index) const;
private:
    std::string m_nume;
    std::string m_prenume;
    std::string m_cod;
    std::vector<Casa> m_case;
    std::vector<Teren> m_terenuri;
    std::vector<Apartament> m_apartamente;
    double m_procentCastigPersonal = 0.1;
};

#endif // AGENT_VANZARI_H

