#include "Dictionary.h"
#include <iostream>
using namespace std;

void findMatches(const Dictionary& dict, const Grid& grid)
{
  //read in grid and make into matrix format
  //know the matrix bounds
  string wordMaybe;
  int imax, jmax; //bounds of matrix
  
  if (imax < 5 && jmax < 5)
  {
    return 0; //idk if i can do this
  }

  //big four loops, iterate through matrix finding all possible starting letters.
  for (i = 0; i < imax; i++) //row iteration (imax is a matrix bound)
  {
      for (j = 0; j < jmax; j++) //column iteration (jmax is matrix bound)
      {
        //check all possible words going down

        //check all possible words going diagonally

        //check all possible words going across
      }
  }
  
  
}

int main ()
{
  return 0;
}
