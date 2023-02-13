#include <unistd.h>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

#define BUFSIZE 256
#define BOUDRATE 230400
#define DEVICE "/dev/ttyUSB1"

using namespace std;
using namespace boost::asio;

class Client{
  char read_msg_[BUFSIZE];
  boost::asio::io_service ios;
  boost::asio::serial_port port;
private:
  void handler(const boost::system::error_code& error,size_t bytes_transferred)
  {
    read_msg_[bytes_transferred] = 0;
    cout << bytes_transferred << " bytes: "<< read_msg_ <<endl;
    read_some();
  }

public:
  void read_some()
  {
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
  size_t count = 0;
  while(1){
    std::cout << "count = " << count << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
    count++;
  }
  return 0;
}