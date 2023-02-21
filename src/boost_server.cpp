#include <boost_rs485_ClientServer.hpp>
#include <tabl_reg_config.hpp>
#include <iostream>

int main(int argc, char** argv) {
    string devPort = "";

    // if(argc == 2) {
    //     devPort = argv[1];
    // } else {
    //     std::cerr << "[program_name][devPort(1, 2...)]" << std::endl;
    //     return -1;
    // }
    const char* dev_name = "/dev/ttyUSB1";
    std::cout << "boost_server start.\n";
    boost_rs485::Boost_RS485_Master boostRS485_transp(dev_name);
    protocol_master::ProtocolMaster boostRS485_prot_master(boostRS485_transp);
    Boost_RS485_Server raspbPi(boostRS485_prot_master);
    raspbPi.polling();
}