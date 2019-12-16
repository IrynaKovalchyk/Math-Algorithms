#include "Exception.h"


Exceptoin::Exceptoin(const int &index) : index(index){

}

string Exceptoin::what() {
    string messages = "you try to get wrong value for index" + to_string(index) ;
    return messages;
}
