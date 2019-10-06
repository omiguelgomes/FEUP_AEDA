#include "frota.h"
#include <string>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1)
{
    veiculos.push_back(v1);
}

int Frota::numVeiculos() const
{
    return veiculos.size();
}

int Frota::menorAno() const
{
    if(veiculos.size() == 0)
    {
        return 0;
    }
    int menor = INT_MAX;

    for(Veiculo *v : veiculos)
    {
        if(v->getAno() < menor)
            menor = v->getAno();
    }
    return menor;
}

float Frota::totalImposto() const
{
    if(numVeiculos() == 0) return 0;

    float total = 0;
    for(auto v : veiculos)
    {
        total+=v->calcImposto();
    }
    return total;
}

ostream & operator<<(ostream & o, const Frota & f)
{
    vector<Veiculo *>::const_iterator it=f.veiculos.begin();
    while(it!=f.veiculos.end()) {
        (*it)->info();
        it++;
    }
    return o;
}

vector<Veiculo *> Frota::operator()(int anoM) const {
    vector<Veiculo *> veiculosAno;
    for(auto v : veiculos)
    {
        if(v->getAno() == anoM)
        {
            veiculosAno.push_back(v);
        }
    }
    return veiculosAno;
}




