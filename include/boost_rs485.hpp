
/**
 *  @file       boost_rs485.hpp
 *  @brief
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#pragma once

/* Includes ------------------------------------------------------------------*/
#include "i_transport.hpp"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>

#define BOUDRATE 230400

using namespace std;
using namespace boost::asio;

namespace boost_rs485
{
    static const uint32_t proto_max_buff    = 32;

    class Boost_RS485_Master : public i_transport::ITransport
    {
    private:
        boost::asio::io_service    m_ioService;
        boost::asio::serial_port   m_port;
        uint8_t m_recvdData[proto_max_buff] = {0};
        bool m_recvd = false;
        uint32_t m_sendCount = 0;
        uint32_t m_recvdCount = 0;

        void read_handler(const boost::system::error_code& error,size_t bytes_transferred)
        {
            if(!error){
                m_recvdCount++;
                m_recvd = true;
                std::cout << "\nport read returns: " + error.message();
                printf("\n[I RECEIVED]:\n"
                "[%u][%u][%u][%u\t][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u]\n"
                "m_recvdCount = %u\n",
                m_recvdData[0], m_recvdData[1], m_recvdData[2], m_recvdData[3],
                m_recvdData[4], m_recvdData[5], m_recvdData[6], m_recvdData[7], 
                m_recvdData[8], m_recvdData[9], m_recvdData[10], m_recvdData[11],
                m_recvdData[12], m_recvdData[13], m_recvdData[14], m_recvdData[15], m_recvdCount);
                cout << "bytes_transferred: "<< bytes_transferred << endl;
            }
            getData();
        }

    public:
        Boost_RS485_Master(const char* dev_name):m_ioService(),m_port(m_ioService, dev_name)
        {
            m_port.set_option(boost::asio::serial_port_base::baud_rate(BOUDRATE));
            m_port.set_option(boost::asio::serial_port_base::character_size(8));
            m_port.set_option(boost::asio::serial_port_base::stop_bits(serial_port_base::stop_bits::one));
            m_port.set_option(boost::asio::serial_port_base::parity(serial_port_base::parity::none));
            m_port.set_option(boost::asio::serial_port_base::flow_control(serial_port_base::flow_control::none));

            boost::thread td(boost::bind(&boost::asio::io_service::run, &m_ioService));
            getData();
        }
        
        bool sendData(const uint8_t* ptrData, uint32_t len)
        {
            boost::system::error_code error;
            size_t sendBytes = m_port.write_some(boost::asio::buffer(ptrData, len), error);
            if(!error){
                m_sendCount++;
                std::cout << "\nport write returns: " + error.message();
                printf("\n[I SEND]:\n"
                "[%u][%u][%u][%u\t][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u]\n"
                "m_sendCount = %u\n",
                ptrData[0], ptrData[1], ptrData[2], ptrData[3],
                ptrData[4], ptrData[5], ptrData[6], ptrData[7], 
                ptrData[8], ptrData[9], ptrData[10], ptrData[11],
                ptrData[12], ptrData[13], ptrData[14], ptrData[15], m_sendCount);
                cout << "sendBytes: "<< sendBytes << endl;
                return true;
            } else {
                //std::cerr << error.what();
                return false;
            }
        }

        bool getData(uint8_t* ptrData, uint32_t* lenInOut)
        {
            if (!m_recvd) return false;
            std::memcpy(ptrData, m_recvdData, sizeof(ptrData));
            m_recvd = false;
            return true;
        }

        void getData(){
            std::memset(m_recvdData, 0, sizeof(m_recvdData));
            m_port.async_read_some(boost::asio::buffer(m_recvdData, sizeof(m_recvdData)),
                    boost::bind(&Boost_RS485_Master::read_handler,this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
        }

        bool transportReset() {return true;}
            
        ~Boost_RS485_Master() override {};
    };
    
/////////////////////////////////////////////////////////////////
    class Boost_RS485_Slave : public i_transport::ITransport
    {
    private:
        boost::asio::io_service    s_ioService;
        boost::asio::serial_port   s_port;
        uint8_t s_recvdData[proto_max_buff] = {0};
        bool s_recvd = false;
        uint32_t s_sendCount = 0;
        uint32_t s_recvdCount = 0;

        void read_handler(const boost::system::error_code& error,size_t bytes_transferred)
        {
            if(!error){
                s_recvdCount++;
                std::cout << "\nport read returns: " + error.message();
                s_recvd = true;
                printf("\n[I RECEIVED]:\n"
                "[%u][%u][%u][%u\t][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u]\n"
                "s_recvdCount = %u\n",
                s_recvdData[0], s_recvdData[1], s_recvdData[2], s_recvdData[3],
                s_recvdData[4], s_recvdData[5], s_recvdData[6], s_recvdData[7], 
                s_recvdData[8], s_recvdData[9], s_recvdData[10], s_recvdData[11],
                s_recvdData[12], s_recvdData[13], s_recvdData[14], s_recvdData[15], s_recvdCount);
                cout << "bytes_transferred: "<< bytes_transferred << endl;
            }
            getData();
        }

    public:
        Boost_RS485_Slave(std::string dev_name):s_ioService(),s_port(s_ioService, dev_name)
        {
            s_port.set_option(boost::asio::serial_port_base::baud_rate(BOUDRATE));
            s_port.set_option(boost::asio::serial_port_base::character_size(8));
            s_port.set_option(boost::asio::serial_port_base::stop_bits(serial_port_base::stop_bits::one));
            s_port.set_option(boost::asio::serial_port_base::parity(serial_port_base::parity::none));
            s_port.set_option(boost::asio::serial_port_base::flow_control(serial_port_base::flow_control::none));

            boost::thread td(boost::bind(&boost::asio::io_service::run, &s_ioService));
            getData();
        }
        
        bool sendData(const uint8_t* ptrData, uint32_t len)
        {
            boost::system::error_code error;
            size_t sendBytes = s_port.write_some(boost::asio::buffer(ptrData, len), error);
            if(!error){
                s_sendCount++;
                std::cout << "\nport write returns: " + error.message();
                printf("\n[I SEND]:\n"
                "[%u][%u][%u][%u\t][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u]\n"
                "s_sendCount = %u\n",
                ptrData[0], ptrData[1], ptrData[2], ptrData[3],
                ptrData[4], ptrData[5], ptrData[6], ptrData[7], 
                ptrData[8], ptrData[9], ptrData[10], ptrData[11],
                ptrData[12], ptrData[13], ptrData[14], ptrData[15], s_sendCount);
                cout << "sendBytes: "<< sendBytes << endl;
                return true;
            } else {
                //std::cerr << error.what();
                return false;
            }
        }

        bool getData(uint8_t* ptrData, uint32_t* lenInOut)
        {
            if (!s_recvd) return false;
            std::memcpy(ptrData, s_recvdData, sizeof(ptrData));
            s_recvd = false;
            return true;
        }

        void getData(){
            std::memset(s_recvdData, 0, sizeof(s_recvdData));
            s_port.async_read_some(boost::asio::buffer(s_recvdData, sizeof(s_recvdData)),
                    boost::bind(&Boost_RS485_Slave::read_handler,this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
        }

        bool transportReset() {return true;}
            
        ~Boost_RS485_Slave() override {};
    };

/////////////////////////////////////////////////////////////////

    class Boost_RS485_Slave_sync : public i_transport::ITransport
    {
    public:
        Boost_RS485_Slave_sync(string dev_name):sync_ioService(),sync_port(sync_ioService, dev_name)
        {
            sync_port.set_option(boost::asio::serial_port_base::baud_rate(BOUDRATE));
            sync_port.set_option(boost::asio::serial_port_base::character_size(8));
            sync_port.set_option(boost::asio::serial_port_base::stop_bits(serial_port_base::stop_bits::one));
            sync_port.set_option(boost::asio::serial_port_base::parity(serial_port_base::parity::none));
            sync_port.set_option(boost::asio::serial_port_base::flow_control(serial_port_base::flow_control::none));
        }
    
        bool sendData(const uint8_t* ptrData, uint32_t len)
        {
            boost::system::error_code error;
            size_t sendBytes = sync_port.write_some(boost::asio::buffer(ptrData, len), error);
            if(!error){
                sync_sendCount++;
                std::cout << "\nport write returns: " + error.message();
                printf("\n[I SEND]:\n"
                "[%u][%u][%u][%u\t][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u]\n"
                "sync_sendCount = %u\n",
                ptrData[0], ptrData[1], ptrData[2], ptrData[3],
                ptrData[4], ptrData[5], ptrData[6], ptrData[7], 
                ptrData[8], ptrData[9], ptrData[10], ptrData[11],
                ptrData[12], ptrData[13], ptrData[14], ptrData[15], sync_sendCount);
                cout << "sendBytes: "<< sendBytes << endl;
                return true;
            } else {
                //std::cerr << error.what();
                return false;
            }
        }

        bool getData(uint8_t* ptrData, uint32_t* lenInOut)
        {
            boost::system::error_code error;
            size_t recvdBytes = sync_port.read_some(boost::asio::buffer(ptrData, sizeof(ptrData)), error);
            if(!error){
                sync_recvdCount++;
                std::cout << "\nport read returns: " + error.message();
                printf("\n[I RECEIVED]:\n"
                "[%u][%u][%u][%u\t][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u][%u]\n"
                "sync_recvdCount = %u\n",
                ptrData[0], ptrData[1], ptrData[2], ptrData[3],
                ptrData[4], ptrData[5], ptrData[6], ptrData[7], 
                ptrData[8], ptrData[9], ptrData[10], ptrData[11],
                ptrData[12], ptrData[13], ptrData[14], ptrData[15], sync_recvdCount);
                cout << "recvdBytes: "<< recvdBytes << endl;
                return true;
            } else {
                //std::cerr << error.what();
                return false;
            }
        }

        bool transportReset() {return true;}
            
        ~Boost_RS485_Slave_sync() override {};

    private:
        boost::asio::io_service    sync_ioService;
        boost::asio::serial_port   sync_port;
        uint32_t sync_sendCount = 0;
        uint32_t sync_recvdCount = 0;
    };
}