#include <iostream>
#include <vector>
#include "agent_vanzari.h"
#include "client.h"
#include <memory>


int main()
{

    std::vector<std::unique_ptr<AgentVanzari>> agenti;

    agenti.push_back(std::make_unique<AgentVanzari>("Alin", "Petre", "AV001"));
    agenti.push_back(std::make_unique<AgentVanzari>("Alisa", "Georgescu", "AV002"));
    agenti.push_back(std::make_unique<AgentVanzari>("David", "Radu", "AV003"));
    agenti.push_back(std::make_unique<AgentVanzari>("Andrei", "Ionescu", "AV004"));


    agenti[0]->adaugaCasa(Casa("Str. Primaverii 10", 150000, 200, 2));
    agenti[0]->adaugaCasa(Casa("Str. Libertatii 25", 250000, 300, 3));
    agenti[0]->adaugaCasa(Casa("Str. Republicii 5", 350000, 400, 4));

    agenti[0]->adaugaTeren(Teren("Str. Pacii 15", 50000, 500, true));
    agenti[0]->adaugaTeren(Teren("Str. Mihai Viteazu 30", 75000, 600, false));
    agenti[0]->adaugaTeren(Teren("Str. Victoriei 20", 100000, 700, true));

    agenti[0]->adaugaApartament(Apartament("Str. Aviatorilor 5", 100000, 100, 2));
    agenti[0]->adaugaApartament(Apartament("Str. Unirii 12", 120000, 120, 3));
    agenti[0]->adaugaApartament(Apartament("Str. Eroilor 8", 140000, 140, 4));


    agenti[1]->adaugaCasa(Casa("Str. Parcului 1", 200000, 250, 3));
    agenti[1]->adaugaCasa(Casa("Str. Florilor 10", 300000, 350, 4));
    agenti[1]->adaugaCasa(Casa("Str. Stefan cel Mare 15", 400000, 450, 5));

    agenti[1]->adaugaTeren(Teren("Str. Garii 20", 60000, 600, true));
    agenti[1]->adaugaTeren(Teren("Str. Independentei 25", 80000, 700, false));
    agenti[1]->adaugaTeren(Teren("Str. Ion Creanga 30", 120000, 800, true));

    agenti[1]->adaugaApartament(Apartament("Str. I.L. Caragiale 10", 150000, 150, 3));
    agenti[1]->adaugaApartament(Apartament("Str. Vasile Alecsandri 12", 180000, 180, 4));
    agenti[1]->adaugaApartament(Apartament("Str. George Enescu 15", 200000, 200, 5));

    agenti[3]->adaugaCasa(Casa("Str. Republicii 50", 220000, 270, 3));
    agenti[3]->adaugaCasa(Casa("Str. Libertatii 55", 320000, 370, 4));
    agenti[3]->adaugaCasa(Casa("Str. Parcului 60", 420000, 470, 5));

    agenti[3]->adaugaTeren(Teren("Str. Mihai Viteazu 65", 65000, 600, true));
    agenti[3]->adaugaTeren(Teren("Str. Victoriei 70", 85000, 700, false));
    agenti[3]->adaugaTeren(Teren("Str. Garii 75", 105000, 800, true));

    agenti[3]->adaugaApartament(Apartament("Str. Vasile Alecsandri 30", 160000, 160, 3));
    agenti[3]->adaugaApartament(Apartament("Str. George Enescu 32", 190000, 190, 4));
    agenti[3]->adaugaApartament(Apartament("Str. I.L. Caragiale 35", 210000, 210, 5));

    int optiune;
    do
    {

        std::cout << "\n\n~~~ Meniu Imobiliare ~~~\n";
        std::cout << "1. Doresc sa vand un imobil\n";
        std::cout << "2. Afiseaza detalii imobile\n";
        std::cout << "3. Doresc sa cumpar un imobil\n";
        std::cout << "4. Vreau sa las o recenzie\n";
        std::cout << "5. Vizualizeaza recenziile agentiilor nostri\n";
        std::cout << "0. Iesire\n";
        std::cout << "Alegeti optiunea: ";
        std::cin >> optiune;
        std::cout<<"\n";

        switch (optiune)
        {
        case 1:
        {

            int tipImobil;
            std::cout << '\n';
            std::cout << "Selectati tipul imobilului pe care doriti sa il vindeti:\n";
            std::cout << "1. Casa\n";
            std::cout << "2. Teren\n";
            std::cout << "3. Apartament\n";
            std::cout << "Optiune: ";
            std::cin >> tipImobil;

            std::string adresa;
            double pret, suprafata;
            std::cout << "Introduceti adresa: ";
            std::cin.ignore();
            std::getline(std::cin, adresa);
            std::cout << "Introduceti pretul: ";
            std::cin >> pret;
            std::cout << "Introduceti suprafata: ";
            std::cin >> suprafata;

            int idAgent;
            std::cout << "\nSelectati indexul agentului de vanzari cu care doriti sa colaborati:\n";
            for (size_t i = 0; i < agenti.size(); ++i)
            {
                std::cout << i + 1 << ". " << agenti[i]->getNume() << " " << agenti[i]->getPrenume() << " (" << agenti[i]->getCod() << ")\n";
            }
            std::cout << "Optiune: ";
            std::cin >> idAgent;

            if (tipImobil == 1)
            {
                int numarEtaje;
                std::cout << "\nIntroduceti numarul de etaje: ";
                std::cin >> numarEtaje;
                Casa casa_noua(adresa, pret, suprafata, numarEtaje);
                agenti[idAgent - 1]->adaugaCasa(casa_noua);

            }
            else if (tipImobil == 2)
            {
                bool esteIntravilan;
                std::cout << "\nEste intravilan? (1 - Da, 0 - Nu): ";
                std::cin >> esteIntravilan;
                Teren teren_nou(adresa, pret, suprafata, esteIntravilan);
                agenti[idAgent - 1]->adaugaTeren(teren_nou);
            }
            else if (tipImobil == 3)
            {
                int numarCamere;
                std::cout << "\nIntroduceti numarul de camere: ";
                std::cin >> numarCamere;
                Apartament apartament_nou(adresa, pret, suprafata, numarCamere);
                agenti[idAgent - 1]->adaugaApartament(apartament_nou);

            }
            else
            {
                std::cout << "Optiune invalida!\n";
            }

            std::cout << "\nImobilul dvs a fost adaugat cu succes in oferta agentului!";
            std::cout<<"\nVa mentionam ca la pretul de vanzare se adauga "<<agenti[idAgent-1]->getProcentCastig()*100<<"% procentul agentului de vanzari.";
            break;
        }
        case 2:
        {
            std::cout << "\n~~~ Detalii Imobile ~~~\n";
            for (size_t i = 0; i < agenti.size(); ++i)
            {
                std::cout << "\n~~~ Imobilele agentului " << agenti[i]->getNume() << " " << agenti[i]->getPrenume() << " (" << agenti[i]->getCod() << ") ~~~\n\n";
                agenti[i]->afiseazaDetaliiImobile();
            }
            break;
        }
        case 3:
        {
            int idAgent, indexImobil,tipImobil;
            std::cout << "Selectati indexul agentului de vanzari:\n";
            for (size_t i = 0; i < agenti.size(); ++i)
            {
                std::cout << i + 1 << ". " << agenti[i]->getNume() << " " << agenti[i]->getPrenume() << " (" << agenti[i]->getCod() << ")\n";
            }
            std::cout << "Optiune: ";
            std::cin >> idAgent;


            agenti[idAgent - 1]->afiseazaDetaliiImobile();

            std::cout << "Selectati tipul imobilului: (1-casa, 2-teren, 3-apartament):";
            std::cin >> tipImobil;
            std::cout << "Selectati numarul imobilului in categoria aleasa:";
            std::cin >> tipImobil;
            double pretFinal = agenti[idAgent - 1]->calculeazaPretFinalImobil(tipImobil, indexImobil);
            std::cout << "\nPretul final al imobilului este: " << pretFinal << " euro"<< std::endl;
            break;
        }
        case 0:
            std::cout << "La revedere!\n";
            break;


        case 4:
        {
            int idAgent, nota;
            std::string recenzie,numeClient;
            std::cout << "\nVa rugam sa va introduceti numele: ";
            std::cin.ignore();
            std::getline(std::cin, numeClient);
            std::cout << "\nSelectati indexul agentului de vanzari:\n";
            for (size_t i = 0; i < agenti.size(); ++i)
            {
                std::cout << i + 1 << ". " << agenti[i]->getNume() << " " << agenti[i]->getPrenume() << " (" << agenti[i]->getCod() << ")\n";
            }
            std::cout << "Optiune: ";
            std::cin >> idAgent;

            std::cout << "\nIntroduceti nota (de la 1 la 10): ";
            std::cin >> nota;

            std::cout << "Introduceti recenzia: ";
            std::cin.ignore();
            std::getline(std::cin, recenzie);
            std::shared_ptr<Client> client = std::make_shared<ClientMultumit>(numeClient,recenzie);
            if (nota >= 6)
            {
                std::shared_ptr<Client> client = std::make_shared<ClientMultumit>(numeClient,recenzie);
                std::shared_ptr<ClientMultumit> c_multumit = std::dynamic_pointer_cast<ClientMultumit>(client);

                agenti[idAgent - 1]->adaugaMultumit(c_multumit);

            }
            else
            {
                std::shared_ptr<Client> client = std::make_shared<ClientNemultumit>(numeClient,recenzie);
                std::shared_ptr<ClientNemultumit> c_nemultumit = std::dynamic_pointer_cast<ClientNemultumit>(client);

                agenti[idAgent - 1]->adaugaNemultumit(c_nemultumit);
            }
            std::cout<<"\nRecenezia a fost inregistrata cu succes! Va multumim.";

            //agenti[idAgent - 1]->getClient()->feedback(nota, recenzie);
            break;
        }
        case 5:
        {
            std::cout << "\n~~~ Feedback Agenti ~~~\n";
            for (const auto& agent : agenti)
            {
                std::cout << "\n~~~ Feedback Agent " << agent->getNume() << " " << agent->getPrenume() << " (" << agent->getCod() << ") ~~~\n";

                auto clienti_multumiti = agent->getClientiMultumiti();
                if (!clienti_multumiti.empty())
                {
                    std::cout << "Clienti Multumiti:\n";
                    for (const auto& client : clienti_multumiti)
                    {
                        std::cout << "Nume: " << client->getNume() << ", Feedback: " << client->getRecenzie() << std::endl;
                    }
                }
                else
                {
                    std::cout << "Nu exista clienti multumiti pentru acest agent.\n";
                }

                auto clienti_nemultumiti = agent->getClientiNemultumiti();
                if (!clienti_nemultumiti.empty())
                {
                    std::cout << "Clienti Nemultumiti:\n";
                    for (const auto& client : clienti_nemultumiti)
                    {
                        std::cout << "Nume: " << client->getNume() << ", Feedback: " << client->getRecenzie() << std::endl;
                    }
                }
                else
                {
                    std::cout << "Nu exista clienti nemultumiti pentru acest agent.\n";
                }
            }
            break;
        }

        default:
            std::cout << "Optiune invalida!\n";
            break;
        }
    }
    while (optiune != 0);

    return 0;
}
