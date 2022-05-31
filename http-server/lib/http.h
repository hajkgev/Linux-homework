#ifndef HTTP_SERVER_HTTP_H
#define HTTP_SERVER_HTTP_H

#include "../scheduler_lib/scheduler_lib.h"
#include <algorithm>
#include <arpa/inet.h>
#include <cstring>
#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <netdb.h>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <utility>
#include <vector>

#define RESPONSE_400 http::Response("400", "Bad Request")
#define RESPONSE_404 http::Response("404", "Not Found")
#define RESPONSE_411 http::Response("411", "Length Required");
#define RESPONSE_500 http::Response("500", "Internal Server Error")
