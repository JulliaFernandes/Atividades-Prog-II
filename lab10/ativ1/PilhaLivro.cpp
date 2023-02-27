#include "PilhaLivro.hpp"

using namespace std;

PilhaLivro :: PilhaLivro(){
    this -> setPrimeiro(NULL);
    this -> setUltimo(NULL);
    this -> setItens(0);

}
PilhaLivro :: PilhaLivro(string _nome, float _isbn){
    primeiro = new Livro (_nome, _isbn);
    ultimo = primeiro;
    this -> setItens(0);
}

void PilhaLivro :: setPrimeiro(Livro* primeiro){
    this -> primeiro = primeiro;
}
Livro* PilhaLivro :: getPrimeiro(){
    return this -> primeiro;
}

void PilhaLivro :: setUltimo(Livro* ultimo){
    this -> ultimo = ultimo;
}
Livro* PilhaLivro :: getUltimo(){
    return this -> ultimo;
}

void PilhaLivro :: setItens(int itens){
    this -> itens = itens;
}
int PilhaLivro :: getItens(){
    return this -> itens;
}

bool PilhaLivro :: vazia(){
    return(primeiro == NULL); //retorna True pq ta vazia
}

void PilhaLivro :: CadastrarLivro(Livro* novoL){

    if(vazia()){
        this -> setPrimeiro(novoL);
        this -> setUltimo(novoL);
        this -> setItens(1);
    }
    else{
        novoL -> setProximo(primeiro);
        this -> setPrimeiro(novoL); 
        this -> setItens(getItens()+1);    
    } 
}

void PilhaLivro:: Retirar(){
    Livro* l = this -> getPrimeiro();
    Livro *proximo;

    cout << "\t[DADOS DO LIVRO]" << endl;
    cout << ">Nome: " << l -> getNome() << endl;
    cout << ">ISBN: " << l -> getISBN() << endl;
    cout << ">Restam: " << this -> getItens() - 1 << " livros" << endl;

    proximo = l -> getProximo();
    this -> setPrimeiro(proximo);
    this -> setItens(this -> getItens() -1);
    delete l;

    //this -> setPrimeiro(l -> getProximo());
    //this -> setItens(this -> getItens() -1);
    //delete l;
}

void PilhaLivro :: ImprimirLivros(){
   Livro* l = getPrimeiro();
    
    while(l){
        cout << ">Nome: " << l -> getNome() << endl;
        cout << ">ISBN: " << l -> getISBN() << endl;
        cout << endl;
        l = l -> getProximo(); 
    }
    cout << "----------------------------------------------" << endl; 
}