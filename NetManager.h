#ifndef NETMANAGER_H_
#define NETMANAGER_H_

#include <unordered_map>
#include <SDL_net.h>
#include "Packet.h"
#include "NetUpdate.h"

class NetManager
{
    private:
        IPaddress ip;
        TCPsocket server;
        std::unordered_map<int, TCPsocket> clients;
        SDLNet_SocketSet socket_set;
        bool isServer;
        bool isRunning;
        int nextClientId;

        std::vector<int> queuedDisconnects;

        std::unordered_map<int, TCPsocket>::iterator messageSingleClient(std::unordered_map<int, TCPsocket>::iterator iter, const Packet &p);

        void serverGetData(NetUpdate& update);
        void clientGetData(NetUpdate& update);

    public:
        NetManager();
        ~NetManager();

        void startServer();
        void startClient(char* host);
        int numClients() const;

        void messageServer(const Packet& p);
        void messageClients(const Packet& p);
        void messageClient(int clientId, const Packet& p);
        NetUpdate checkForUpdates();
};

#endif /* NETMANAGER_H_ */
