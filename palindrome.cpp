#include <iostream>
#include <cstring>
using namespace std;

/*
 * Author | Sophia You
 * Date | September 11, 2023
 * Description | This program reads in a user's input as a character array and
 * determines if it is a palindrome. It does not include spaces or punctuation
 * when determining palindrome-ness.
 * Sources | https://cplusplus.com/reference/cstring/strlen/
 */
int main() {
 
  int max = 80;
  char input[max + 1];

      cout << "Enter a phrase. Note: the program will only read in up to 80 characters. " << endl;

      // read in input until the user presses "enter" (end of the string)
      cin.getline(input, max);

      int rawLength = strlen(input); // length of the raw input
      //cout << input << endl;

      // this new array stores the manipulated input (without spaces)
      char forward[max + 1];

      int forwardCount = 0; // count is the index for forward
      for (int i = 0; i < rawLength; i++) // walk through the input string
	{
	  if (input[i] != '\0') // as long as we haven't reached the return
	    {
	      char cur = input[i]; // placeholder for current value
	      if (cur >= 'A' && cur <= 'Z')
	      {
		// change uppercase to lower case
		cur += 32;
	      }

	      // get rid of punctuation and spaces
	      if((cur >= 'a' && cur <= 'z') || (cur >= '0' && cur <= '9'))
	      {
		forward[forwardCount] = cur;
		forwardCount++; // move on to the next space in the "forward" string
	      }
	    }
	}
      
      forward[forwardCount] = '\0'; //add null character to the end

      //cout << endl;
      cout << "Forward: " << forward << endl; // print out the plain text

      // this new array stores the plain text input backwards
      int length = forwardCount; // length of the plain text (w/o spaces, punctuation)
      char backward[max + 1];
      int backwardCount = 0; // backwardCount is the index for backward

      // forward goes into backward in reverse
      for (int i = length - 1; i >= 0; i--)
	{
	  if (input[i] != '\0') // as long as we haven't reached the return
	  {
	    char cur = forward[i];
	    backward[backwardCount] = cur;
	    backwardCount++;
	  }
	}

      backward[backwardCount] = '\0';

      cout << "Backward: "<< backward << endl;

      // compare the forward and backward strings
      if (strcmp(forward, backward) == 0) // if the character are the same
      {
	cout << "It's a palindrome." << endl;
      }
      else // if characters are not the same
      {
	cout << "It is unfortunately not a palindrome." << endl;
      }
      
  return 0;
}
