#ifndef Usuario_hpp
#define Usuario_hpp
#include <string>

class Usuario
{
private:
    std::string nome;
public:
    Usuario(std::string);
    std::string recuperaNome() const;
    std::string getPrimeiroNome() const;
    std::string getSobreNome() const;
};

#endif /* Usuario_hpp */
