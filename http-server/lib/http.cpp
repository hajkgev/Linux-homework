#include "http.h"

http::Text http::parse(const std::string &str) {
  http::Text text;
  text.push_back(http::Line());
  
  return text;
}

void http::Server::getHead(int clientSocket, std::string &head,
                           std::string &body) {
 
}

int http::Server::parseRequestHead(http::Request &req, const std::string &head) {
