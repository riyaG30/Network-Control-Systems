#include "Packets.h"
#include <vector>

std::vector<Packet> initializePackets()
{
    std::vector<Packet> DataPackets;
    DataPackets.push_back({100, 0.0, 1, 2, true});
    DataPackets.push_back({150, 0.1, 1, 3, false});
    DataPackets.push_back({200, 0.2, 2, 3, true});
    DataPackets.push_back({250, 0.3, 3, 4, false});
    DataPackets.push_back({300, 0.4, 4, 5, true});
    DataPackets.push_back({350, 0.5, 5, 6, false});
    DataPackets.push_back({400, 0.6, 6, 7, true});
    DataPackets.push_back({450, 0.7, 7, 8, false});
    DataPackets.push_back({500, 0.8, 8, 9, true});
    DataPackets.push_back({550, 0.9, 9, 10, false});
    DataPackets.push_back({600, 1.0, 10, 11, true});
    DataPackets.push_back({650, 1.1, 11, 12, false});
    DataPackets.push_back({700, 1.2, 12, 13, true});
    DataPackets.push_back({750, 1.3, 13, 14, false});
    DataPackets.push_back({800, 1.4, 14, 15, true});
    DataPackets.push_back({850, 1.5, 15, 16, false});
    DataPackets.push_back({900, 1.6, 16, 17, true});
    DataPackets.push_back({950, 1.7, 17, 18, false});
    DataPackets.push_back({1000, 1.8, 18, 19, true});
    DataPackets.push_back({1050, 1.9, 19, 20, false});
    DataPackets.push_back({1100, 2.0, 20, 21, true});
    DataPackets.push_back({1150, 2.1, 21, 22, false});
    DataPackets.push_back({1200, 2.2, 22, 23, true});
    DataPackets.push_back({1250, 2.3, 23, 24, false});
    DataPackets.push_back({1300, 2.4, 24, 25, true});

    return DataPackets;
}
