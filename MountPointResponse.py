
import socket

UserAgent = 'MountPointScript'


Server = '115.42.198.157'
Port = 2101



client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = (Server, Port)
client_socket.connect(server_address)

request_header = ('GET / HTTP/1.0\r\n' +
                'Host: %s:%s\r\n' +
                'User-Agent: %s\r\n' +
                'Accept: */*\r\n' +
                '\r\n') % (Server, Port, UserAgent)

print("**********************")
print("*  request_header    *")
print("**********************")
print(request_header)

request_header = bytes(request_header, encoding='utf-8')
client_socket.send(request_header)

response = b''
while True:
    recv = client_socket.recv(1024)
    if not recv:
        break
    response += recv 

print("**********************")
print("*     response       *")
print("**********************")

# response contains a bunch of '\r\n' terminated lines
response = str(response, 'UTF-8')
print (response)
client_socket.close()