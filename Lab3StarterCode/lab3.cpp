#include "Movie.h"
#include "Actor.h"
#include "Actor.cpp"
#include "Movie.cpp"

using namespace std;

void test();

int main()
{
	cout << "Start testing\n" << endl;
	test();
	cout << "\nFinished testing" << endl;
	return 0;
}

void test()
{
    Movie m(150, 2002, 4, 20.99, "Justin");
	m.actors = new Actor[m.getNumberOfActors()];
	m.addActor("Justin", "A", 1990);
	m.addActor("Justin", "B", 1991);
	m.printMovieInfo();
	Movie copiedMovie(m);
	copiedMovie.addActor("Justin", "C", 1992);
	copiedMovie.addActor("Justin", "D", 1993);
	copiedMovie.printMovieInfo();

}