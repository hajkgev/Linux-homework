#include "http_lib/http.h"

struct StaticFile : http::Service {
  std::string content;

  explicit StaticFile(std::string _content)
      : fileContent(std::move(_content)) {}

  http::Response doService(const http::Request &req) final {
    
  }
};

struct Upper : http::Service {
 
  }
};

int main(int argc, char *argv[]) {
  
}
