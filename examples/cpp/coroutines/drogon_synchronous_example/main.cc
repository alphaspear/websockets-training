#include <drogon/drogon.h>
#include <future>
#include <iostream>
#include<thread>
#include <mutex>


using namespace drogon;


void fun()
{

    auto client = HttpClient::newHttpClient("http://www.google.com");
    auto req = HttpRequest::newHttpRequest();
    std::pair<drogon::ReqResult, std::shared_ptr<drogon::HttpResponse>> return_pair;
    req->setMethod(drogon::Get);
    req->setPath("/");
    req->setParameter("wd", "wx");
    req->setParameter("oq", "wx");
    std::cout << "Sending request " << std::endl;
        return_pair = client->sendRequest(req);
        auto resp = return_pair.second;
        std::cout<<resp->getStatusCode()<<std::endl;
    std::cout << "Completed request"<<std::endl;
}

int main()
{
    std::thread t(fun);
    
    app().run();
}
