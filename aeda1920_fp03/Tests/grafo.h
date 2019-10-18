#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 *
 * No guarda arestas que saem dele. Aresta guarda no para onde vai
 */

template <class N, class A> class Aresta;
template<class N> class ArestaRepetida;

template<class N> class NoRepetido;
template<class N> class NoInexistente;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
    bool operator==(No<N, A> &no);
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	bool operator==(Aresta<N, A>&);
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo(); 
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const; 
};

template<class N, class A>
Grafo<N, A>::Grafo(){}

template<class N, class A>
Grafo<N, A>::~Grafo()
{
    for(int i = 0; i < nos.size(); i++){delete nos[i];}
}

template<class N, class A>
int Grafo<N, A>::numNos(void) const {return nos.size();}

template<class N, class A>
int Grafo<N, A>::numArestas() const
{
    int total = 0;
    for(No<N, A> *no : nos)
    {
        total += no->arestas.size();
    }
    return total;
}

template<class N, class A>
Grafo<N, A>& Grafo<N, A>::inserirNo(const N &dados)
{
    for(No<N, A> *no : nos)
    {
        if(no->info == dados) throw NoRepetido<N>(dados);
    }
    No<N, A> *no;
    no =  new No<N, A>(dados);
    nos.push_back(no);
    return *this;
}

template<class N, class A>
Grafo<N, A>& Grafo<N, A>::inserirAresta(const N &inicio, const N &fim, const A &val)
{
    bool noEncontrado = false;
    No<N, A> *noInicio;
    No<N, A> *noFim;

    for(No<N, A> *no: nos) {//check if No inicio exists
        if (no->info == inicio) {
            noEncontrado = true;
            noInicio = no;
        }
    }
    if(!noEncontrado) throw NoInexistente<N>(inicio);

    noEncontrado = false;
    for(No<N, A> *no: nos) {//check if No fim exists
        if (no->info == fim) {
            noEncontrado = true;
            noFim = no;
        }
    }
    if(!noEncontrado) {
        throw NoInexistente<N>(fim);
    }

    Aresta<N, A> arestaDada(noFim, val);

    for(Aresta<N, A> aresta : noInicio->arestas)
    {
        if((aresta.valor == val) && (aresta.destino->info == fim))
            throw ArestaRepetida<N>();
    }

    noInicio->arestas.push_back(arestaDada);
    return *this;
}

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);

template<class N, class A>
bool No<N, A>::operator==(No<N, A> &no)
{
    return (this->info == no.info);
}

template<class N>
class ArestaRepetida{
    public:
        ArestaRepetida(){};
        //ostringstream &operator<<(ostringstream &out);
    };

template<class N>
ostringstream &operator<<(ostringstream &out, const ArestaRepetida<N> arestaRepetida)
{
    out << "test" << endl;
    return out;
}
// excecao NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};

template <class N> 
ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }


// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }


