#include <iostream>
#include <cstring>
#define tam 4
#define MES 12
using namespace std;

int qtdCadastrados=0, codAtual=1;

typedef struct vendedores{
    char nome[50];
    int codigo;
}vendedores_t;

typedef struct vendas{
    float mes[MES];
    int codigo;
}vendas_t;

void cadastro(vendedores_t *vendedores, vendas_t *cadastroVendas){
    int cod;

    if(qtdCadastrados == 4){
        cout<<"LIMITE DE VENDEDORES ATINGIDO. IMPOSSIVEL CADASTRAR MAIS VENDEDORES";
        return;
    }

    if(vendedores[qtdCadastrados].codigo == -1){
        cout<<"Digite o nome do vendedor:";
        cin>>vendedores[qtdCadastrados].nome;
            
        vendedores[qtdCadastrados].codigo = codAtual;

        cout<<endl;
        cout<<"SEUS DADOS:";   
        cout<<endl; 
        cout<<"SR.(A)"<<vendedores[qtdCadastrados].nome<< endl << "SEU CÓDIGO É:"<<vendedores[qtdCadastrados].codigo;
        cout<<endl;

        for(int i=0; i<MES; i++){
            cadastroVendas[qtdCadastrados].codigo = vendedores[qtdCadastrados].codigo;
            cadastroVendas[qtdCadastrados].mes[i]= -1;
        }
        qtdCadastrados++;
        codAtual++;
    }
}

void CadVendas(vendedores_t *vendedores, vendas_t *cadastroVendas){
    int mesVendedor;
    int cod;
    int variavel=0;

    cout<<"Digite o codigo do vendedor:\n";
    cin>>cod;

    for(int i=0; i<qtdCadastrados; i++){
        if(cod == cadastroVendas[i].codigo){
            variavel=1;
            cout<<vendedores[i].nome <<" digite o mes da sua venda:";
            cout<<"\n 1-Janeiro\n 2-Fevereiro\n 3-Março\n 4-Abril\n 5-Maio\n 6-Junho\n";
            cout<<" 7-Julho\n 8-Agosto\n 9-Setembro\n 10-Outubro\n 11-Novembro\n 12-Dezembro\n";
            cin>>mesVendedor;

            for(int j=0; j<MES; j++){
                if(mesVendedor == j+1){
                    if(cadastroVendas[i].mes[j] != -1){
                        cout<<"\nJa possui vendas nesse mes\n";
                        break;
                    }
                    else{
                        cout<<"Digite o valor da compra\n";
                        cin>>cadastroVendas[i].mes[j];
                        break;
                    }
                }
            }
        }
    }
    if(variavel==0){
        cout<<"Nao possui vendedor com esse codigo. Tente novamente";
    }
}

void consultaVenda(vendedores_t *vendedores, vendas_t *cadastroVendas){
    int cod;
    int mes;
    int variavel=0;

    cout<<"Digite o codigo do vendedor:\n";
    cin>>cod;
    for(int i=0; i<qtdCadastrados; i++){
        if(cod == cadastroVendas[i].codigo){
            variavel=1;
            cout<<"Digite o mes que deseja consultar:";
            cout<<"\n 1-Janeiro\n 2-Fevereiro\n 3-Março\n 4-Abril\n 5-Maio\n 6-Junho\n";
            cout<<" 7-Julho\n 8-Agosto\n 9-Setembro\n 10-Outubro\n 11-Novembro\n 12-Dezembro\n";    
            cin>>mes;
            
            for(int j=0; j<MES; j++){
                if(mes == j+1){
                    if(cadastroVendas[i].mes[j] != -1){
                        cout<<"Voce possui uma venda no valor de " <<cadastroVendas[i].mes[j]<< " cadastrada";
                    }
                    else{
                        cout<<"\nNao possui vendas cadastradas nesse mes\n";
                    }
                }
            }
        }
    }
    if(variavel==0){
        cout<<"Nao possui vendedor com esse codigo. Tente novamente";
    }
}

void totalVendas(vendedores_t *vendedores, vendas_t *cadastroVendas){
    int cod;
    float soma=0;
    int variavel=0;

    cout<<"Digite o codigo do vendedor:\n";
    cin>>cod;
    for(int i=0; i<qtdCadastrados; i++){
        if(cod == cadastroVendas[i].codigo){
            variavel=1;
            for(int j=0; j<MES; j++){
                if(cadastroVendas[i].mes[j] != -1){
                    soma+=cadastroVendas[i].mes[j];
                }
            }  
            cout<<"\nVoce fez um total de "<<soma<<" vendas";
        }
    }
    if(variavel==0){
        cout<<"Nao possui vendedor com esse codigo. Tente novamente";
    }
}

void melhorVend(vendedores_t *vendedores, vendas_t *cadastroVendas){
    int mes;
    int aux=0;
    int cod;

    cout<<"Digite o mes que deseja consultar:";
            cout<<"\n 1-Janeiro\n 2-Fevereiro\n 3-Março\n 4-Abril\n 5-Maio\n 6-Junho\n";
            cout<<" 7-Julho\n 8-Agosto\n 9-Setembro\n 10-Outubro\n 11-Novembro\n 12-Dezembro\n";    
            cin>>mes;
            for(int i=0; i<MES; i++){
                if(mes == i+1){
                    for(int j=0; j<qtdCadastrados; j++){
                        if(cadastroVendas[j].mes[i]>aux){
                            aux=cadastroVendas[j].mes[i];
                            cod=cadastroVendas[j].codigo;
                        }
                    }
                }
            }
        cout<<"O vendor de maior venda nesse mes é o de codigo: "<<cod<< ", que vendeu: "<<aux;
}

void maiorVenda(vendedores_t *vendedores, vendas_t *cadastroVendas){
    float aux[MES];
    float ganha=0;
    int mes;


    for(int i=0; i<MES; i++){
        aux[i]=0;
    }

    for(int i=0; i<MES; i++){
        for(int j=0; j<qtdCadastrados; j++){
            aux[i]+=cadastroVendas[j].mes[i];
            if(aux[i]>ganha){
                ganha=aux[i];
                mes=i+1;
            }
        }
    }
    cout<<"O mes que obteve mais vendas é o: "<<mes<<". Com um total de:"<<ganha<<" vendas";
}


int main()
{
    vendedores_t vendedores[tam];
    vendas_t cadastroVendas[tam];
    int op=-1;
    
    for (int i=0; i<tam; i++){
        vendedores[i].codigo =-1;
    }

    while(op!= 7){
    
        cout<<"\nMENU\n";
        cout<<"1-Cadastrar vendedor\n";
        cout<<"2-Cadastrar venda\n";
        cout<<"3-Consultar venda\n";
        cout<<"4-Consultar o total de vendas de um determinado vendedor\n";
        cout<<"5-Mostrar o numero do vendedor que mais vendeu em um determinado mes\n";
        cout<<"6-Mostrar o numero de mes com mais vendas\n";
        cout<<"7-Sair\n";
        
        cout<<"Digite qual opçao deseja\n";
        cin>>op;
        
        switch (op){
            case  1:
            cadastro(vendedores, cadastroVendas);
            break;
            case 2:
            CadVendas(vendedores, cadastroVendas);
            break;
            case 3:
            consultaVenda(vendedores, cadastroVendas);
            break;
            case 4:
            totalVendas(vendedores, cadastroVendas);
            break;
            case 5:
            melhorVend(vendedores, cadastroVendas);
            break;
            case 6:
            maiorVenda(vendedores, cadastroVendas);
            break;
            case 7:
            cout<<"Saindo do programa obrigada ;)";
            break;
        }
    }

    return 0;
}
