# Python code

import os

def main():
    # Create the named pipe with read/write permissions
    
    pipe_name = "./pubSubPipe"

    
    # Open the named pipe for writing
    # if  os.path.exists(pipe_name):
    #     pipe_fd = os.open(pipe_name, os.O_WRONLY)
    #     os.close()
    
    if not os.path.exists(pipe_name):
        os.mkfifo(pipe_name, 0o666)
    pipe_fd = os.open(pipe_name, os.O_WRONLY)
    print("Pipe opened!")
    
    inp = input("Begin publishing?")
    while (inp == "y"):
        # Publish a message to the named pipe
        message = b"Hello from Python!"
        os.write(pipe_fd, message)
        inp = input('publish again?')
        
    os.close(pipe_fd)
if __name__ == "__main__":
    main()
