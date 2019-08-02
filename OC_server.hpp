#include<iostream>
#include"mongoose.h"
#include"Util.hpp"

struct mg_serve_http_opts http_opts;
class OC_server
{
private:
    string port;
    struct mg_mgr mgr;
    struct mg_connection* nc;

public:
    static void ev_handler(struct mg_connection* nc, int ev, void* ev_data)
    {
        switch(ev)
        {
            case MG_EV_WEBSOCKET_HANDSHAKE_DONE:
            {
                
            }
        }
    }

    
    OC_server(string _port = 8080)
        :port(_port)
    {
        mg_mgr_init(&mgr, NULL);
        nc = mg_bind(&mgr, port.c_str(), ev_handler);
        mg_set_protocol_http_websocket(nc);
        s_http_server_opts.document_root = ".";
        s_http_server_opts.enable_directory_listing = "yes";
        
        while(s_signal_recevied == 0)
        {
            mg_mgr_poll(&mgr, 200);
        }
        mg_mgr_free(&mgr);
    }


  
};
