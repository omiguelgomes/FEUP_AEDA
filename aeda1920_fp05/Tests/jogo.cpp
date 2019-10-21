/*
 * jogo.cpp
 */

#include "jogo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Jogo::numPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = frase.find(' ');
  while (pos != string::npos) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}

// a implementar
Jogo::Jogo()
{
}


Jogo::Jogo(list<Crianca>& lc2)
{
    for(Crianca c : lc2)
        criancas.push_back(c);
}


void Jogo::insereCrianca(const Crianca &c1)
{criancas.push_back(c1);}


list<Crianca> Jogo::getCriancasJogo() const
{return criancas;}

string Jogo::escreve() const
{
    string infoCriancas;
    for(Crianca c : criancas)
    {
        infoCriancas += c.escreve() +"\n";
    }
    return infoCriancas;
}

// a implementar
Crianca& Jogo::perdeJogo(string frase)
{
    auto criancaIt = criancas.begin();
    int resto;

    while(criancas.size()>1) {
        resto = numPalavras(frase) % criancas.size(); //gives position, not index

        if (resto == 0) resto = criancas.size(); //gives position, not index

        advance(criancaIt, resto-1);

        criancaIt = criancas.erase(criancaIt);

        if(criancaIt==criancas.end())
            criancaIt = criancas.begin();
    }
    return *criancaIt;
}

list<Crianca>& Jogo::inverte()
{
    list<Crianca> invertedCriancas;
    auto iterator = criancas.begin();
    while(iterator!=criancas.end())
    {
        invertedCriancas.push_front(*iterator);
        iterator++;
    }
    criancas = invertedCriancas;
    return criancas;
}

list<Crianca> Jogo::divide(unsigned id)
{
    list<Crianca> res;
    auto iterator = criancas.begin();

    while(iterator!=criancas.end()) {
        if (iterator->getIdade() > id) {
            res.push_back(*iterator);
            iterator = criancas.erase(iterator);
        } else {
            iterator++;
        }
    }
    return res;
}

void Jogo::setCriancasJogo(const list<Crianca>& l1)
{criancas = l1;}

bool Jogo::operator==(Jogo& j2)
{
    bool iguais = true;
    if(criancas.size()!=j2.criancas.size()) return false;

    auto thisIterator = criancas.begin();
    auto j2Iterator = j2.criancas.begin();

    while(thisIterator!=criancas.end())
    {
        if(!(*thisIterator==*j2Iterator)) iguais = false;
        thisIterator++;
        j2Iterator++;
    }

	return iguais;
}

list<Crianca> Jogo::baralha() const
{
    list<Crianca> res;
    list<Crianca> temp = criancas;
    auto iterator = temp.begin();
    int randomNumber;

    while(temp.size()>0)
    {
        randomNumber = rand() % temp.size();
        advance(iterator, randomNumber);
        res.push_back(*iterator);
        iterator = temp.erase(iterator);
        iterator=temp.begin();
    }
    return res;
}
