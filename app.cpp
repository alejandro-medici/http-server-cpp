// main.cc 
#include <lithium_http_server.hh>
#include <lithium_json.hh>

#ifndef LI_SYMBOL_my_param
#define LI_SYMBOL_my_param
  LI_SYMBOL(my_param)
#endif

int main() {
  li::http_api my_api;

  my_api.get("/hello_world") =  [&](li::http_request& request, li::http_response& response) {
    auto param = request.get_parameters(s::my_param = std::optional<int>());
    response.write("Hello from C++ Server");
  };
  
  li::http_serve(my_api, 8080);
}