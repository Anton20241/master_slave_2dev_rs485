#include <boost/asio.hpp>
#include <iostream>
#include <protocol.hpp>
#include <chrono>
#include <thread>

#define BUFSIZE 256
#define BOUDRATE 230400
#define DEVICE "/dev/ttyUSB0"


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
    uint8_t data[BUFSIZE];
    while(true) {
        boost::system::error_code error;
        size_t recvdBytes = serial.read_some(boost::asio::buffer(data, BUFSIZE), error);
        if(!error){
            // Write data to stdout
            data[BUFSIZE] = 0;
            std::cout << "recvdBytes: " << recvdBytes << std::endl;
            std::cout << "data: " << data << std::endl;
            size_t sendBytes = serial.write_some(boost::asio::buffer(data, BUFSIZE), error);
            std::cout << "sendBytes: " << sendBytes << std::endl;
            std::cout << "data: " << data << std::endl;
            std::cout << "count: " << count << std::endl;

            memset(data, 0, sizeof(data));
            count++;
            
        } else {
            //std::cerr << error.what();
        }
    }
}