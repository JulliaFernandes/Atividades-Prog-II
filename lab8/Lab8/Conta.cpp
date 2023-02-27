#include "Conta.hpp"

using namespace std;

Conta :: Conta(){

}
Conta :: Conta (string _nome, int _numeroDaConta){
    this -> nome = _nome;
    this -> numeroDaConta = _numeroDaConta;
    this -> setSaldo(0);
}

void Conta :: setNome(string _nome){
    this -> nome = _nome;
}
string Conta :: getNome(){
    return this ->  nome;
}

void Conta :: setNumeroDaConta(int _numeroDaConta){
    this -> numeroDaConta = _numeroDaConta;
}
int Conta :: getNumeroDaConta(){
    return this -> numeroDaConta;
}

void Conta :: setSaldo(double _saldo){
    this -> saldo = _saldo;
}
double Conta :: getSaldo(){
    return this -> saldo;
}

void Conta :: setTransacao(string _transacao){
    this -> transacao = _transacao;
}
string Conta :: getTransacao(){
    return this -> transacao;
}

void Conta :: deposito(double _valor){
    double valor;
    string data, descricao;
    string transacao = " ";
    int aux = 0, error;

    cin.ignore();
    cout << "\nDigite a data do deposito: " << endl;
    getline(cin, data);
    cout << "\nDescrição: " << endl;
    getline(cin, descricao);

    setSaldo(getSaldo() + _valor);

    string _valorString (to_string(_valor));

    transacao.append("Data: ");
    transacao.append(data);
    transacao.append(" | ");
    transacao.append("Deposito: +");
    transacao.append(_valorString);
    transacao.append(" | ");
    transacao.append("Descrição: ");
    transacao.append(descricao);
    transacao.append("\n");

    setTransacao(getTransacao() + transacao);

    //return valor;
}

/*void Conta :: retirada(double _retirada){
    string data, descricao;
    string transacao = " ";

    cin.ignore();
    cout << "\nDigite a data do saque: " << endl;
    getline(cin, data);
    /*cout << "\nDigite o valor da transacao: " << endl;
    cin >> valor;
    cout << "\nDescrição: " << endl;
    getline(cin, descricao);

    setSaldo(getSaldo() - _retirada);

    string _retiradaString (to_string(_retirada));

    transacao.append("Data: ");
    transacao.append(data);
    transacao.append(" | ");
    transacao.append("Saque: -");
    transacao.append(_retiradaString);
    transacao.append(" | ");
    transacao.append("Descrição: ");
    transacao.append(descricao);
    transacao.append("\n");

    setTransacao(getTransacao() + transacao);

}*/
