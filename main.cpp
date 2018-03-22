#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Ldde;

template <typename T>
class No{
    private:
        T valor;
        No* prox;
        No* ante;
    public:
        T getValor() const {
            return valor;
        }

        No(T valor) : valor(valor), prox(NULL), ante(NULL) {}

    friend class Ldde<T>;
};

template <typename T>
class Ldde{
private:
    No<T>* primeiro;
    No<T>* ultimo;
    int n;
public:
    Ldde() : primeiro(NULL), ultimo(NULL), n(0) {}

    bool insereNo(T valor){
        No<T>* novo = new No<T>(valor);
        No<T>* a = NULL;
        No<T>* b = primeiro;

        if(!novo)
            return false;

        while (b && b->getValor() < valor){
            a = b;
            b = b->prox;
        }
        if(a)
            a->prox = novo;
        else//lista vazia
            primeiro = novo;
        if(b)
            b->ante = novo;
        else//final da lista, todos os numero < que valor
            ultimo = novo;

        novo->ante = a;
        novo->prox = b;

        n++;
        return true;
    }
    No<T>* buscaNo(T valor){
        No<T>* atual = primeiro;
        while (atual && atual->getValor()<valor){
            atual = atual->prox;
        }
        if(atual->getValor() == valor)
            return atual;
        return NULL;
    }
    bool removeNo(T valor){
        No<T>* bu = buscaNo(valor);
        if(!bu)
            return false;
        No<T>* ant = bu->ante;
        No<T>* dep = bu->prox;
        if(ant)
            ant->prox = dep;
        else
            primeiro = dep;
        if(dep)
            dep->ante = ant;
        else
            ultimo = ant;

        delete bu;
        n--;
    }
    void imprimeNo(){
        No<T>* atual = primeiro;
        while (atual){
            cout<<atual->getValor()<<endl;
            atual = atual->prox;
        }
    }
};


class Pessoa{
    private:
        string nome;
        int cpf;
        float peso;
    public:
        const string &getNome() const {
            return nome;
        }

        int getCpf() const {
            return cpf;
        }

        float getPeso() const {
            return peso;
        }

        Pessoa(const string &nome, int cpf, float peso) : nome(nome), cpf(cpf), peso(peso) {}

        bool operator<(const Pessoa& p){
            return nome < p.getNome();
        }

        bool operator==(const Pessoa& p){
            return nome == p.getNome();
        }
        /*
        bool operator<(const Pessoa& p){
            return cpf < p.getCpf();
        }

        bool operator==(const Pessoa& p){
            return cpf == p.getCpf();
        }

        bool operator<(const Pessoa& p){
            return peso < p.getPeso();
        }

        bool operator==(const Pessoa& p){
            return peso == p.getPeso();
        }
         */

};/*
class Compromisso{
private:
    string nome;
    string tipo;
    int dia;
public:
    const string &getNome() const {
        return nome;
    }

    const string &getTipo() const {
        return tipo;
    }

    int getDia() const {
        return dia;
    }

    Compromisso(const string &nome, const string &tipo, int dia) : nome(nome), tipo(tipo), dia(dia) {}

    bool operator<(Compromisso& c){
        return nome < c.getNome();
    }
    bool operator==(Compromisso& c){
        return nome == c.getNome();
    }

};*/
ostream& operator<<(ostream& o, const Pessoa& p){
    o<<"Nome: "<<p.getNome()<<" Cpf: "<<p.getCpf()<<" Peso: "<<p.getPeso();
    return o;
}

int main() {

    Ldde<float> l;
    cout<<endl<<"------INSERÇÃO--------"<<endl;
    l.insereNo(5.3);
    l.insereNo(0.3);
    l.insereNo(12.9);
    l.insereNo(17.123);
    l.insereNo(4.12);
    l.imprimeNo();
    cout<<endl<<"------REMOÇAO--------"<<endl;
    l.removeNo(12.9);
    l.imprimeNo();


    Ldde<Pessoa> lp;
    cout<<endl<<"------INSERÇÃO--------"<<endl;
    lp.insereNo(Pessoa("Joao",122133,69.5));
    lp.insereNo(Pessoa("Maria",34133,70.234));
    lp.insereNo(Pessoa("Jonas",112433,12.5));
    lp.insereNo(Pessoa("Antonio",12673,122.31));
    lp.imprimeNo();
    cout<<endl<<"------REMOÇAO--------"<<endl;
    lp.removeNo(Pessoa("Jonas",0,0));
    lp.imprimeNo();
/*
    Ldde<Compromisso>lc;
    cout<<endl<<"------INSERÇÃO--------"<<endl;
    lc.insereNo(Compromisso("show","diversao",13));
    lc.imprimeNo();
    */
    return 0;
}