#include "Movie.h"
#include "Actor.h"

using namespace std;

Movie::Movie(){
    this->movieTime=0;
    this->movieYearOut=0;
    this->numberOfActors=0;
    this->actorArrayIndex=0;
    this->moviePrice=0.0;
    this->movieTitle="";
}

Movie::Movie(int Time, int YearOut, int NumActors, double Price, string Title){
    this->movieTime=Time;
    this->movieYearOut=YearOut;
    this->numberOfActors=NumActors;
    this->actors = new Actor[NumActors];
    this->actorArrayIndex=0;
    this->moviePrice=Price;
    this->movieTitle=Title;
}

Movie::Movie(const Movie &m){
    this->movieTime = m.movieTime;
    this->movieYearOut = m.movieYearOut;
    this->numberOfActors = m.numberOfActors;
    this->actorArrayIndex = m.actorArrayIndex;
    this->actors = new Actor[numberOfActors];
    copy(m.actors, m.actors + this->numberOfActors, this->actors);
    this->moviePrice = m.moviePrice;
    this->movieTitle = m.movieTitle;
}


Movie::~Movie(){
    delete [] this->actors;
}

void Movie::setMovieTime(int Time){
    this->movieTime=Time;
}

int Movie::getMovieTime(){
    return this->movieTime;
}
void Movie::setMovieYearOut(int YearOut){
    this->movieYearOut=YearOut;
}
int Movie::getMovieYearOut(){
    return this->movieYearOut;
}
void Movie::setNumberOfActors(int NumOfActors){
    this->numberOfActors=NumOfActors;
    this->actors = new Actor[NumOfActors];
}
int Movie::getNumberOfActors(){
    return this->numberOfActors;
}
void Movie::addActor(std::string firstName, std::string lastName, int birthYear){
    this->actors[this->actorArrayIndex] = Actor(firstName, lastName, birthYear);
    this->actorArrayIndex = this->actorArrayIndex + 1;
}
void Movie::setMoviePrice(double Price){
    this->moviePrice=Price;
}
double Movie::getMoviePrice(){
    return this->moviePrice;
}
void Movie::setMovieTitle(std::string Title){
    this->movieTitle=Title;
}
std::string Movie::getMovieTitle(){
    return this->movieTitle;
}
void Movie::printMovieInfo(){
    cout << "Title: " << this->movieTitle << ", Published in: " << this->movieYearOut << endl;
    cout << "Duration of Movie: " << this->movieTime << " minutes"  << endl;
    cout << "Price: $" << this->moviePrice  << endl;
    cout << "Actors:" << endl;
    for(int i = 0 ; i < this->numberOfActors ; i++){
        cout << this->actors[i].getFirstName() << " " << this->actors[i].getLastName() << ", " << this->actors[i].getBirthYear() << endl;
        }
                
}