#include "v1_employees.h"

using namespace v1;

// Add definition of your processing function here

void employees::index(const HttpRequestPtr &req,
                   std::function<void (const HttpResponsePtr &)> &&callback)
{

    //Verify the validity of the token, etc.
    //Read the database or cache to get user information
    Json::Value ret;

    ret["result"]="ok";
    ret["user_name"]="Jack";

    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
