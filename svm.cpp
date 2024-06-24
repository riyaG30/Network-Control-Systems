#include "SVM.h"
#include <cmath>
#include <iostream>

SVM::SVM(double learning_rate, int epochs, double lambda)
    : learning_rate(learning_rate), epochs(epochs), lambda(lambda), bias(0.0),
      max_size(0.0), max_arrival_time(0.0), max_ratio(0.0), max_distance(0)
{
    weights = std::vector<double>(4, 0.0); // Initialize weights to zero (4 features now)
}

std::vector<double> SVM::extractFeatures(const Packet &packet) const
{
    double ratio = static_cast<double>(packet.size) / (packet.arrival_time + 1e-5); // Prevent division by zero
    int distance = std::abs(packet.destination - packet.source);
    return {static_cast<double>(packet.size), packet.arrival_time, ratio, static_cast<double>(distance)};
}

void SVM::normalizeFeatures(std::vector<double> &features) const
{
    features[0] /= max_size;
    features[1] /= max_arrival_time;
    features[2] /= max_ratio;
    features[3] /= max_distance;
}

void SVM::train(const std::vector<Packet> &packets)
{
    // Find max values for normalization
    for (const auto &packet : packets)
    {
        if (packet.size > max_size)
        {
            max_size = packet.size;
        }
        if (packet.arrival_time > max_arrival_time)
        {
            max_arrival_time = packet.arrival_time;
        }
        double ratio = static_cast<double>(packet.size) / (packet.arrival_time + 1e-5);
        if (ratio > max_ratio)
        {
            max_ratio = ratio;
        }
        int distance = std::abs(packet.destination - packet.source);
        if (distance > max_distance)
        {
            max_distance = distance;
        }
    }

    for (int epoch = 0; epoch < epochs; ++epoch)
    {
        for (const auto &packet : packets)
        {
            std::vector<double> features = extractFeatures(packet);
            normalizeFeatures(features);
            double label = packet.is_periodic ? 1.0 : -1.0;

            double linear_output = bias;
            for (size_t i = 0; i < weights.size(); ++i)
            {
                linear_output += weights[i] * features[i];
            }

            if (label * linear_output < 1)
            {
                for (size_t i = 0; i < weights.size(); ++i)
                {
                    weights[i] = (1 - learning_rate * lambda) * weights[i] + learning_rate * label * features[i];
                }
                bias += learning_rate * label;
            }
            else
            {
                for (size_t i = 0; i < weights.size(); ++i)
                {
                    weights[i] = (1 - learning_rate * lambda) * weights[i];
                }
            }
        }
    }
}

bool SVM::predict(const Packet &packet) const
{
    std::vector<double> features = extractFeatures(packet);
    normalizeFeatures(features);
    double linear_output = bias;
    for (size_t i = 0; i < weights.size(); ++i)
    {
        linear_output += weights[i] * features[i];
    }
    return linear_output >= 0;
}
