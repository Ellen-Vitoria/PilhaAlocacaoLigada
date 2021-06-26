#include <iostream>
#include <stdlib.h>
#include "pilhaLigada.h"

using namespace std;

int main()
{
    cout << "Pilha Ligada" << endl;
    Pilha<int> p;
    int x, opc;

    //Menu
    do{
        cout<< "\n1 - Empilhar" <<endl;
        cout<< "2 - Desempilhar" <<endl;
        cout<< "3 - Elemento do Topo" <<endl;
        cout<< "4 - Exibir a Pilha" <<endl;
        cout<< "5 - Fim" <<endl;

        cout<< "\nSelecione:" <<endl;
        cin >> opc;

        switch(opc){
            //Empilhar
            case 1:
                cout<< "\nDigite o Valor: ";
                cin >> x;

                if(!p.empilhar(x)){
                    cout<< "Pilha Cheia...." <<endl;
                }

                break;

            //Desempilhar
            case 2:
                if(p.pilhaVazia()){
                    cout<<"Pilha vazia...."<<endl;
                }
                else{
                    cout<<"\nDesempilha: "<<p.desempilhar()<<endl;
                }
                break;

            //Elemento do Topo
            case 3:
                if(p.pilhaVazia()){
                    cout<<"Pilha vazia...."<<endl;
                }
                else{
                    cout<<"\nElemento do topo: "<<p.elementoTopo()<<endl;
                }
                break;

            //Exibir a Pilha
            case 4:
                cout<< "\nElementos da Pilha: " <<endl;

                if(p.pilhaVazia()){
                    cout<< "Pilha Vazia...." <<endl;
                }
                else{
                    Node<int> *aux = p.getTopo();
                    while(aux != NULL){
                        cout<< aux->info << "   ";
                        aux = aux->prox;
                    }
                    cout <<endl;
                }
                break;

            //Fim
            case 5:
                cout<< "\nFim...." <<endl;
                return 0;
                break;

            default:
                continue;
                break;
        }
        cout<< "\n\n";
        system("pause");
        system("cls");
    }
    while (opc != 5);
}
