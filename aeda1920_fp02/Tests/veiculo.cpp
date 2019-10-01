#include "veiculo.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a)
{
    marca = mc;
    mes = m;
    ano = a;
}

string Veiculo::getMarca() const
{
    return marca;
}

int Veiculo::getAno() const
{
    return ano;
}

int Veiculo::getMes() const
{
    return mes;
}

int Veiculo::info() const
{
    cout << endl << "Marca: " << marca << endl << "Mes: " << mes << endl
    << "Ano: " << ano << endl;
    return 3;
}

bool Veiculo::operator < (const Veiculo & v) const
{
    return (ano < v.getAno() || (ano == v.getAno() && mes < v.getMes()));
}

Motorizado::Motorizado(string mc, int m, int a, string c, int cil) : Veiculo(mc, m, a)
{
    combustivel = c;
    cilindrada = cil;
}

string Motorizado::getCombustivel() const {
    return combustivel;
}

int Motorizado::info() const
{
    int infoV = Veiculo::info();
    cout << "Combustivel: " << combustivel << endl
    << "Cilindrada: " << cilindrada << endl;
    return 2 + infoV;
}

float Motorizado::calcImposto() const
{
    float imposto;

    if(combustivel == "gasolina")
    {
        if((cilindrada <= 1000))
        {
            if(ano > 1995) imposto = 14.56;
            else imposto = 8.10;
        }
        else if((cilindrada > 1000) && (cilindrada <= 1300))
        {
            if(ano > 1995) imposto = 29.06;
            else imposto = 14.56;
        }
        else if((cilindrada > 1300) && (cilindrada <= 1750))
        {
            if(ano > 1995) imposto = 45.15;
            else imposto = 22.65;
        }
        else if((cilindrada > 1750) && (cilindrada <= 2600))
        {
            if(ano > 1995) imposto = 113.18;
            else imposto = 54.89;
        }
        else if((cilindrada > 2600) && (cilindrada <= 3500))
        {
            if(ano > 1995) imposto = 181.17;
            else imposto = 87.13;
        }
        else
        {
            if(ano > 1995) imposto = 320.89;
            else imposto = 148.37;
        }
    }
    else
        {
            if((cilindrada <= 1500))
            {
                if(ano > 1995) imposto = 14.56;
                else imposto = 8.10;
            }
            else if((cilindrada > 1500) && (cilindrada <= 2000))
            {
                if(ano > 1995) imposto = 29.06;
                else imposto = 14.56;
            }
            else if((cilindrada > 2000) && (cilindrada <= 3000))
            {
                if(ano > 1995) imposto = 45.15;
                else imposto = 22.65;
            }
            else
            {
                if(ano > 1995) imposto = 113.98;
                else imposto = 54.89;
            }
        }
    return imposto;
}

Automovel::Automovel(string mc, int m, int a, string c, int cil) : Motorizado(mc, m, a, c, cil){}

int Automovel::info() const
{
    int infoM = Motorizado::info();
    return infoM;
}

Camiao::Camiao(string mc, int m, int a, string c, int cil, int cm) : Motorizado(mc, m, a, c, cil)
{
    carga_maxima = cm;
}

int Camiao::info() const
{
    int infoM = Motorizado::info();
    cout << "Carga Máxima: " << endl;
    return 1 + infoM;
}

Bicicleta::Bicicleta(string mc, int m, int a, string t) : Veiculo(mc, m, a)
{
    tipo = t;
}

int Bicicleta::info() const
{
    int infoV = Veiculo::info();
    cout << "Tipo: " << tipo << endl;
    return 1 + infoV;
}

float Bicicleta::calcImposto() const
{
    return 0;
}
