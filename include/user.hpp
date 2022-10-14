#ifndef USER_HPP
#define USER_HPP
#include "caixa.hpp"

class User{
    public:
        User();
        ~User();
        string leremail();
        void receberemail(int, string);
        User(int);

    private:
        User* proximo;
        Caixa* caixadeentrada;
        int id;

    friend class Registro;
};


#endif