#ifndef MENSAGEM_HPP
#define MENSAGEM_HPP
#include <iostream>

using namespace std;


class Mensagem {
    public:
        Mensagem();
        Mensagem(int, string);
        ~Mensagem();

    private:
        int prioridade;
        string mensagem;
        Mensagem* proximo;

    friend class Caixa; 
};


#endif