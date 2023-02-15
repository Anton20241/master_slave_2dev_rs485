#include <unistd.h>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <chrono>
#include <thread>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core.hpp>
#include <opencv2/aruco.hpp>

#define BOUDRATE 230400
#define DEVICE "/dev/ttyUSB0"

class ITransport
{
public:
    ITransport() {}
    virtual ~ITransport() {}
    virtual bool sendData() = 0;
};

class Server{
public:
    Server(){}
    void SendData(ITransport* transport_ptr){
        transport_ptr->sendData();
    }
private:
    ITransport* it_transport;
};

class Plane: public ITransport{
public:
    Plane(boost::asio::io_service& io_service_)
    : m_port(io_service_){
        boost::system::error_code error;
        m_port.open(DEVICE, error);
        if (!error)
        {
            // Configure basic serial port parameters: 115.2kBaud, 8N1
            m_port.set_option(boost::asio::serial_port_base::baud_rate(BOUDRATE));
            m_port.set_option(boost::asio::serial_port_base::character_size(8 /* data bits */));
            m_port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
            m_port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

            boost::thread td(boost::bind(&boost::asio::io_service::run, &io_service_));
            getData();
        }
    }

    void read_handler(const boost::system::error_code& error,size_t bytes_transferred)
    {
        if(!error){
            recvdCount++;
            std::cout << "socket read returns: " + error.message() << std::endl;
            std::cout << "recvdData: " << recvdData << std::endl;
            std::cout << "bytes_transferred: "<< bytes_transferred << std::endl;
        }
        getData();
    }

    void getData(){
        std::memset(recvdData, '\0', sizeof(recvdData));
        m_port.async_read_some(boost::asio::buffer(recvdData, sizeof(recvdData)),
                boost::bind(&Plane::read_handler,this,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
    }

    virtual bool sendData() override {
        size_t count = 0;
        boost::system::error_code reError;
        boost::system::error_code wrError;

        //create trackbars
        cv::namedWindow("Trackbars");
        cv::createTrackbar("C_S_Time", "Trackbars", &low_Time, high_Time);

        while(true) {
            cv::waitKey(1);
            size_t sendBytes = m_port.write_some(boost::asio::buffer(sendMsg), wrError);
            if(!wrError){
                // Write data to stdout
                std::cout << "sendBytes: " << sendBytes << std::endl;
                std::cout << "sendMsg: " << sendMsg << std::endl;
                std::cout << "count: " << count << std::endl;
            } else {
                //std::cerr << wrError.what();
            }
            std::this_thread::sleep_for (std::chrono::milliseconds(low_Time));
            count++;
        }
        return true;
    }

private:
    boost::asio::serial_port m_port;
    int low_Time = 0;
    int high_Time = 200;
    char sendMsg[18] = "Plane!!! Plane!!!";
    char recvdData[256] = {0};
    uint32_t sendCount = 0;
    uint32_t recvdCount = 0;
};


int main() {
    boost::asio::io_service io;
    Plane plane(io);
    Server myServ;
    myServ.SendData(&plane);
}