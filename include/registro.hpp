#ifndef REGISTRO_HPP
#define REGISTRO_HPP
#include "user.hpp"

class Registro{
    public:
        Registro();
        ~Registro();
        void criaruser(int);
        void deletaruser(int);
        void enviarmensagem(int, int, string);
        void lermensagem(int);

    private:
        User* primeiro;
};

#endif