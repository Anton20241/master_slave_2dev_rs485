#include <boost_rs485_ClientServer.hpp>
#include <tabl_reg_config.hpp>
#include <iostream>

#define USBPORT_0 "/dev/ttyUSB0"
#define USBPORT_1 "/dev/ttyUSB1"
#define USBPORT_2 "/dev/ttyUSB2"

int main() {
    std::cout << "boost_server start.\n";
    boost_rs485::Boost_RS485_Master boostRS485_transp(USBPORT_0);
    protocol_master::ProtocolMaster boostRS485_prot_master(boostRS485_transp);
    Boost_RS485_Server raspbPi(boostRS485_prot_master);
    raspbPi.polling();
}