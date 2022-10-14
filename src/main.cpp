#include "registro.hpp"
#include <string.h>

int main(){
    Registro interfaceMail;
    FILE* file = fopen("../input.txt", "rt");

    if(file == NULL){
        cout << "Arquivo não encontrado" << endl;
        return -1;
    }

    while(!feof(file)){
        char command[20];
        fscanf(file, "%s", command);

        if(strcmp(command, "CADASTRA") == 0){
            int idToCreate;
            fscanf(file, " %d", &idToCreate);
            interfaceMail.criaruser(idToCreate);
        }

        else if(strcmp(command, "REMOVE") == 0){
            int idToRemove;
            fscanf(file, " %d", &idToRemove);
            interfaceMail.deletaruser(idToRemove);
        }
       
            else if(strcmp(command, "ENTREGA") == 0){
                int idToSend;
                int priority;
               
                fscanf(file, " %d %d", &idToSend, &priority);
                char word[20] = "";

                string message = "";
                fscanf(file, " %s", word);
                while(strcmp(word, "FIM") != 0){
                    message += word;
                    fscanf(file, " %s", word);
                    
                    if(strcmp(word, "FIM") != 0)
                        message += " ";
                }

                interfaceMail.enviarmensagem(idToSend, priority, message);
            }

                else{
                    int idToGetEmail;
                    fscanf(file, " %d", &idToGetEmail);
                    interfaceMail.lermensagem(idToGetEmail);
                }
   
    }

}