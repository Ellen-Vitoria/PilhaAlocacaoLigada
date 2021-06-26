#ifndef PILHALIGADA_H_INCLUDED
#define PILHALIGADA_H_INCLUDED

template <typename Tipo>

struct Node{
    Tipo info;
    Node<Tipo> *prox; //Ponteiro para N�, do tipo Tipo
};

template <typename Tipo> //� preciso declarar template para quando for usado tanto em Struct quanto na Classe

class Pilha{
private:
    Node<Tipo> *topo; //Ponteiro para uma vari�vel do tipo Node

public:
    //Fun��o inicializadora; estado inicial
    Pilha(){
        topo = NULL;
    }

    bool empilhar(Tipo x){
        bool v = true;
        Node<Tipo> *aux = new Node<Tipo>; //1� Passo: Alocar espa�o de Mem�ria

        //No caso de n�o conseguir Alocar
        if(aux == NULL)
        {
            v = false;
        }
        else
        {
            aux->info = x; //2� Passo: Guardar informa��o; ->: Operador de refer�ncia
            aux->prox = topo; //3� Passo: o Prox de Auxiliar receber� conte�do do Topo, que no momento inicial � NULL
            topo = aux; //4� Passo: o Topo receber� o conte�do (a informa��o) de Auxiliar
        }
        return v;
    }

    Tipo desempilhar(){
        Tipo temp = topo->info; //Elemento do Topo para mostrar, depois, que elemento foi desempilhado

        Node<Tipo> *aux = topo; //1� Passo: Aux apontar� para onde o Topo est� apontando
        topo = topo->prox; //2� Passo: Topo passa a apontar para onde o Prox est� apontando, podendo ser um novo Elemento (empilhado anteriormente) ou o NULL
        delete aux; //3� Passo: Liberando espa�o, para n�o ficar perdido na Mem�ria

        return temp;
    }

    Tipo elementoTopo(){
        return topo->info;
    }

    bool pilhaVazia(){
        return topo == NULL;
    }

    //Retornar a refer�ncia do Topo
    Node<Tipo> *getTopo(){
        return topo;
    }
};

#endif // PILHALIGADA_H_INCLUDED
