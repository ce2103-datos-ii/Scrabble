//
// Created by ivan on 4/7/19.
//

#ifndef SCRABBLE_COMMUNICATION_H
#define SCRABBLE_COMMUNICATION_H

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

class Communication {

public:
    int connection(int socket);
};


#endif //SCRABBLE_COMMUNICATION_H
