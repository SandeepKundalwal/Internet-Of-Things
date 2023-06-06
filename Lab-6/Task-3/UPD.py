import socket

UDP_IP = "XXX.XXX.XXX.XXX"
UDP_PORT = 1880

if __name__ == "__main__":
    while True:
        randomNumber = int(input("Enter a random number between 1 to 100: "))
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.sendto(randomNumber.to_bytes(),  (UDP_IP, UDP_PORT))