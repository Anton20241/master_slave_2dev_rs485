#include <unistd.h>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <chrono>
#include <thread>

#define BUFSIZE 256
#define BOUDRATE 230400
#define DEVICE "/dev/ttyUSB0"

using namespace std;
using namespace boost::asio;

class Client{
  uint8_t read_msg_[BUFSIZE];
  boost::asio::io_service ios;
  boost::asio::serial_port port;
  uint32_t count = 0;

private:
  void handler(const boost::system::error_code& error,size_t bytes_transferred)
  {
    count++;
    read_msg_[bytes_transferred] = 0;
    std::cout << "bytes_transferred: " << bytes_transferred << std::endl;
    std::cout << "read_msg_: " << read_msg_ << std::endl;
    std::cout << "count: " << count << std::endl;

    cout << bytes_transferred << " bytes: "<< read_msg_ <<endl;
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


  Client(const char* dev_name):ios(),port(ios,dev_name)
  {
    port.set_option(boost::asio::serial_port_base::baud_rate(BOUDRATE));
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
  std::cout << "serial_sub_async start" << std::endl;
  Client client(DEVICE);
  while(1){}
  return 0;
}