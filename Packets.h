#ifndef PACKETS_H
#define PACKETS_H

#include <vector>

struct Packet
{
    int size;
    double arrival_time;
    int source, destination;
    bool is_periodic;
};
std::vector<Packet> initializePackets();

#endif
