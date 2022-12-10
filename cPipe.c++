//boilerplate c++ imports:
#include <iostream>  // for input/output
#include <cstdio>  // for printf
#include <cstring>  // for string functions
#include <cmath>  // for mathematical functions
#include <ctime>  // for time functions
#include <algorithm>  // for algorithm functions
#include <vector>  // for vector containers
#include <queue>  // for queue containers
#include <stack>  // for stack containers
#include <map>  // for map containers
#include <set>  // for set containers
#include <utility>  // for pair
#include <limits>  // for numeric_limits
#include <cstdlib>  // for exit() and abs()
#include "unistd.h"
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


using namespace std;


// void sendImg(){
//     // Create the named pipe
//     int result = mkfifo("/tmp/image_pipe", 0666);
//     if (result == -1) {
//     // Handle error
//     }
//     // Open the named pipe for writing
//     int fd = open("/tmp/image_pipe", O_WRONLY);
//     if (fd == -1) {
//     // Handle error
//         cout<<"error opening pip"<<endl;
//     }

//     // Encode the image data as base64
//     std::string base64_data = encode_as_base64(image_data);

//     // Write the base64-encoded data to the named pipe
//     ssize_t bytes_written = write(fd, base64_data.data(), base64_data.size());
//     if (bytes_written == -1) {
//     // Handle error
//         cout<<"Error writting"<<endl;
//     }
// }

void sendText(){
    // Create the named pipe with read/write permissions
    const char* pipe_name = "./my_named_pipe";
    int ret = mkfifo(pipe_name, 0666);

    // Open the named pipe for writing
    int pipe_fd = open(pipe_name, O_WRONLY);

    // Write a message to the named pipe
    const char* message = "Hello from C++!";
    ret = write(pipe_fd, message, strlen(message));

    // Close the named pipe
    close(pipe_fd);

    // Open the named pipe for reading
    pipe_fd = open(pipe_name, O_RDONLY);

    // Read a response from the named pipe
    char response[1024];
    ret = read(pipe_fd, response, sizeof(response));

    // // Print the response to the console
    std::cout << "Received response: " << response << std::endl;

    // Close the named pipe
    close(pipe_fd);

}


int main(){
    sendText();

}
