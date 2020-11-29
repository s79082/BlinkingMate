import socket
import serial
import sys

if len(sys.argv) == 1:
    print("usage")

UDP_IP = "192.168.1.113"
UDP_PORT = 65506
    
sock = socket.socket(socket.AF_INET, # Internet
                         socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

ser = serial.Serial('/dev/ttyACM0')
print(ser.is_open)

f = open('test.out', "w+")
# TODO config serial
    
while True:
    data, addr = sock.recvfrom(1300) # buffer size is 1024 bytes

    count = 0

    for byte in data:

        # substitue start byte
        if byte == 156:
            byte = 201

        # we dont want to send the package Nr and the package count
        if count == 4 or count == 5:
            count = count + 1
            continue

        count = count + 1


        ser.write(bytearray([byte])) 

    print("package with " + str(count))