#include <iostream>
#include <vector>
using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

template <class N> class NoRepetido;


template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
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

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);

template<class N, class A>
Grafo<N, A>::Grafo() {
}

template<class N, class A>
Grafo<N, A>::~Grafo() {
    delete &nos;
}

template<class N, class A>
int Grafo<N, A>::numNos(void) const
    {return nos.size();}

template<class N, class A>
int Grafo<N, A>::numArestas(void) const
{
    int total;
    No<N,A> *noPtr;
    for(int i = 0; i < nos.size(); i++)
    {
        noPtr = nos.at(i);
        total += noPtr->arestas.size();
    }
    return total;
}

template<class N, class A>
Grafo<N,A> &Grafo<N, A>::inserirNo(const N &dados) {

    for(int i = 0; i < nos.size(); i++)
    {
        if(nos.at(i)->info == dados)
        {
            throw NoRepetido<N>(dados);
        }
    }
    No<N, A> *no = new No<N, A>(dados);
    nos.push_back(no);
    return *this;
}

template<class N, class A>
Grafo<N, A> &Grafo<N, A>::inserirAresta(const N &inicio, const N &fim, const A &val)
{
    cout << "Hi: " << endl;
    cout << nos.at(0)->arestas.at(1).valor << endl;
    for(int i = 0; i < nos.size(); i++)
    {
        for(int j = 0; j < nos.at(i)->arestas.size(); j++)
        {
            if((nos.at(i)->arestas.at(j).valor == val) || (nos.at(i)->arestas.at(j).destino == fim))
            {
                //throw aresta repetida exception
            }
        }
    }
    return *this;
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
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
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


