#ifndef _JARVIS_
#define _JARVIS_

#include<json/json.h>
#include<iostream>
#include<string>
#include<json/json.h>
#include<sstream>
#include"base/http.h"
#include<fstream>
#include<cstdio>
#include<unistd.h>
#include<fcntl.h>
#include<fstream>
#include<map>
#include<sys/types.h>
#include<sys/stat.h>
#include<memory>


#define ASR "temp_file/asr.wav"

class Util
{
public:
    static bool Exec(std::string command.)
}

class Robot 
{
private:
    std::string url;//对应的url平台
    std::string api_key;//注册对应的api
    std::string user_id;//用户自定义ID
    aip::HttpClient client;//直接调用百度相关接口
private:
    std::string MessageToJson(std::string& message)
    {
        Json::Value root;
        Json::StreamWriterBuilder wb;
        std::ostringstream ss;

        Json::Value item_;
        item_["test"] = message;

        Json::Value item;
        item["inputText"] = item;

        root["reqType"] = 0;
        root["perception"] = item;

        item.clear();
        item["apiKey"] = api_key;
        item["userId"] = user_id;
        root["userInfo"] = item;


        std::unique_ptr<Json::StreamWriter> sw(wb.newStreamWriter());
        sw->write(root, &ss);
        std::string json_string = ss.str();
        std::cout << "debug: " << json_string << std::endl;
        return json_string;
    }
    std::string RequestTL(std::string &request_json)
    {
        std::string response;
        int status_code = client.post(url, nullptr, request_json, nullptr, &response);
        if(status_code != CURLcode::CURLE_OK)
        {
            std::cerr << "post error" << std::endl;
            return "";
        }
        return response;
    }
    std::string JsonToBack(std::string &str)
    {
        JSONCPP_STRING errs;
        Json::Value root;
        Json::CharReaderBuilder rb;
        std::unique_ptr<Json::CharReader> const cr(rb.newCharReader());
        bool res = cr->parse(str.data(), str.data() + str.size(), &root, &errs);
        if(!res || !errs.empty())
        {
            std::cerr << "parse error!" << std::endl;
            
        }
        int code = root["intent"]["code"].asInt();
        if(code == 5000 )
        {
            std::cerr << "response code error" << std::endl;
            return "";
        }
        Json::Value item = root["results"][0];
        std::string msg = item["values"]["test"].asString();
        return msg;
    }
public:
    Robot(std::string id = "1")
    {
        this->url = "http://openapi.tuling123.com/openapi/api/v2";
        this->api_key = "77545728c320448288de0c21f8db99d0";
        this->user_id = id;
    }
    std::string Talk(std::string message)
    {
        std::string json = MessageToJson(message);
        std::string response  = RequestTL(json);
        std::string echo_message = JsonToBack(response);

        return echo_message;
    }
    ~Robot()
    {}
};


class Jarvis
{
private:
    Robot rt;

private；
    bool Record()
    {
        std::string command = "arecord -t wav -c 1 -r 16000 -d 5 -f S16_LE demo.wav";
        command += ASR;
        return Util::Exec(command, false);
    }
public:
    Jarvis()
    {}
    void Run()
    {
        bolatile quit = false;
        while(!quit)
        {
            if(Record())
            {}
        }
        else
        {
            std::err << "Record error..." << std::endl;
        }
    }
    ~Jarvis()
    {}
}




















#endif
