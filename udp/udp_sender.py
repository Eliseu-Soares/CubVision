import socket

class UDPsender:
    def __init__(self, port: int, ip_address: str):
        self.SERVER_ADDRESS = (ip_address, port)

    def send(self, command):
        with socket.socket(
        socket.AF_INET,
        socket.SOCK_DGRAM
    ) as sock:
            sock.sendto(
                command.encode(),
                self.SERVER_ADDRESS
            )
