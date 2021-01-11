#include <iostream>
#include <unistd.h>

#include "Socket.hpp"

#define HOSTNAME_MAX 255

using namespace std;

int main(int argc, char **argv) {
    try {
        Socket::UDP sock;
        sock.bind(SERVER_PORT);
        while (true) {
            Socket::Datagram received = sock.receive();
            cout << "Received "
                 << received.data
                 << " from "
                 << received.address.ip
                 << ":"
                 << received.address.port
                 << endl;
            char *hostname = new char[HOSTNAME_MAX];
            gethostname(hostname, HOSTNAME_MAX);
            sock.send(received.address.ip, received.address.port, hostname);
        }
    } catch (Socket::Exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}
