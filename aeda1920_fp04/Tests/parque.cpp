#include "parque.h"
#include "insertionSort.h"
#include "insertionSortName.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot;
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::getClientes() const { return clientes; }

unsigned int ParqueEstacionamento::getNumLugares() const { return lotacao; }

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const { return lotacao-vagas; }


int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
    InfoCartao i;
    i.nome = nome;
    return sequentialSearch(clientes, i);
}

int ParqueEstacionamento::getFrequencia(const string &nome) const
{
    int clienteIndex = posicaoCliente(nome);
    if(clienteIndex == -1)
    {
        throw ClienteNaoExistente(nome);
    }
    return clientes.at(clienteIndex).frequencia;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
	clientes.push_back(info);
	numClientes++;
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if ( it->presente == false ) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;
	clientes[pos].presente = true;
    clientes[pos].frequencia++;
	vagas--;
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}


void ParqueEstacionamento::ordenaClientesPorFrequencia()
{
    insertionSort(clientes);
}


void ParqueEstacionamento::ordenaClientesPorNome()
{
    insertionSortName(clientes);
}

vector<string> ParqueEstacionamento::clientesGamaUso(int n1, int n2)
{
    vector<string> nomes;
    for(int i = 0; i < clientes.size(); i++)
    {
        if((clientes.at(i).frequencia >= n1) && (clientes.at(i).frequencia <= n2))
            nomes.push_back(clientes.at(i).nome);
    }
    insertionSort(nomes);
    return nomes;
}


ostream & operator<<(ostream & os, const ParqueEstacionamento & pe)
{
    for(InfoCartao i : pe.clientes)
    {
        os << i.nome << endl << i.presente << endl << i.frequencia << endl << endl;
    }
    return os;
}


InfoCartao ParqueEstacionamento::getClienteAtPos(vector<InfoCartao>::size_type p) const
{
    if(clientes.size() <= p)
        throw PosicaoNaoExistente(p);
    InfoCartao info = this->clientes.at(p);
    return info;
}


bool InfoCartao::operator==(InfoCartao i) const
{
    return (this->nome == i.nome);
}


bool InfoCartao::operator<(InfoCartao i) const //made to work with insertionSort provided, actually returns if its >
{
    if(this->frequencia < i.frequencia)
        return false;

    if(this->frequencia == i.frequencia)
        return this->nome < i.nome;

    return true;
}


PosicaoNaoExistente::PosicaoNaoExistente(const int pos)
{
    this->pos = pos;
}


int PosicaoNaoExistente::getValor() const
{
    return pos;
}


ClienteNaoExistente::ClienteNaoExistente(const string &nome){
    this->nome = nome;
}


string ClienteNaoExistente::getNome() const{
    return this->nome;
};
