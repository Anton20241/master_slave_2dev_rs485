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

#define BOUDRATE 230400

using namespace std;
using namespace boost::asio;

namespace boost_rs485
{
/* Exported defines ----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
    typedef struct
    {
        
    } boost_rs485SPort_param;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

    static const uint32_t proto_max_buff    = 32;

    class Boost_RS485 : public i_transport::ITransport
    {
    private:
        boost::asio::io_service    m_ioService;
        boost::asio::serial_port   m_port;
        uint8_t m_recvdData[proto_max_buff] = {0};
        uint32_t* m_lenInOut;
        bool recvd = false;

        void read_handler(const boost::system::error_code& error,size_t bytes_transferred)
        {
            recvd = true;
            printf("\n[I RESEIVED]:\n"
            "ptrData[0] = %d\n"
            "ptrData[1] = %d\n"
            "ptrData[2] = %d\n"
            "ptrData[3] = %d\n"
            "ptrData[4] = %d\n"
            "ptrData[5] = %d\n"
            "ptrData[6] = %d\n"
            "ptrData[7] = %d\n",
            m_recvdData[0], m_recvdData[1], m_recvdData[2], m_recvdData[3],
            m_recvdData[4], m_recvdData[5], m_recvdData[6], m_recvdData[7]);
            cout << " bytes_transferred: "<< bytes_transferred << endl;
            getData();
        }

    public:
        Boost_RS485(const char* dev_name):m_ioService(),m_port(m_ioService, dev_name)
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
                printf("\n[I SEND]:\n"
                "ptrData[0] = %d\n"
                "ptrData[1] = %d\n"
                "ptrData[2] = %d\n"
                "ptrData[3] = %d\n"
                "ptrData[4] = %d\n"
                "ptrData[5] = %d\n"
                "ptrData[6] = %d\n"
                "ptrData[7] = %d\n",
                ptrData[0], ptrData[1], ptrData[2], ptrData[3],
                ptrData[4], ptrData[5], ptrData[6], ptrData[7]);
                return true;
            } else {
                //std::cerr << error.what();
                return false;
            }
        }

        bool getData(uint8_t* ptrData, uint32_t* lenInOut)
        {
            std::memcpy(ptrData, m_recvdData, sizeof(ptrData));
            if (!recvd){
                return false;
            } else{
                recvd = false;
                return true;
            }
        }

        void getData(){
            m_port.async_read_some(boost::asio::buffer(m_recvdData, sizeof(m_recvdData)),
                    boost::bind(&Boost_RS485::read_handler,this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
        }

        bool transportReset() {return true;}
            
        ~Boost_RS485() override {};
    };
}