#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InfoCartao {
public:
	string nome;
	bool presente;
};

class ParqueEstacionamento {
	unsigned int vagas;
	unsigned int lotacao;
	vector<InfoCartao> clientes;
	unsigned int numMaximoClientes;
public:
	ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli);
	bool adicionaCliente(const string & nome);
	bool retiraCliente(const string & nome);
	bool entrar(const string & nome);
	bool sair(const string & nome);
	int posicaoCliente(const string & nome) const;
	unsigned int getNumLugares() const;
	unsigned int getNumMaximoClientes() const;
	int getNumLugaresOcupados() const;
    unsigned int getNumClientesAtuais() const;
    const ParqueEstacionamento & operator += (const ParqueEstacionamento & p2);
};
