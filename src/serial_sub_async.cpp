#include <unistd.h>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <chrono>
#include <thread>
#include <mutex>

#define BUFSIZE 256

using namespace std;
using namespace boost::asio;

class Client{
  uint8_t read_msg_[BUFSIZE];
  boost::asio::io_service ios;
  boost::asio::serial_port port;
  uint32_t m_recvdCount = 0;
  uint32_t m_sendCount = 0;
  std::mutex my_mytex;
  std::vector<uint8_t> m_copyRecvdData;

private:
  void handler(const boost::system::error_code& error, size_t bytes_transferred)
  {
    my_mytex.lock();
    if(!error && bytes_transferred > 0){
        m_recvdCount++;
        
        for (size_t i = 0; i < bytes_transferred; i++){
            m_copyRecvdData.push_back(read_msg_[i]);
        }
        printf("\n[RECEIVED]:\n");
        for (size_t i = 0; i < m_copyRecvdData.size(); i++)
        {
            printf("[%u]", m_copyRecvdData[i]);
        }
        std::cout << std::endl;
        cout << "bytes_transferred: "<< bytes_transferred << endl;
    } else {
        std::cout << "\n\033[1;31m[ERROR RESEIVED FROM SERIAL]\033[0m\n";
    }
    my_mytex.unlock();
    read_some();
  }

public:
  void read_some()
  {
    memset(read_msg_, 0, sizeof(read_msg_));
    port.async_read_some(boost::asio::buffer(read_msg_,sizeof(read_msg_)),
			 boost::bind(&Client::handler,this,
				     boost::asio::placeholders::error,
				     boost::asio::placeholders::bytes_transferred));
  }

  void sendData(const uint8_t* ptrData, uint32_t len)
  {
      boost::system::error_code error;
      size_t sendBytes = port.write_some(boost::asio::buffer(ptrData, len), error);
      if(!error && sendBytes > 0){
          m_sendCount++;
          std::cout << "\nport write returns: " + error.message();
          printf("\n[SEND]:\n");
          for (size_t i = 0; i < sendBytes; i++)
          {
              printf("[%u]", ptrData[i]);
          }
          std::cout << std::endl;
          cout << "sendBytes: "<< sendBytes << endl;
      } else {
          std::cout << "error.what()\n";
      }
  }


  Client(std::string port_, std::string boudrate):ios(),port(ios, port_)
  {
    port.set_option(boost::asio::serial_port_base::baud_rate(std::stoi(boudrate)));
    port.set_option(boost::asio::serial_port_base::character_size(8));
    port.set_option(boost::asio::serial_port_base::stop_bits(serial_port_base::stop_bits::one));
    port.set_option(boost::asio::serial_port_base::parity(serial_port_base::parity::none));
    port.set_option(boost::asio::serial_port_base::flow_control(serial_port_base::flow_control::none));

    boost::thread td(boost::bind(&boost::asio::io_service::run,&ios));
    read_some();
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
    client.sendData(dataS, sizeof(dataS));
    std::this_thread::sleep_for (std::chrono::milliseconds(1000));
  }
  return 0;
}