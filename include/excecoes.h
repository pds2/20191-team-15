#ifndef EXCECOES_H
#define EXCECOES_H
#include <stdexcept>


class ArestaInvalidaException : public std::exception {
public:
    virtual const char* what() const noexcept override;
};

class NumVerticesInvalidoException : public std::exception {
public:
    virtual const char* what() const noexcept override;
};

class VerticesInvalidosException : public std::exception {
public:
    virtual const char* what() const noexcept override;
};

class PesoInvalidoException : public std::exception {
public:
    virtual const char* what() const noexcept override;
};

class ArestaJaExistenteException : public std::exception {
public:
    virtual const char* what() const noexcept override;
};

#endif