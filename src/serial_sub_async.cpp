#include <unistd.h>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include <chrono>
#include <thread>
#include <mutex>

#define BUFSIZE 16

using namespace std;
using namespace boost::asio;

class Client{
  uint8_t read_msg_[BUFSIZE];
  boost::asio::io_service ios;
  boost::asio::serial_port port;
  uint32_t m_recvdCount = 0;
  uint32_t m_sendCount = 0;
  //std::mutex my_mytex;
  std::vector<uint8_t> m_copyRecvdData;
  boost::chrono::system_clock::time_point tp_first = boost::chrono::system_clock::now();

private:

  void read_handler(const boost::system::error_code& error, size_t bytes_transferred)
  {
    std::cout << "!!!!!!!!!read_handler!!!!!!!!!\n";
    
    //my_mytex.lock();
    if(!error && bytes_transferred > 0){
    
        boost::chrono::duration<double> us = boost::chrono::system_clock::now() - tp_first;
        std::cout << "exec time: " << us.count() * 1000000 << " us" << std::endl;
        tp_first = boost::chrono::system_clock::now();
    
        m_recvdCount++;
        cout << "m_recvdCount: "<< m_recvdCount << endl;
        printf("\n[RECEIVED]:\n");
        for (size_t i = 0; i < bytes_transferred; i++)
        {
            printf("[%u]", read_msg_[i]);
        }
        std::cout << std::endl;
        
        for (size_t i = 0; i < bytes_transferred; i++){
            m_copyRecvdData.push_back(read_msg_[i]);
        }

        cout << "bytes_transferred: "<< bytes_transferred << endl;
    } else {
        std::cout << "\n\033[1;31m[ERROR RESEIVED FROM SERIAL]\033[0m\n";
    }
    //my_mytex.unlock();
    read_msg_serial();
  }
  
  void read_msg_serial()
  {
    memset(read_msg_, 0, sizeof(read_msg_));
    port.async_read_some(boost::asio::buffer(read_msg_,sizeof(read_msg_)),
			 boost::bind(&Client::read_handler,this,
				     boost::asio::placeholders::error,
				     boost::asio::placeholders::bytes_transferred));
  }

public:

  uint32_t sendData(const uint8_t* ptrData, uint32_t len)
  {
      boost::system::error_code error;
      size_t sendBytes = write(port,boost::asio::buffer(ptrData, len));
      if(!error && sendBytes > 0){
          m_sendCount++;
          cout << "m_sendCount: "<< m_sendCount << endl;
          std::cout << "\nport write returns: " + error.message();
          
          printf("\n[SEND]:\n");
          for (size_t i = 0; i < sendBytes; i++)
          {
              printf("[%u]", ptrData[i]);
          }
          std::cout << std::endl;
          cout << "sendBytes: "<< sendBytes << endl;
          return sendBytes;
      } else {
          std::cout << "error.what()\n";
          return -1;
      }
  }

  uint32_t getData(uint8_t* ptrData)
  {
    uint8_t dataR[BUFSIZE] = {0};
    size_t r = port.read_some(boost::asio::buffer(dataR));
    // Write data to stdout
    if(r > 0){
        m_recvdCount++;
        printf("\nresvd new pack\n");
        printf("m_recvdCount = %u\n", m_recvdCount);
        for(int i = 0; i < r; i++){
            printf("[%u]", dataR[i]);
        }
        std::cout << std::endl;
        printf("r = %u\n", r);
    }
    memcpy(dataR, ptrData, r);
    return r;
  }

    Client(std::string port_, std::string boudrate):ios(),port(ios, port_)
      {
          // Configure basic serial port parameters
          termios t;
          int m_fd;
          m_fd = port.native_handle();
          if (tcgetattr(m_fd, &t) < 0) { /* handle error */ }
          if (cfsetspeed(&t, std::stoi(boudrate)) < 0) { /* handle error */ }
          if (tcsetattr(m_fd, TCSANOW, &t) < 0) { /* handle error */ }
          port.set_option(boost::asio::serial_port_base::baud_rate(std::stoi(boudrate)));
          port.set_option(boost::asio::serial_port_base::character_size(8 /* data bits */));
          port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
          port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
          port.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));

          // boost::thread td(boost::bind(&boost::asio::io_service::run, &ios));
          // read_msg_serial();
      }
};


int main(int argc,char* argv[])
{
  if(argc < 3){
      std::cout << "[./serial_sub_async][/dev/ttyX][baudrate]\n";
      return -1;
  }

  std::string port = argv[1];
  std::string baudrate = argv[2];

  std::cout << "serial_sub_async start" << std::endl;
  Client client("/dev/tty" + port, baudrate);
  while(1){
    uint8_t dataS[] = {0x01, 0x06, 0x20, 0x01, 0x02, 0xA6};
    uint32_t bt = client.sendData(dataS, sizeof(dataS));
    uint8_t dataR[BUFSIZE] = {0};
    if (bt > 0){
      client.getData(dataR);
    }
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
  }
  return 0;
}
