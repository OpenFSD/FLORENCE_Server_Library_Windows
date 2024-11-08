#include "pch.h"
#include "Server.h"
#include <cstddef>

namespace FLORENCE
{
    class Algorithms* ptr_Algorithms = NULL;
    class Data* ptr_Data = NULL;
    class Execute* ptr_Execute = NULL;
    class Global* ptr_Global = NULL;

    Server::Server()
    {
        this->ptr_Global = new Global();
        while (this->ptr_Global == NULL) { /* wait untill created */ }

        this->ptr_Algorithms = new Algorithms(ptr_Global->get_NumCores());
        while (this->ptr_Algorithms == NULL) { /* wait untill created */ }

        this->ptr_Data = new Data(ptr_Global->get_NumCores());
        while (this->ptr_Data == NULL) { /* wait untill created */ }
        this->ptr_Data->initialise_Control();

        this->ptr_Execute = new Execute(ptr_Global, ptr_Global->get_NumCores());
        while (this->ptr_Execute == NULL) { /* wait untill created */ }
        this->ptr_Execute->initialise_Control(ptr_Global->get_NumCores(), ptr_Global);
    }

    Server::~Server()
    {
        delete this->ptr_Global;
        delete this->ptr_Algorithms;
        delete this->ptr_Data;
        delete this->ptr_Execute;
    }

    class Algorithms* Server::get_Algorithms()
    {
        return this->ptr_Algorithms;
    }

    class Data* Server::get_Data()
    {
        return this->ptr_Data;
    }

    class Execute* Server::get_Execute()
    {
        return this->ptr_Execute;
    }

    class Global* Server::get_Global()
    {
        return this->ptr_Global;
    }
