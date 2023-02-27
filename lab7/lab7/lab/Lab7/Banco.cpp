#include "Banco.hpp"
#include <iostream>

using namespace std;

int NumConta = 1000;

Banco :: Banco(){
    this -> lc = new ListaContaSemLimite();
    this -> lcc = new ListaContaCorrente();
    this -> lcp = new ListaContaPoupanca();

}
Banco :: Banco(ListaContaSemLimite* _lc, ListaContaCorrente* _lcc, ListaContaPoupanca* _lcp){
    this -> lc = new ListaContaSemLimite();
    this -> lcc = new ListaContaCorrente();
    this -> lcp = new ListaContaPoupanca();
}

void Banco :: setListaContaSemLimite(ListaContaSemLimite* _lc){
    this -> lc = _lc;
}
ListaContaSemLimite* Banco :: getListaContaSemLimite(){
    return this -> lc;
}

void Banco :: setListaContaCorrente(ListaContaCorrente* _lcc){
    this -> lcc = _lcc;
}
ListaContaCorrente* Banco :: getListaContaCorrente(){
    return this -> lcc;
}

void Banco :: setListaContaPoupanca(ListaContaPoupanca* _lcp){
    this -> lcp = _lcp;
}
ListaContaPoupanca* Banco :: getListaContaPoupanca(){
    return this -> lcp;
}

void Banco :: cadastroC(){
    string nome;
    //ContaSemLimite* c = getListaContaSemLimite()-> getPrimeiro();

    cin.ignore();
    cout << "\nDigite seu nome:" << endl;
    getline(cin, nome);


    cout << "\n\t!ATENCAO!" << endl;
    cout << "\nNUMERO DA SUA CONTA:" << NumConta << endl;
    cout << "\n--------------------------------------------------------------------------------"<< endl;

        ContaSemLimite* novaC = new ContaSemLimite(nome, NumConta);
        lc->inserirFinal(novaC);

    NumConta++;
}

void Banco :: cadastroCC(){
    string nome, saldo;
    double limite, limiteAux = 0;
    //ContaCorrente* cc = getPrimeiro();

        cin.ignore();
        cout << "\nDigite seu nome:" << endl;
        getline(cin, nome);
        cout << "\nDigite seu limite:" << endl;
        cin >> limite;
        limiteAux = limite;

        cout << "\n\t!ATENCAO!" << endl;
        cout << "\nNUMERO DA SUA CONTA:" << NumConta << endl;
        cout << "\n--------------------------------------------------------------------------------"<< endl;
        ContaCorrente* novaCC = new ContaCorrente(nome, NumConta, limite, limiteAux);

        NumConta++;

        lcc -> inserirFinal(novaCC);

}

void Banco :: cadastroCP(){
    string nome, aniversario;
    //ContaPoupanca* cp = getPrimeiro();

        cin.ignore();
        cout << "\nDigite seu nome:" << endl;
        getline(cin, nome);
        cout << "\nDigte seu aniversario no formato (XX/XX/XXXX):" << endl;
        getline(cin, aniversario);

        cout << "\n\t!ATENCAO!" << endl;
        cout << "\nNUMERO DA SUA CONTA:" << NumConta << endl;
        cout << "\n--------------------------------------------------------------------------------"<< endl;

        ContaPoupanca* novaCP = new ContaPoupanca();
        novaCP -> setNome(nome);
        novaCP -> setAniversario(aniversario);
        novaCP -> setNumeroDaConta(NumConta);
        NumConta++;
        
        lcp -> inserirFinal(novaCP);
}



void Banco :: depositoC(){
    int Nconta, aux = 0;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaSemLimite* c = getListaContaSemLimite() -> getPrimeiro();

    if(getListaContaSemLimite() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;

        while(c){
            if(c -> getNumeroDaConta() == Nconta){
                cout << "\nDigite o valor do deposito" << endl;
                cin >> valor;
                
                
                cin.ignore();
                cout << "\nDigite a data do deposito: " << endl;
                getline(cin, data);
                cout << "\nDescrição: " << endl;
                getline(cin, descricao);

                c -> setSaldo(c -> getSaldo() + valor);

                string _valorString (to_string(valor));

                transacao.append("Data: ");
                transacao.append(data);
                transacao.append(" | ");
                transacao.append("Deposito: +");
                transacao.append(_valorString);
                transacao.append(" | ");
                transacao.append("Descrição: ");
                transacao.append(descricao);
                transacao.append("\n");

                c -> setTransacao(c -> getTransacao() + transacao);
                //c -> deposito(valor);
                aux = 1;
                break;
            }
            c = c -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
    }
}

void Banco :: depositoCC(){
    int Nconta, aux = 0, cont = 0, auxSaldo = 0, auxSL = 0;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaCorrente* cc = lcc -> getPrimeiro();


    if(getListaContaCorrente() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;

        while(cc){
            if(cc -> getNumeroDaConta() == Nconta){
                cout << "\nDigite o valor do deposito" << endl;
                cin >> valor;
                cont = 1;

                if(valor > cc -> getLimiteAux()){
                    cout << "\nValor maximo do limite atingido, impossivel cadastrar" << endl;
                    auxSL = 1;
                }
                if(auxSL == 0){
                    if(cc -> getLimite() < cc -> getLimiteAux()){
                        if(valor>0){
                            cin.ignore();
                            cout << "\nDigite a data do deposito: " << endl;
                            getline(cin, data);
                            cout << "\nDescrição: " << endl;
                            getline(cin, descricao);

                            string _valorString (to_string(valor));

                            transacao.append("Data: ");
                            transacao.append(data);
                            transacao.append(" | ");
                            transacao.append("Deposito: +");
                            transacao.append(_valorString);
                            transacao.append(" | ");
                            transacao.append("Descrição: ");
                            transacao.append(descricao);
                            transacao.append("\n");

                            cc -> setTransacao(cc -> getTransacao() + transacao);
                            aux = 1;
                            /////////////////
                            cc -> setLimite(cc -> getLimite() + valor);
                            if(cc -> getLimite() < cc -> getLimiteAux()){
                                cout << "\nDeposito realizado no limite" << endl;

                            }
                            else if(cc -> getLimite() == cc -> getLimiteAux()){
                                cout << "\nDeposito realizado no limite" << endl;
                                cc -> setSaldo(0);   
                            }
                            else if( (cc -> getLimite() + valor) > cc -> getLimiteAux() ){
                                auxSaldo = (cc -> getLimite()) - cc -> getLimiteAux();
                                cc -> setSaldo(auxSaldo);
                                cc -> setLimite(cc -> getLimiteAux());  
                            }
                        }
                    }
                    else if(cc -> getSaldo() + valor == cc -> getLimiteAux()){
                        cin.ignore();
                        cout << "\nDigite a data do deposito: " << endl;
                        getline(cin, data);
                        cout << "\nDescrição: " << endl;
                        getline(cin, descricao);

                        cc -> setSaldo(cc -> getSaldo() + valor);

                        string _valorString (to_string(valor));

                        transacao.append("Data: ");
                        transacao.append(data);
                        transacao.append(" | ");
                        transacao.append("Deposito: +");
                        transacao.append(_valorString);
                        transacao.append(" | ");
                        transacao.append("Descrição: ");
                        transacao.append(descricao);
                        transacao.append("\n");

                        cc -> setTransacao(cc -> getTransacao() + transacao);
                        aux = 1;
                        /////////////////
                }
                else if((cc -> getSaldo() == 0) && (cc -> getLimite() == cc -> getLimiteAux())){
                        cin.ignore();
                        cout << "\nDigite a data do deposito: " << endl;
                        getline(cin, data);
                        cout << "\nDescrição: " << endl;
                        getline(cin, descricao);

                        cc -> setSaldo(cc -> getSaldo() + valor);

                        string _valorString (to_string(valor));

                        transacao.append("Data: ");
                        transacao.append(data);
                        transacao.append(" | ");
                        transacao.append("Deposito: +");
                        transacao.append(_valorString);
                        transacao.append(" | ");
                        transacao.append("Descrição: ");
                        transacao.append(descricao);
                        transacao.append("\n");

                        cc -> setTransacao(cc -> getTransacao() + transacao);
                        aux = 1;
                }
                }
            }
            cc = cc -> getProximo();
        }
        if(cont == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
        else if(aux == 0){
            cout << "\nO valor do deposito esta maior que o limite" << endl;
        }
    }
} 

/*void Banco :: depositoCC(){
    int Nconta, aux = 0, cont = 0;
    double valor;
    ContaCorrente* c = lcc -> getPrimeiro();


    if(getListaContaCorrente() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;

        while(c){
            if(c -> getNumeroDaConta() == Nconta){
                cout << "\nDigite o valor do deposito" << endl;
                cin >> valor;
                cont = 1;
                if(c -> getLimite() >= valor){
                    c -> deposito(valor);
                    aux = 1;
                    break;
                }
            }
            c = c -> getProximo();
        }
        if(cont == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
        else if(aux == 0){
            cout << "\nO valor do deposito esta maior que o limite" << endl;
        }

    }
} */

void Banco :: depositoCP(){
    int Nconta, aux = 0;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaPoupanca* cp = getListaContaPoupanca() -> getPrimeiro();

    if(getListaContaPoupanca() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;

        while(cp){
            if(cp -> getNumeroDaConta() == Nconta){
                cout << "\nDigite o valor do deposito" << endl;
                cin >> valor;



                cin.ignore();
                cout << "\nDigite a data do deposito: " << endl;
                getline(cin, data);
                cout << "\nDescrição: " << endl;
                getline(cin, descricao);

                cp -> setSaldo(cp -> getSaldo() + valor);

                string _valorString (to_string(valor));

                transacao.append("Data: ");
                transacao.append(data);
                transacao.append(" | ");
                transacao.append("Deposito: +");
                transacao.append(_valorString);
                transacao.append(" | ");
                transacao.append("Descrição: ");
                transacao.append(descricao);
                transacao.append("\n");

                cp -> setTransacao(cp -> getTransacao() + transacao);
                aux = 1;
                break;
            }
            cp = cp -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
    }
}



void Banco :: extratoC(){
    ContaSemLimite* c = lc -> getPrimeiro();
    int Nconta, aux = 0;

    if(getListaContaSemLimite() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }
    else{
        cout << "\nDigite o numero da sua conta: " << endl;
        cin >> Nconta;

        while(c){
            if(c -> getNumeroDaConta() == Nconta){
                cout << "\n\t[DADOS PESSOAIS]" << endl;
                cout << ">Nome: " << c -> getNome() << endl;
                cout << ">Numero da Conta: " << c -> getNumeroDaConta() << endl;
                cout << ">Saldo: " << c -> getSaldo() << endl;
                cout << ">Transacao: " << endl;
                cout << c -> getTransacao() << endl;
                aux = 1;
                break;
            }
            c = c -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
    }
}

void Banco :: extratoCC(){
    ContaCorrente* cc = lcc -> getPrimeiro();
    int Nconta, aux = 0;

    if(getListaContaCorrente() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }
    else{
        cout << "\nDigite o numero da sua conta: " << endl;
        cin >> Nconta;

        while(cc){
            if(cc -> getNumeroDaConta() == Nconta){
                cout << "\n\t[DADOS PESSOAIS]" << endl;
                cout << ">Nome: " << cc -> getNome() << endl;
                cout << ">Numero da Conta: " << cc -> getNumeroDaConta() << endl;
                cout << ">Saldo: " << cc -> getSaldo() << endl;
                cout << ">Limite: " << cc -> getLimite() << endl;
                cout << ">Transacao: " << endl;
                cout << cc -> getTransacao() << endl;
                aux = 1;
                break;
            }
            cc = cc -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
    }
}

void Banco :: extratoCP(){
    ContaPoupanca* cp = lcp -> getPrimeiro();
    int Nconta, aux = 0;

    if(getListaContaPoupanca() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }
    else{
        cout << "\nDigite o numero da sua conta: " << endl;
        cin >> Nconta;

        while(cp){
            if(cp -> getNumeroDaConta() == Nconta){
                cout << "\n\t[DADOS PESSOAIS]" << endl;
                cout << ">Nome: " << cp -> getNome() << endl;
                cout << ">Numero da Conta: " << cp -> getNumeroDaConta() << endl;
                cout << ">Saldo: " << cp -> getSaldo() << endl;
                cout << ">Aniversario: " << cp -> getAniversario() << endl;
                cout << ">Transacao: \n"<< endl;
                cout << cp -> getTransacao() << endl;
                aux = 1;
                break;
            }
            cp = cp -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
    }
}



void Banco :: retiradaC(){
    int Nconta, aux = 0, auxSaldo = 0;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaSemLimite* c = getListaContaSemLimite() -> getPrimeiro();

    if(getListaContaSemLimite() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;

        while(c){
            if(c -> getNumeroDaConta() == Nconta){
                aux = 1;
                cout << "\nDigite o valor do saque: " << endl;
                cin >> valor;
                if(valor <= c -> getSaldo()){
                    auxSaldo = 1;

                    cin.ignore();
                    cout << "\nDigite a data do saque: " << endl;
                    getline(cin, data);
                    cout << "\nDescrição: " << endl;
                    getline(cin, descricao);

                    c -> setSaldo(c -> getSaldo() - valor);

                    string valorString (to_string(valor));

                    transacao.append("Data: ");
                    transacao.append(data);
                    transacao.append(" | ");
                    transacao.append("Saque: -");
                    transacao.append(valorString);
                    transacao.append(" | ");
                    transacao.append("Descrição: ");
                    transacao.append(descricao);
                    transacao.append("\n");

                    c -> setTransacao(c -> getTransacao() + transacao);
                                    
                                    
                    //c -> retirada(valor);
                    break;
                }
            }
            c = c -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
        else if(auxSaldo == 0){
            cout << "\nValor maior que seu saldo atual" << endl;
        }
    }
}

void Banco :: retiradaCP(){
    int Nconta, aux = 0, auxSaldo = 0;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaPoupanca* cp = getListaContaPoupanca() -> getPrimeiro();

    if(getListaContaPoupanca() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;

        while(cp){
            if(cp -> getNumeroDaConta() == Nconta){
                aux = 1;
                cout << "\nDigite o valor do saque" << endl;
                cin >> valor;
                if(valor <= cp -> getSaldo()){
                    auxSaldo = 1;

                    cin.ignore();
                    cout << "\nDigite a data do saque: " << endl;
                    getline(cin, data);
                    cout << "\nDescrição: " << endl;
                    getline(cin, descricao);

                    cp -> setSaldo(cp -> getSaldo() - valor);

                    string valorString (to_string(valor));

                    transacao.append("Data: ");
                    transacao.append(data);
                    transacao.append(" | ");
                    transacao.append("Saque: -");
                    transacao.append(valorString);
                    transacao.append(" | ");
                    transacao.append("Descrição: ");
                    transacao.append(descricao);
                    transacao.append("\n");

                    cp -> setTransacao(cp -> getTransacao() + transacao);
                    //cp -> retirada(valor);
                    break;
                }
            }
            cp = cp -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
        else if(auxSaldo == 0){
            cout << "\nValor maior que seu saldo atual" << endl;
        }
    }
}

void Banco :: retiradaCC(){
    int Nconta, aux = 0, auxSaldo = 0, cont = 0;
    double valor;
    string data, descricao;
    string transacao = " ";
    ContaCorrente* cc = getListaContaCorrente() -> getPrimeiro();

    if(getListaContaCorrente() -> getItens() == 0){
        cout << "\nNão ha nenhum cadastro ate o momento" << endl;
    }

    else{
            cout << "\nDigite o numero da sua conta: " << endl;
            cin >> Nconta;

        while(cc){
            if(cc -> getNumeroDaConta() == Nconta){
                aux = 1;
                cout << "\nDigite o valor do saque: " << endl;
                cin >> valor;

                if(cc -> getSaldo() == 0){
                    if(cc -> getLimite() >= valor){
                        cin.ignore();
                        cout << "\nDigite a data do saque: " << endl;
                        getline(cin, data);
                        cout << "\nDescrição: " << endl;
                        getline(cin, descricao);

                        string valordaString (to_string(valor));

                        transacao.append("Data: ");
                        transacao.append(data);
                        transacao.append(" | ");
                        transacao.append("Saque: -");
                        transacao.append(valordaString);
                        transacao.append(" | ");
                        transacao.append("Descrição: ");
                        transacao.append(descricao);
                        transacao.append("\n");

                        cc -> setTransacao(cc -> getTransacao() + transacao);
                        cc -> setLimite(cc -> getLimite() - valor);
                        cout << "\nSaque realizado no limite" << endl;
                    }
                }

                if(cc -> getSaldo() > 0){
                    if((cc -> getSaldo() + cc -> getLimite()) > valor){
                        cin.ignore();
                        cout << "\nDigite a data do saque: " << endl;
                        getline(cin, data);
                        cout << "\nDescrição: " << endl;
                        getline(cin, descricao);

                        string valordaString (to_string(valor));

                        transacao.append("Data: ");
                        transacao.append(data);
                        transacao.append(" | ");
                        transacao.append("Saque: -");
                        transacao.append(valordaString);
                        transacao.append(" | ");
                        transacao.append("Descrição: ");
                        transacao.append(descricao);
                        transacao.append("\n");

                        cc -> setTransacao(cc -> getTransacao() + transacao);
                       
                        cc -> setSaldo(cc -> getSaldo() - valor);
                        cout << "\nSaque realizado" << endl;
                       
                        if(cc -> getSaldo() < 0){
                            cout << "\nSaldo ultrapassa seu limite, RETIRANDO DO SEU LIMITE"<< endl;
                           
                            cin.ignore();
                            cout << "\nDigite a data do saque: " << endl;
                            getline(cin, data);
                            cout << "\nDescrição: " << endl;
                            getline(cin, descricao);

                            string valordaString (to_string(valor));

                            transacao.append("Data: ");
                            transacao.append(data);
                            transacao.append(" | ");
                            transacao.append("Saque: -");
                            transacao.append(valordaString);
                            transacao.append(" | ");
                            transacao.append("Descrição: ");
                            transacao.append(descricao);
                            transacao.append("\n");

                            cc -> setTransacao(cc -> getTransacao() + transacao);
                           
                            while(cc -> getSaldo() < 0){
                                cc -> setSaldo(cc -> getSaldo()+1);
                                auxSaldo++;
                            }
                            cc -> setLimite(cc -> getLimite() - auxSaldo);
                        }
                    }
                }

                if(cc -> getLimite() == 0){
                    cout << "\nSem valor em sua conta" << endl;
                }

                if((cc -> getSaldo() - valor) < 0){
                    if((cc -> getLimite() - valor) < 0){
                        cout << "\nImpossivel realizar essa operação, pois ja utiliza o limite" << endl;
                    }
                    else{
                        cc -> setLimite(cc -> getLimite() - valor + cc -> getSaldo());
                        cc -> setSaldo(0);
                        cont = 1;
                    }
                }
                else{
                    cc -> setSaldo( cc -> getSaldo() - valor);
                    cont = 1;
                }
            }
            cc = cc -> getProximo();
        }
        if(aux == 0){
            cout << "\nNumero de conta nao cadastrado" << endl;
        }
        /*else if(auxSaldo == 0){
            cout << "\nValor maior que seu saldo atual" << endl;
        }*/
    }
}

