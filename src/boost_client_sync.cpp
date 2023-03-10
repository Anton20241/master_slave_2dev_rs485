#include <boost_rs485_ClientServer.hpp>
#include <tabl_reg_config.hpp>
#include <iostream>

int main(int argc, char** argv) {
    int devAddr = 0;
    std::string devPort = "";
    
    if(argc == 3) {
        devAddr = std::stoi(argv[1]);
        devPort = argv[2];
    } else {
        std::cerr << "[program_name][devAddr(1, 2...)][devPort(1, 2...)]" << std::endl;
        return -1;
    }
    std::cout << "boost_client_sync start.\n\n";
    boost_rs485::Boost_RS485_Slave_sync boostRS485_transp("/dev/ttyUSB" + devPort);
    tabl_reg::TablReg m_tabl(tabl_reg_cfg::tablRegConfig);
    protocol::Protocol boostRS485_prot(boostRS485_transp, m_tabl, devAddr);
    Boost_RS485_Client client(boostRS485_prot, m_tabl);
    client.pollingSensors();
}