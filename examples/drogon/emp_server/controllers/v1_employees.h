#pragma once

#include <drogon/HttpController.h>

using namespace drogon;
namespace v1
{
class dataStorage
{
  
  public:
  class users
    {
      public:
      int id;
      std::string name;
      std::string department;
      std::string projectid;
    };
    std::vector<users> vector_of_users;


    dataStorage()
    {
        create_action("Abhilash","SDE","111");
    }

    Json::Value index_action()
    {
      Json::Value final;
      Json::Value temp;
      for (auto i =vector_of_users.begin(); i != vector_of_users.end(); ++i)
      {
        temp["id"]=(*i).id;
        temp["name"]=(*i).name;
        temp["department"]=(*i).department;
        temp["projectID"]=(*i).projectid;
        final.append(temp);
      }
      
      return final;
    }
    Json::Value show_action(int ID)
    {
      Json::Value final;
      for (auto i =vector_of_users.begin(); i != vector_of_users.end(); ++i)
      {
        if((*i).id == ID)
        {
            final["id"]=(*i).id;
            final["name"]=(*i).name;
            final["department"]=(*i).department;
            final["projectID"]=(*i).projectid;
            return final;      
        }
      }
      final["HTTP_response_status_code"]="400";
      final["error"]="User not found";   
      return final;
    }
    Json::Value create_action(std::string Name, std::string Department, std::string ProjectID)
{
      int size_of_vector=vector_of_users.size();
      users u3;
      u3.id=size_of_vector;
      u3.projectid=ProjectID;
      u3.name=Name;
      u3.department=Department;
      vector_of_users.push_back(u3);
      return show_action(u3.id);
    }

  Json::Value update_full_info_action(int ID, std::string Name, std::string Department, std::string ProjectID)
  {
    Json::Value ret;
    if(Name.empty() || Department.empty() || ProjectID.empty())
    {
        ret["error"]="Bad Request - Your request is missing parameters. Please verify and resubmit.";
        ret["HTTP_response_status_code"]="400";
        return ret;
    }
    for (auto i =vector_of_users.begin(); i != vector_of_users.end(); ++i)
      {
        if((*i).id == ID)
        {
          (*i).name=Name;
          (*i).department=Department;
          (*i).projectid=ProjectID;
          break;
        }
      }
      return show_action(ID);
  }

  Json::Value update_some_info_action(int ID, std::string Name, std::string Department, std::string ProjectID)
  {
    Json::Value ret;
    for (auto i =vector_of_users.begin(); i != vector_of_users.end(); ++i)
      {
        if((*i).id == ID)
        {
          if(!Name.empty())
            (*i).name=Name;
          if(!Department.empty())
            (*i).department=Department;
          if(!ProjectID.empty())
            (*i).projectid=ProjectID;
          return show_action(ID);
        }
      }
      ret["error"]="Bad Request - User not found";
      ret["HTTP_response_status_code"]="400";
      return ret;
  }

  Json::Value delete_action(int ID)
    {
      Json::Value final;
      int position;
      for(int i=0; i < vector_of_users.size(); i++)
      {
        if(vector_of_users[i].id== ID)
        {
          position = i;
          vector_of_users.erase(vector_of_users.begin()+position);
          final["Status"]="User deleted";
          return final;
        }
      }
      final["HTTP_response_status_code"]="400";
      final["error"]="User not found";
      return final;
    }
};
class employees : public drogon::HttpController<employees>
{
  public:
    METHOD_LIST_BEGIN
      METHOD_ADD(employees::index, "/", Get);
      METHOD_ADD(employees::getInfo, "/{id}", Get);
      METHOD_ADD(employees::addInfo, "/", Post);
      METHOD_ADD(employees::update_full_info, "/{id}",Put);
      METHOD_ADD(employees::update_some_info,"/{id}",Patch);
      METHOD_ADD(employees::deleteInfo, "/{id}", Delete);

    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(employees::get, "/{2}/{1}", Get); // path is /v1/employees/{arg2}/{arg1}
    // METHOD_ADD(employees::your_method_name, "/{1}/{2}/list", Get); // path is /v1/employees/{arg1}/{arg2}/list
    // ADD_METHOD_TO(employees::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void index(const HttpRequestPtr &req,
                      std::function<void (const HttpResponsePtr &)> &&callback);
    void getInfo(const HttpRequestPtr &req, 
                      std::function<void (const HttpResponsePtr &)> &&callback, int userId);
    void addInfo(const HttpRequestPtr& req,
                      std::function<void (const HttpResponsePtr &)> &&callback);
    void deleteInfo(const HttpRequestPtr &req, 
                      std::function<void (const HttpResponsePtr &)> &&callback, int userId);
    void update_full_info(const HttpRequestPtr &req, 
                      std::function<void (const HttpResponsePtr &)> &&callback, int userId);
    void update_some_info(const HttpRequestPtr &req, 
                      std::function<void (const HttpResponsePtr &)> &&callback, int userId);

};
}
