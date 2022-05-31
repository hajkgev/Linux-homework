#include "http.h"

http::Text http::parse(const std::string &str) {
  http::Text http::parse(const std::string &str) {
  http::Text text;
  text.push_back(http::Line());
  bool new_str = true;
  for (char i : str) {
    if (std::isspace(i) == 0) {
      if (new_str) {
        new_str = false;
        text.back().push_back(std::string());
      }
      text.back().back().push_back(i);
    } else {
      new_str = true;
      if (i == '\n') {
        text.push_back(http::Line());
      }
    }
  }
  return text;
}

void http::Server::getHead(int clientSocket, std::string &head,
                           std::string &body) {
  char buff[BUFFER_SIZE];
  bool emptyLineR = false;
  while (!emptyLineR) {
    ssize_t reading = recv(clientSocket, buff, BUFFER_SIZE, 0);
    handle(reading, static_cast<ssize_t>(-1),
           "Couldn't receive a message from a socket!");
    handle(reading, static_cast<ssize_t>(0), "Client Disconnected!", false);
    for (size_t i = 0; i < reading; ++i) {
      if (!emptyLineR && !head.empty() && head.back() == '\n' &&
          buff[i] == '\n') {
        emptyLineR = true;
        continue;
      }
      if (!emptyLineR) {
        // ignore carriage return
        if (buff[i] != 13) {
          head += buff[i];
        }
      } else {
        body += buff[i];
      }
    }
  }
}
int http::Server::parseRequestHead(http::Request &req, const std::string &head) {
