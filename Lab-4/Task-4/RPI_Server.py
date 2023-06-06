import socket
from datetime import datetime

def createSocketAndConnect(HOST, PORT):  
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, PORT))
    s.listen() 
    print("Server is created. Waiting for client...")
    client, addr = s.accept()
    print(f"Client with IP {addr} connected on port {PORT}.")
    client.settimeout(None)        
        
    while True:
        content = str(client.recv(1024), 'utf-8')
        if content.strip() != "" and content != "\n":
            if content == "T" or content == "t":
                # send current time to the client
                now = datetime.now()
                current_time = now.strftime("%H:%M:%S")
                client.send(bytes("Response: Time is now: " + current_time, 'utf-8'))
                print("Client served with response -> Time is now: " + current_time)
            else :
                # Response: Unknown Request
                client.send(b'Response: Unknown Request.')
                print("Client served with response -> Unknown Request.")
   
if __name__ == "__main__":
    print("Setting up the server...")
    createSocketAndConnect("XXX.XXX.XXX.XXX", 8585)
    
    