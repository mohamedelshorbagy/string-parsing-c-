#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <sstream>
using namespace std;



void getString(string s) {
  
  cout << s << endl;
}



int main() {


  std::ifstream ifs("example.m");
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
  
  string matrix[100];
  string names[100];
  size_t countSqaures = std::count(content.begin(),content.end() , ']');
  bool shorbagy = false;
  for(int i = 0 ;i < countSqaures + 1;i++) {

    size_t found = content.find('[');
      if(found != std::string::npos) {
      matrix[i] = content.substr(0,content.find(']') + 1);
      names[i] = matrix[i].substr(0,content.find('='));
      names[i].erase(std::remove(names[i].begin(),names[i].end(),' '),names[i].end());


      content.erase(0,content.find('=',content.find(']')) - 2);
      
      } else {

        shorbagy = true;
        

      }




  }



  for(int i = 0 ;i < countSqaures;i++) {
    // matrix[i].erase(0,matrix[i].find('['));
    matrix[i].erase(std::remove(matrix[i].begin(), matrix[i].end(), '\n'), matrix[i].end());
  }


  for(int i = 0 ; i < countSqaures;i++) {
    implemetation(matrix[i]);
  }



  std::istringstream f(content);
  std::string operationLine;
  while(getline(f,operationLine)) {
    implemetation(operationLine);
    
  }





    return 0;
}