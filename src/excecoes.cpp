#include "excecoes.h"

const char* ArestaInvalidaException::what() const noexcept{
    return "Aresta Invalida!";
}


const char* NumVerticesInvalidoException::what() const noexcept{
    return "Numero de vertices Invalido!";
}

const char* VerticesInvalidosException::what() const noexcept{
    return "Vertices Invalidos!";
}

const char* PesoInvalidoException::what() const noexcept{
    return "Peso Invalido!";
}

const char* ArestaJaExistenteException::what() const noexcept{
    return "Aresta ja existente!";
}