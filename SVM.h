#ifndef SVM_H
#define SVM_H

#include "Packets.h"
#include <vector>

class SVM
{
public:
    SVM(double learning_rate, int epochs, double lambda);
    void train(const std::vector<Packet> &packets);
    bool predict(const Packet &packet) const;

private:
    double learning_rate;
    int epochs;
    double lambda; // Regularization parameter
    std::vector<double> weights;
    double bias;

    std::vector<double> extractFeatures(const Packet &packet) const;
    void normalizeFeatures(std::vector<double> &features) const;

    double max_size;
    double max_arrival_time;
    double max_ratio;
    int max_distance;
};

#endif
