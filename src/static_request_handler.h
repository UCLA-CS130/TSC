#ifndef HTTP_STATIC_REQUEST_HANDLER_H
#define HTTP_STATIC_REQUEST_HANDLER_H

#include <string>
#include <vector>
#include <map>
#include "request_handler.h"

namespace http {
namespace server {
  
/// The common handler for all incoming requests.
class StaticRequestHandler: public RequestHandler
{
 public:
  StaticRequestHandler(const std::vector<std::string>& serve_paths_, 
  					   const std::map<std::string, std::string>& url_root2base_dir_);

  void handle_request(const request& req, reply& rep);

  void handle_request(const std::string req, reply& rep) {};

  bool check_serve_path(std::string uri);

 private:
  std::map<std::string, std::string> uri_root2base_dir; 

  std::vector<std::string> serve_paths;

  std::string extension2type(std::string);
};

} // server
} // http

#endif // HTTP_STATIC_REQUEST_HANDLER_H