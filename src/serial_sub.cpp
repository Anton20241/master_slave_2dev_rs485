#include <boost/asio.hpp>
#include <iostream>
#include <protocol.hpp>
#include <chrono>
#include <thread>

#define BUFSIZE 4
#define BOUDRATE 460800
#define DEVICE "/dev/ttyUSB1"

int main() {
    boost::asio::io_service io;
    // Open serial port
    boost::asio::serial_port serial(io, DEVICE);

    // Configure basic serial port parameters: 115.2kBaud, 8N1
    serial.set_option(boost::asio::serial_port_base::baud_rate(BOUDRATE));
    serial.set_option(boost::asio::serial_port_base::character_size(8 /* data bits */));
    serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
    serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

    // Read data in a loop and copy to stdout
    size_t count = 0;
    char data[BUFSIZE];
    while(true) {
        boost::system::error_code reError;
        boost::system::error_code wrError;
        memset(data, '\0', sizeof(data));
        size_t recvdBytes = serial.read_some(boost::asio::buffer(data, BUFSIZE), reError);
        if(!reError){
            std::cout << "socket read returns: " + reError.message() << std::endl;
            std::cout << "recvdBytes: " << recvdBytes << std::endl;
            std::cout << "data: " << data << std::endl;
            size_t sendBytes = serial.write_some(boost::asio::buffer(data, BUFSIZE), wrError);
            if(!wrError){
                std::cout << "socket write returns: " + wrError.message() << std::endl;
                std::cout << "sendBytes: " << sendBytes << std::endl;
                std::cout << "data: " << data << std::endl;
                std::cout << "count: " << count << std::endl;
            } else {
                //std::cerr << wrError.what();
            }
            count++;
        } else {
            //std::cerr << reError.what();
        }
    }
}