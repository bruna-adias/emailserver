#ifndef CAIXA_HPP
#define CAIXA_HPP
#include "mensagem.h"

class Caixa {
    public:
        Caixa ();
        ~Caixa();
        string leitura();
        void receber(int, string);

    private:
        Mensagem* primeiro;
    
};


#endif