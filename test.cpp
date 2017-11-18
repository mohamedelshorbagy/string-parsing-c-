#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
using namespace std;



char * my_strtok(char * str, char *comp)
{
	static int pos;
	static char *s;
	int i =0, start = pos;

	// Copying the string for further calls of strtok
	if(str!=NULL)
		s = str;

	i = 0;
	int j = 0;
	//While not end of string
	while(s[pos] != '\0')
	{
		j = 0;
		//Comparing of one of the delimiter matches the character in the string
		while(comp[j] != '\0')
		{
			//Pos point to the next location in the string that we have to read
			if(s[pos] == comp[j])
			{
				//Replace the delimter by \0 to break the string
				s[pos] = '\0';
				pos = pos+1;
				//Checking for the case where there is no relevant string before the delimeter.
				//start specifies the location from where we have to start reading the next character
				if(s[start] != '\0')
					return (&s[start]);
				else
				{
					// Move to the next string after the delimiter
					start = pos;
					// Decrementing as it will be incremented at the end of the while loop
					pos--;
					break;
				}
			}
			j++;
		}
		pos++;
	}//End of Outer while
	s[pos] = '\0';
	if(s[start] == '\0')
		return NULL;
	else
		return &s[start];
}



int main() {

  string m = "[1.2 5.7 4.2 1.4; 6.3 2.5 8.1 3.1; 6.4 2.8 7.1 8.1; 3.2 5.1 7.2 6.2]";

  char * buffer = new char[m.length() + 1];
  strcpy(buffer, m.c_str());

  char * lineSeparators = ";";

  char * line = strtok(buffer,lineSeparators);
	
 while(line) {

    string s;
    for(int i = 0;i < strlen(line) + 1;i++) {
      if(line[i] == ' ' || i == strlen(line)) {
				if(s == "") {
        	s = "";
				} else {
					cout << s << endl;
        	s = "";
				}
				continue;
      } else if(line[i] == ']' || line[i] == '[') {
				continue;
			} else if(line[i] != ' ' || line[i] != NULL){
        s += line[i];
      }
    }

     line = strtok(NULL,lineSeparators);
  }



  return 0;
}
