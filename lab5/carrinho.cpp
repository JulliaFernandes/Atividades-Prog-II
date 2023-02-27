#include "carrinho.hpp"

Carrinho :: Carrinho(){
    primeiro = NULL;
    ultimo = NULL;
    this -> cont = 0;
    this -> totalizador =0;
}

Carrinho :: Carrinho(int id, int qtd, string nome, float preco){
    primeiro = new Produto(id, qtd, nome, preco);
    ultimo = primeiro;
    this -> cont = 0;
}

Carrinho :: ~Carrinho(){
    delete primeiro;
}

bool Carrinho :: vazio(){
    return (primeiro == NULL);
}

void Carrinho :: adicionar(){
    int id , qtd;
    string nome;
    float preco;

    cout << "Digite o nome do produto:" << endl;
    cin >> nome;
    cout << "Digite a quantidade de produtos:" << endl;
    cin >> qtd;
    cout << "Digite o valor unitario do produto:" << endl;
    cin >> preco;

    //Produto P(id, qtd, nome, preco);
    Produto* novo_produto = new Produto(id, qtd, nome, preco);

    if(vazio()){
        primeiro = novo_produto;
        ultimo = novo_produto;
        this -> cont++;
        this -> totalizador += (preco*qtd);
    }
    else{
        ultimo -> setProx(novo_produto);
        ultimo = novo_produto;
        this -> cont++;
        this -> totalizador += (preco*qtd);
    }
}

void Carrinho :: mostrar(){

    Produto* P = primeiro;

    if(vazio()){
        cout << "Seu carrinho esta vazio" << endl;
    }
    else{
        while(P){
            cout << "-Produto: " << P -> getNome() << endl;
            cout << "-ID do produto: " << P -> getId() << endl;
            cout << "-Preço do produto: " << P -> getpreco() << endl;
            cout << "-Quantidade de produtos: " << P -> getQtd() << endl;

            P = P -> obterProximo();
            cout<< endl;
        }
        cout << "Quantidade de produtos: " << cont << endl;
        cout << "Valor total do carrinho: " << totalizador << endl;

    }
}

void Carrinho::unicoC(){
    Produto* P1 = primeiro;

    if(vazio()){
        cout << "Seu carrinho esta vazio" << endl;
    }
    else{
        while(P1){
            P1->unico();
            P1 = P1 -> obterProximo();
            cout<< endl;
        }
    }
}

void Carrinho :: consultar(){
    Produto* P = primeiro;
    int auxId = 0;
    int auxCont= cont;

    //mostrar();

    cout << "Digite o ID que deseja consultar: " << endl;
    cin >> auxId;

    if(vazio()){
        cout << "Seu carrinho esta vazio";
    }
    else{
        while(P){
            if(auxId == P -> getId()){
            cout << "-Produto: " << P -> getNome() << endl;
            cout << "-ID do produto: " << P -> getId() << endl;
            cout << "-Preço do produto: " << P -> getpreco() << endl;
            cout << "-Quantidade de produtos: " << P -> getQtd() << endl;
            }
            P = P -> obterProximo();
            cout << endl;
        }
    }
}

void Carrinho ::remover(){
    Produto* P = primeiro;

    int auxId = 0, auxquantidade;
    float auxtotal;

    cout << "Digite o ID que deseja remover: " << endl;
    cin >> auxId;

    if(vazio()){
        cout << "Seu carrinho esta vazio" << endl;
    }
    else{
        if(primeiro->obterProximo() == NULL && primeiro->getId() == auxId){
            auxtotal = primeiro -> getpreco();
            auxquantidade = primeiro -> getQtd();
            auxtotal = (auxtotal*auxquantidade);
            totalizador -= auxtotal;

            primeiro = NULL;
        }
        else if((primeiro -> obterProximo() -> obterProximo() == NULL) && (primeiro -> getId() == auxId)){ //tirou a cabeça
            auxtotal = primeiro -> getpreco();
            auxquantidade = primeiro -> getQtd();
            auxtotal = (auxtotal*auxquantidade);
            totalizador -= auxtotal;

            primeiro =  primeiro -> obterProximo();
        }
        else if((primeiro -> obterProximo() -> obterProximo() == NULL) && (primeiro -> obterProximo() -> getId() == auxId)){ // tirou a cauda
            primeiro -> setProx(NULL);

            auxtotal = ultimo -> getpreco();
            auxquantidade = ultimo -> getQtd();
            auxtotal = (auxtotal*auxquantidade);
            totalizador -= auxtotal;

            ultimo = primeiro;
        }
        else{
            Produto* anterior = primeiro; // inicializa o nó anterior com o primeiro item da lista 
            Produto* atual = primeiro -> obterProximo(); // o nó atual com o proximo nó 
            Produto* proximo = primeiro -> obterProximo() -> obterProximo();
            Produto* auxiliar;

            while(proximo){
                if(primeiro -> getId() == auxId){
                    auxtotal = primeiro -> getpreco();
                    auxquantidade = primeiro -> getQtd();
                    auxtotal = (auxtotal*auxquantidade);
                    totalizador -= auxtotal;

                    primeiro = atual;
                }
                else if(atual -> getId() == auxId){
                    anterior -> setProx(proximo);

                    auxtotal = atual -> getpreco();
                    auxquantidade = atual -> getQtd();
                    auxtotal = (auxtotal*auxquantidade);
                    totalizador -= auxtotal;

                    free(atual);
                }
                anterior = atual;
                atual = proximo;
                proximo = proximo -> obterProximo();
            }
            if((atual == ultimo) &&(atual -> getId() == auxId)){
                auxtotal = atual -> getpreco();
                auxquantidade = atual -> getQtd();
                auxtotal = (auxtotal*auxquantidade);
                totalizador -= auxtotal;

                anterior ->  setProx(NULL);
                ultimo = anterior;
                delete atual;
            }
        }
        cont--;
    }
}

void Carrinho :: modificar(){
    Produto* P = primeiro;
    
    int auxId = 0;
    int auxQtd;
    float auxValor, auxTotal, auxTotal2, soma = 0;
    string auxNome;

    

    cout << "Digite o ID que deseja modificar: " << endl;
    cin >> auxId;

    if(vazio()){
        cout << "Seu carrinho esta vazio" << endl;
    }
    else{
        while(P){
            if(auxId == P->getId()){

                auxValor = P -> getpreco();
                auxQtd = P -> getQtd();
                auxTotal = (auxValor*auxQtd);

                cout << "Digite o nome do produto:" << endl;
                cin >> auxNome;
                cout << "Digite a quantidade do produto:" << endl;
                cin >> auxQtd;
                cout << "Digite o valor do produto:" << endl;
                cin >> auxValor;

                P -> setNome(auxNome);
                P -> setQtd(auxQtd);
                P -> setPreco(auxValor);

                auxTotal2 = (auxValor*auxQtd);
                soma = auxTotal2 - auxTotal;
                totalizador += soma;

                break;
            }
            P = P -> obterProximo();
            cout << endl;
        }   
    }
}