#include "parque.h"
#include <vector>
#include <iostream>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli){
    this->lotacao = lot;
    this->numMaximoClientes = nMaxCli;
    this->vagas = lot;
}

unsigned int ParqueEstacionamento::getNumLugares()const
{
    return lotacao;
}
unsigned int ParqueEstacionamento::getNumMaximoClientes() const
{
    return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
    for(int i = 0; i < clientes.size(); i++)
    {
        if(clientes.at(i).nome == nome) return i;
    }
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string &nome)//REGISTAR
{
    if(posicaoCliente(nome) != -1)
    {
        return false;
    }
    else
        {
        if(clientes.size() < numMaximoClientes) {
            InfoCartao novo;
            novo.nome = nome;
            novo.presente = false;
            clientes.push_back(novo);
            return true;
        }
        return false;
    }
}

bool ParqueEstacionamento::entrar(const string &nome)
{
    if(vagas <= 0) return false;

    for(InfoCartao info : this->clientes)
    {
        if(info.nome == nome)
        {
            if(info.presente) return false;
            else{
                vagas--;
                clientes.at(posicaoCliente(nome)).presente = true;
                return true;
            }
            }
        }
    return false;
}

bool ParqueEstacionamento::retiraCliente(const string &nome)
{
    int pos = posicaoCliente(nome);
    if(pos == -1) return false;

    if((pos == -1) || clientes.at(pos).presente) return false;
    else
        {
        clientes.erase(clientes.begin()+pos);
        return true;
    }
}

bool ParqueEstacionamento::sair(const string &nome)
{
    int pos = posicaoCliente(nome);
    if(pos == -1) return false;

    if(!(clientes.at(pos).presente)) return false;

    clientes.at(pos).presente = false;
    vagas++;
    return true;
}

int ParqueEstacionamento::getNumLugaresOcupados() const
{
    return lotacao-vagas;
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const
{
    return clientes.size();
}
