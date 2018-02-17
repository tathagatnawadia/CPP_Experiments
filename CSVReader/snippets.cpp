#include <vector>
#include <string>
#include <sstream>
#include <iostream>

// std::vector<std::vector<std::string> > explode(const std::string& str, const char& delimiter_row, const char& delimiter_column) {
//     std::string next;
//     std::vector<std::vector<std::string> > result;
//     for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
//         if (*it == delimiter_row){
//             if(!next.empty()) {
//                 result.push_back(explode(next, delimiter_column));
//                 next.clear();
//             }
//         }
//         else {
//             next += *it;
//         }
//     }
// }

std::vector<std::string> explode(const std::string& str, const char& delimiter) {
	std::stringstream ss(str);
	std::vector<std::string> vec;
	while(ss.good()) {
	    std::string substr;
	    getline( ss, substr, ',' );
	    vec.push_back( substr );
	}
	return vec;
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}


int main()
{
    std::string str = "1,2,3,4,5,6";
    //std::vector<std::string> vect = explode(str, ',');
   	std::vector<std::string> vect  = split(str, ',');

    // std::stringstream ss(str);

    // int i;

    // while (ss >> i)
    // {
    //     vect.push_back(i);

    //     if (ss.peek() == ',')
    //         ss.ignore();
    // }
    int i;
    for (i=0; i< vect.size(); i++) {
        std::cout << vect.at(i)<<std::endl;
    }
}


