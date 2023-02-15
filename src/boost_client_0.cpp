#include <boost_rs485_ClientServer.hpp>
#include <tabl_reg_config.hpp>
#include <iostream>

#define MY_DEVICE 0x01
#define USBPORT_0 "/dev/ttyUSB0"
#define USBPORT_1 "/dev/ttyUSB1"

int main() {
    std::cout << "boost_client_0 start.\n\n";
    boost_rs485::Boost_RS485_Slave boostRS485_transp(USBPORT_0);
    tabl_reg::TablReg m_tabl(tabl_reg_cfg::tablRegConfig);
    protocol::Protocol boostRS485_prot(boostRS485_transp, m_tabl, MY_DEVICE);
    Boost_RS485_Client client(boostRS485_prot, m_tabl);
    client.pollingSensors();
}