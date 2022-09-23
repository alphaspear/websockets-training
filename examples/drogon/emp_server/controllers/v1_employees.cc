#include "v1_employees.h"
#include <string>
#include<vector>
#include <algorithm>
#include<jsoncpp/json/json.h>
#include<jsoncpp/json/value.h>

using namespace v1;
dataStorage ds;
// Add definition of your processing function here

void employees::index(const HttpRequestPtr &req,
                   std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value ret;
    ret=ds.index_action();
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void employees::getInfo(const HttpRequestPtr &req, 
                      std::function<void(const HttpResponsePtr &)> &&callback, int userId)
{
    Json::Value ret;
    ret=ds.show_action(userId);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp); 
}

void employees::addInfo(const HttpRequestPtr& req,
                      std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto json=req->getJsonObject();
    Json::Value ret;
    std::string name = (*json)["name"].asString();
    std::string department = (*json)["department"].asString();
    std::string projectID = (*json)["projectID"].asString();
    if(name.empty() || department.empty() || projectID.empty())
    {
        ret["error"]="Bad Request - Your request is missing parameters. Please verify and resubmit.";
    }
    else
    {
        ret=ds.create_action(name,department,projectID);
    }
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp); 
}

void employees::deleteInfo(const HttpRequestPtr &req,
                      std::function<void (const HttpResponsePtr &)> &&callback, int userId)
{
    Json::Value ret;
    ret=ds.delete_action(userId);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    //std::cout<<ret;
    callback(resp); 
}

void employees::update_full_info(const HttpRequestPtr &req, 
                      std::function<void (const HttpResponsePtr &)> &&callback, int userId)
{

    auto json=req->getJsonObject();
    Json::Value ret;
    std::string name = (*json)["name"].asString();
    std::string department = (*json)["department"].asString();
    std::string projectID = (*json)["projectID"].asString();
    ret=ds.update_full_info_action(userId,name,department,projectID);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    //resp->setStatusCode(HttpStatusCode::k502BadGateway);
    callback(resp); 
}


void employees::update_some_info(const HttpRequestPtr &req, 
                       std::function<void (const HttpResponsePtr &)> &&callback, int userId)
{
    auto json=req->getJsonObject();
    Json::Value ret;
    std::string name = (*json)["name"].asString();
    std::string department = (*json)["department"].asString();
    std::string projectID = (*json)["projectID"].asString();
    ret=ds.update_some_info_action(userId,name,department,projectID);
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    //resp->setStatusCode(HttpStatusCode::k502BadGateway);
    callback(resp); 
}