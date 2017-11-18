#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cstring>
using namespace std;





int main() {


  std::ifstream ifs("example.m");
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
  int a = 0,b = 0;
  string matrix[100];
  string names[100];
  string operation[100];
  int countMatrix = 0;
  int countOperations = 0;

  size_t countSqaures = std::count(content.begin(),content.end() , ']');

  for(int i = 0 ;i < countSqaures + 1;i++) {

    size_t found = content.find('[');
    // cout << found << endl;
    // cout << content << endl;
      if(found != std::string::npos) {
      matrix[i] = content.substr(0,content.find(']') + 1);
      names[i] = matrix[i].substr(0,content.find('='));
      names[i].erase(std::remove(names[i].begin(),names[i].end(),' '),names[i].end());


      content.erase(0,content.find('=',content.find(']')) - 2);
      
      } else {
        cout << "End Of Matrcies" << endl;
      }




  }


  cout << content;


  cout << "###############################################" << endl;
  cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

  for(int i = 0 ;i < countSqaures;i++) {
    matrix[i].erase(0,matrix[i].find('['));
    matrix[i].erase(std::remove(matrix[i].begin(), matrix[i].end(), '\n'), matrix[i].end());
  }


  for(int i = 0 ;i < countSqaures;i++) {
    cout << matrix[i] << endl;
  }
  


// cout << content << endl;
  // if(found == std::string::npos) {
  //   cout << "Not found" << endl;
  // } else {
  //   cout << "found" << " =>  " << found  << "  - String Length " << s.length() << endl;
  // }


// cout << matrix[0] << endl;

// cout << "Name of Matrix[0] " << names[0] << endl;


// cout << "Number of [ " << countSqaures << endl;




// int counter = 0;

// char * buffer = new char[content.length() + 1];
//   strcpy(buffer, content.c_str());

//   char * lineSeparators = ";";

//   char * line = strtok(buffer,lineSeparators);
	
//  while(line) {
//     if(counter == 0) {
//     string s;
//     for(int i = 0;i < strlen(line) + 1;i++) {
//       if(line[i] == ' ' || i == strlen(line)) {
// 				if(s == "") {
//         	s = "";
// 				} else {
// 					cout << atof(s.c_str())<< endl;
//         	s = "";
// 				}
// 				continue;
//       } else if(line[i] == ']' || line[i] == '[') {
// 				continue;
// 			} else if(line[i] != ' ' || line[i] != NULL){
//         s += line[i];
//       }
//     }

//     }
//     counter++;
//      line = strtok(NULL,lineSeparators);
//   }




    return 0;
}