#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <exception>

// for mmap:
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

void handle_error(std::string msg){

}

namespace errors {
    namespace filerr {
        struct FileNotFound : public std::exception {
            std::string filename;
            explicit FileNotFound() : filename("NO_FILENAME_SET") {}
            explicit FileNotFound(const std::string& fname) : filename(fname) {}
            virtual const char* what() const throw() {
                return filename.c_str();
            }
            virtual ~FileNotFound() throw() {}
        };
    }

    namespace custom {
        struct GenericError : public std::exception {
            std::string message;
            explicit GenericError() : message("NO_ERROR_MESSAGE_SET") {}
            explicit GenericError(const std::string& message) : message(message) {}
            const char* what() const throw() {
                return message.c_str();
            }
            virtual ~GenericError() throw() {}
        };
    }
}


namespace utilities {
    void print() {
        std::cout<<std::endl;
    }

    template<typename First, typename ... Rest>
    void print(First first, const Rest& ... rest) {
        std::cout<< first << " ";
        utilities::print(rest ...);
    }
}



std::vector<std::string> explode(const std::string& str, const char& ch) {
    std::string next;
    std::vector<std::string> result;
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        if (*it == ch)
            if (!next.empty()) {
                result.push_back(next);
                next.clear();
            }
            else {
                result.push_back("");
                next.clear();
            }
        else
            next += *it;
    }

    if (!next.empty())
         result.push_back(next);
    return result;
}


std::vector<std::vector<std::string> > explode(const std::string& str, const char& delimiter_row, const char& delimiter_column) {
    std::string next;
    std::vector<std::vector<std::string> > result;
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        if (*it == delimiter_row){
            if(!next.empty()) {
                result.push_back(explode(next, delimiter_column));
                next.clear();
            }
        }
        else {
            next += *it;
        }
    }
    return result;
}

const char* map_file(const char* fname, size_t& length) {
    int fd = open(fname, O_RDONLY);
    if (fd == -1)
        throw errors::filerr::FileNotFound(fname);

    // obtain file size
    struct stat sb;
    if (fstat(fd, &sb) == -1)
        throw errors::custom::GenericError("FSAT");

    length = sb.st_size;

    const char* addr = static_cast<const char*>(mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0u));
    if (addr == MAP_FAILED)
        throw errors::custom::GenericError("MMAP");

    // TODO close fd at some point in time, call munmap(...)
    return addr;
}

int main()
{
    size_t length;
        auto f = map_file("train.csv", length);
        auto l = f + length;
        std::string copy = f;
        std::vector<std::vector<std::string> > result = explode(copy, '\n', ',');
        utilities::print(result.size());
        utilities::print("Row     : ", result.size());
        utilities::print("Columns : ", result[1].size());


        // uintmax_t m_numLines = 0;
        // while (f && f!=l)
        //     if ((f = static_cast<const char*>(memchr(f, '\n', l-f)))){
        //         m_numLines++, f++;
        //     }

        //std::cout << "m_numLines = " << m_numLines << "\n";
}

