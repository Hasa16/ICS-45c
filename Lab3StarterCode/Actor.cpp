#include "Actor.h"

using namespace std;

Actor::Actor(){
            this->firstName = "";
            this->lastName = "";
            this->birthYear = 0;
        }
        
        //Constructs an Actor object with the parameters passed in
Actor::Actor(string first, string last, int birth)
        {
            this->firstName = first;
            this->lastName = last;
            this->birthYear = birth;
        }
        
void Actor::setFirstName(string first)
        {
            this->firstName = first;
        }
        
string Actor::getFirstName()
        {
            return this->firstName;
        }
        
void Actor::setLastName(string last)
        {
            this->lastName =last;
        }
        
string Actor::getLastName()
        {
            return this->lastName;
        }
        
void Actor::setBirthYear(int birth)
        {
            this->birthYear = birth;
        }
        
int Actor::getBirthYear()
        {
            return this->birthYear;
        }