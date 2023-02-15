/**
 *  @file       boost_rs485_ClientServer.hpp
 *  @brief
 */

#pragma once
#include "boost_rs485.hpp"
#include "protocol.hpp"
#include "umba_crc_table.h"
#include <chrono>
#include <thread>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core.hpp>
#include <opencv2/aruco.hpp>

class Boost_RS485_Server
{
public:
    Boost_RS485_Server(protocol_master::ProtocolMaster& protocol_)
    : m_protocol(protocol_){};

    void polling(){
        size_t count = 0;
        std::vector <bool> answRecvd(device.size(), 0);
        std::vector <size_t> answRecvdFailedCount(device.size(), 0);
        int low_C_S_Time = 0;
        int high_C_S_Time = 20000;
        //create trackbars
        cv::namedWindow("Trackbars");
        cv::createTrackbar("C_S_Time", "Trackbars", &low_C_S_Time, high_C_S_Time);
        

        while(1){
            cv::waitKey(1);
            for (int i = 0; i < device.size(); i++){
                answRecvd[i] = m_protocol.sendCmdNOP(device[i]);

                if (!answRecvd[i])
                    answRecvdFailedCount[i]++;
                else 
                    answRecvdFailedCount[i] = 0;

                if (answRecvdFailedCount[i] == 10) {
                    std::cout << "\n\n\n!!!DEVICE[" << i << "] CONNECT ERROR!!!\n\n\n";
                }
                std::this_thread::sleep_for(std::chrono::microseconds(low_C_S_Time));
            }
            std::cout << "\n<------[count] = " << count << "------>\n" << std::endl;
            count++; 
        }
    }
private:
    protocol_master::ProtocolMaster& m_protocol;
    std::vector<uint8_t> device = {0x01, 0x02};
};

class Boost_RS485_Client
{
public:
    Boost_RS485_Client(protocol::Protocol& protocol_, tabl_reg::TablReg& tabl_)
    : m_protocol(protocol_), m_tabl(tabl_){};

    void pollingSensors(){
        size_t count = 0;
        while(1){
            m_protocol.process();  
            //std::cout << "\n<------[count] = " << count << "------>\n" << std::endl;
            count++;
        } 
    }
private:
    protocol::Protocol& m_protocol;
    tabl_reg::TablReg& m_tabl;
};
