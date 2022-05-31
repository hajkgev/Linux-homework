#include "http_lib/http.h"

struct StaticFile : http::Service {
  std::string content;

  explicit StaticFile(std::string _fileContent)
      : fileContent(std::move(_fileContent)) {}

  http::Response doService(const http::Request &request) final {
    http::Response res;
    res.version = "HTTP/1.0";
    res.headers["Content-Length"] = std::to_string(fileContent.size());
    res.body = fileContent;
    res.statusNumber = std::to_string(200);
    res.statusInfo = "OK";
    return res;
  }
};

struct Upper : http::Service {
 
  }
};

int main(int argc, char *argv[]) {
  
}
