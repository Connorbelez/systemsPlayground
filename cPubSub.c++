// C++ code

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

void subscriber(){
    // Open the named pipe for reading
    const char* pipe_name = "./pubSubPipe";

    int pipe_fd = open(pipe_name, O_RDONLY | O_NONBLOCK);

    // Create a set of file descriptors to monitor
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(pipe_fd, &read_fds);

    // Check if there is data available to read
    while(1){
        int ret = select(pipe_fd + 1, &read_fds, NULL, NULL, NULL);

        // If there is data available to read...
        if (ret > 0) {
            // Read a message from the named pipe
            char message[1024];
            ssize_t bytes_read = read(pipe_fd, message, sizeof(message));
              if (bytes_read == 0) {
                std::cout << "Publisher closed the pipe" << std::endl;
                break;
            }

            // Print the message to the console
            std::cout << "Received message: " << message << std::endl;
        }
    }

    // Close the named pipe
    close(pipe_fd);
}


int main()
{
    // Open the named pipe for reading
    // const char* pipe_name = "./my_named_pipe";
    // int pipe_fd = open(pipe_name, O_RDONLY);

    // // Subscribe to messages from the named pipe
    // char message[1024];
    // int ret = read(pipe_fd, message, sizeof(message));

    // // Print the received message to the console
    // std::cout << "Received message: " << message << std::endl;

    // // Close the named pipe
    // close(pipe_fd);


    subscriber();
    return 0;
}
