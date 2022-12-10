import os
from PIL import Image


def sendImg():
# Open named pipe for writing
    pipe_name = "/tmp/pYpipeSend"
    pipe_fd = os.open(pipe_name, os.O_WRONLY)

    # Load image and convert to binary data
    img = Image.open("my_image.jpg")
    img_data = img.tobytes()

    # Write binary data to named pipe
    os.write(pipe_fd, img_data)

    # Close named pipe
    os.close(pipe_fd)

def readImg():
    # Open the named pipe for reading
    with open("/tmp/cPipeSend", "rb") as f:
    # Read the base64-encoded data from the named pipe
        base64_data = f.read()
    # Decode the base64-encoded data
        image_data = decode_from_base64(base64_data)
    # Save the image data to a file on disk
    with open("image.jpg", "wb") as f:
        f.write(image_data)



def readText():
        # Open the named pipe for reading
    pipe_name = "./my_named_pipe"
    pipe_fd = os.open(pipe_name, os.O_RDONLY)

    # Read a message from the named pipe
    message = os.read(pipe_fd, 1024)
    print("Received message:", message)

    # Close the named pipe
    os.close(pipe_fd)

    # Open the named pipe for writing
    pipe_fd = os.open(pipe_name, os.O_WRONLY)

    # Write a response to the named pipe
    response = b"Hello from Python!"
    os.write(pipe_fd, response)

    # Close the named pipe
    os.close(pipe_fd)

def main():
    readText()

main()
