#include <iostream>
#include <stdlib.h>

namespace error {
	struct base : std::exception{
		virtual void format_error_message() const = 0;                          
       
        const char* what() const throw() {
                format_error_message();
                return error_message_buffer;
        }

        mutable char error_message_buffer[512];
	};

	const int max_file_name_length = 255;

	struct with_file_name {
		with_file_name() {
			std::memset(file_name, 0, max_file_name_length+1);
		}

		void set_file_name(const char* file_name){
			std::strncpy(this->file_name, file_name, max_file_name_length);
			this->file_name[max_file_name_length] = '\0';
		}

		char file_name[max_file_name_length+1];

	};

	 struct with_file_line{
            with_file_line(){
                    file_line = -1;
            }
           
            void set_file_line(int file_line){
                    this->file_line = file_line;
            }

            int file_line;
    };

    struct with_errno{
            with_errno(){
                    errno_value = 0;
            }
           
            void set_errno(int errno_value){
                    this->errno_value = errno_value;
            }

            int errno_value;
    };

	struct can_not_open_file:
		base,
		with_file_name,
		with_errno{

			void format_error_message() const {
				if(errno_value != 0)
					std::snprintf(error_message_buffer, sizeof(error_message_buffer),
                                                "Can not open file \"%s\" because \"%s\"."
                                                , file_name, std::strerror(errno_value));
				else
					std::snprintf(error_message_buffer, sizeof(error_message_buffer),
                                                "Can not open file \"%s\""
                                                , file_name);
			}
	};
}


class ByteSource {
	virtual int read(char* buffer, int size) = 0;
	virtual ~ByteSource() {}
};


namespace detail {
	class OwningStdIOByteSourceBase : public ByteSource {
		explicit OwningStdIOByteSourceBase(FILE *file)
	}
}

namespace detail {
	class 
}
int main(){
	std::cout << "Hello World !!" << std::endl;
	return 0;
}