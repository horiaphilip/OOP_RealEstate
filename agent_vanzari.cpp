
#include "agent_vanzari.h"
#include <iostream>
#include <memory>

AgentVanzari::AgentVanzari(const std::string& nume, const std::string& prenume, const std::string& cod)
    : m_nume(nume), m_prenume(prenume), m_cod(cod) {}

void AgentVanzari::adaugaCasa(const Casa& casa)
{
    m_case.push_back(casa);
}
void AgentVanzari::adaugaMultumit(std::shared_ptr<ClientMultumit>multumit)
{
    m_multumiti.push_back(multumit);
}
void AgentVanzari::adaugaNemultumit(std::shared_ptr<ClientNemultumit>nemultumit)
{
    m_nemultumiti.push_back(nemultumit);
}
std::string AgentVanzari::getNume() const
{
    return m_nume;
}
std::string AgentVanzari::getPrenume() const
{
    return m_prenume;
}
std::vector<std::shared_ptr<ClientMultumit>> AgentVanzari::getClientiMultumiti() const
{
    return m_multumiti;
}

std::vector<std::shared_ptr<ClientNemultumit>> AgentVanzari::getClientiNemultumiti() const
{
    return m_nemultumiti;
}


double AgentVanzari::getProcentCastig() const
{
    return m_procentCastigPersonal;
}

std::string AgentVanzari::getCod() const
{
    return m_cod;
}

void AgentVanzari::adaugaTeren(const Teren& teren)
{
    m_terenuri.push_back(teren);
}

void AgentVanzari::adaugaApartament(const Apartament& apartament)
{
    m_apartamente.push_back(apartament);
}

void AgentVanzari::afiseazaCase() const
{
    std::cout << "Oferta agentului contine " << m_case.size() << " case:\n ";
    for (const auto& casa : m_case)
    {
        std::cout << "----------------\n";
        casa.afiseazaDetalii();
    }
    std::cout << "----------------\n";
}

void AgentVanzari::afiseazaTerenuri() const
{
    std::cout << "Oferta agentului contine " << m_terenuri.size() << " terenuri:\n ";
    for (const auto& teren : m_terenuri)
    {
        std::cout << "----------------\n";
        teren.afiseazaDetalii();
    }
    std::cout << "----------------\n";
}

void AgentVanzari::afiseazaApartamente() const
{
    std::cout << "Oferta agentului contine " << m_apartamente.size() << " apartamente:\n ";
    for (const auto& apartament : m_apartamente)
    {
        std::cout << "----------------\n";
        apartament.afiseazaDetalii();
    }
    std::cout << "----------------\n";
}

void AgentVanzari::afiseazaDetaliiImobile() const
{
    afiseazaCase();
    afiseazaTerenuri();
    afiseazaApartamente();
}
double AgentVanzari::m_procentCastigPersonal = 0.05;

double AgentVanzari::calculeazaPretFinalImobil(const int tip,const int nr) const
{
    double pretFinal = 0.0;


    if (tip==1)
    {
        pretFinal = m_case[nr].getPret() + m_case[nr].calculeazaComision();
    }
    else if (tip ==2)
    {

        pretFinal = m_terenuri[nr].getPret() + m_terenuri[nr].calculeazaComision();
    }
    else if (tip==3)
    {
        pretFinal = m_apartamente[nr].getPret() + m_apartamente[nr].calculeazaComision();
    }
    return pretFinal+pretFinal*m_procentCastigPersonal;
}

