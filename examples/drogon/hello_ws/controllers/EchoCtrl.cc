#include <iostream>
#include "EchoCtrl.h"

void EchoCtrl::handleNewMessage(const WebSocketConnectionPtr& wsConnPtr, std::string &&message, const WebSocketMessageType &type)
{
    // write your application logic here
    wsConnPtr->send(message);
}

void EchoCtrl::handleNewConnection(const HttpRequestPtr &req, const WebSocketConnectionPtr& wsConnPtr)
{
    // write your application logic here
    std::cout << "New connection request!\n";
    // cout << wsConnPtr
}

void EchoCtrl::handleConnectionClosed(const WebSocketConnectionPtr& wsConnPtr)
{
    // write your application logic here
}
