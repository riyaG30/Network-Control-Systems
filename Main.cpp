#include "Packets.h"
#include "SVM.h"
#include <iostream>

void visualizeData(const std::vector<Packet> &packets)
{
    int periodic_count = 0;
    int aperiodic_count = 0;

    for (const auto &packet : packets)
    {
        if (packet.is_periodic)
        {
            periodic_count++;
        }
        else
        {
            aperiodic_count++;
        }
    }

    std::cout << "Periodic packets: " << std::string(periodic_count, '*') << " (" << periodic_count << ")\n";
    std::cout << "Aperiodic packets: " << std::string(aperiodic_count, '*') << " (" << aperiodic_count << ")\n";
}

int main()
{
    // Initialize packets
    std::vector<Packet> packets = initializePackets();

    // Visualize data
    visualizeData(packets);

    // Train SVM
    double learning_rate = 0.01;
    int epochs = 5000;
    double lambda = 0.01;

    SVM svm(learning_rate, epochs, lambda);
    svm.train(packets);

    // Test the classifier with various packets
    Packet test_packet1 = {150, 0.1, 1, 3, false};   // Should be predicted as Aperiodic
    Packet test_packet2 = {300, 0.4, 4, 5, true};    // Should be predicted as Periodic
    Packet test_packet3 = {850, 1.5, 15, 16, false}; // Should be predicted as Aperiodic
    Packet test_packet4 = {1300, 2.4, 24, 25, true}; // Should be predicted as Periodic

    std::vector<Packet> test_packets = {test_packet1, test_packet2, test_packet3, test_packet4};

    for (const auto &packet : test_packets)
    {
        bool prediction = svm.predict(packet);
        std::cout << "Prediction for test packet (" << packet.size << ", " << packet.arrival_time << "): "
                  << (prediction ? "Periodic" : "Aperiodic") << std::endl;
    }

    return 0;
}
