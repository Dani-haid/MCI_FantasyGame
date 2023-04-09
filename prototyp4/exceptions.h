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

//Fall Inventar voll ist. Gibt Fehlermeldung retour
class FullInventarException: public GeneralException{
public:
    using GeneralException::GeneralException;
};

class FullInventarExceptionHero: public GeneralException{
public:
    using GeneralException::GeneralException;
};

//Fall in übergebenem Index kein Item vorhanden ist. Gibt Fehlermeldung und Index retour
//evtl. hier auch noch Vererbung von IndexException einbauen
class EmptySlotException: public GeneralException{
protected:
    int index;

public:
    EmptySlotException(const string& message, int index): GeneralException(message), index(index){};

    int getIndex() const {
        return index;
    }
};

//Wenn ein ungültiger Wert übergeben wird
class WrongValueException: public GeneralException{
public:
    using GeneralException::GeneralException;
};

//Fall bei der Suche nach einem gültigen Gegenstand im Inventar nichts gefunden wird
class NoItemFoundException: public GeneralException{
public:
    using GeneralException::GeneralException;
};



#endif //PROTOTYP4_EXCEPTIONS_H
