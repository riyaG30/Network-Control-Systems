#include "Packets.h"
#include "SVM.h"
#include <iostream>
#include <vector>
//! for running
//? first => g++ -std=c++11 -o main main.cpp Packets.cpp SVM.cpp
//? then => ./main
int main()
{
    std::vector<Packet> packets = initializePackets();

    // Separate packets into training and test sets
    std::vector<Packet> training_packets = packets;
    std::vector<Packet> test_packets = packets;

    // Create and train the SVM model
    SVM svm(0.01, 1000, 0.01); // You can adjust learning rate, epochs, and lambda here
    svm.train(training_packets);

    // Test the SVM model on the test_packets
    for (const auto &packet : test_packets)
    {
        bool prediction = svm.predict(packet);
        std::cout << "Prediction for packet (" << packet.size << ", " << packet.arrival_time << "): "
                  << (prediction ? "Periodic" : "Aperiodic") << std::endl;
    }

    return 0;
}
