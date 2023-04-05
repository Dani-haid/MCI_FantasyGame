#ifndef PROTOTYP4_EXCEPTIONS_H
#define PROTOTYP4_EXCEPTIONS_H

#include <exception>
using namespace std;


//Übergeordnete Exception Klasse um benutzerdefinierte Fehlermeldungen auszugeben
class GeneralException: public std::runtime_error{
public:
    using std::runtime_error::runtime_error;
};

//Fall falscher Index eingegeben wurde. Gibt Fehlermeldung und Index retour
class IndexException: public GeneralException{
protected:
    int index;
public:
    //using GeneralException::GeneralException;
    IndexException(const string& message, int index): GeneralException(message), index(index){};

    int getIndex() const {
        return index;
    }
};

class FullInventarException: public GeneralException{
public:
    using GeneralException::GeneralException;
};



#endif //PROTOTYP4_EXCEPTIONS_H
