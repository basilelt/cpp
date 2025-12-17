#include "TimeSeriesDataset.hpp"
#include <iostream>
#include <numeric>
#include <cmath>

TimeSeriesDataset::TimeSeriesDataset() : TimeSeriesDataset(false, false)
{
}

TimeSeriesDataset::TimeSeriesDataset(bool _znormalize, bool _isTrain) : znormalize(_znormalize), isTrain(_isTrain), maxLength(0), numberOfSamples(0)
{
}

TimeSeriesDataset::TimeSeriesDataset(const TimeSeriesDataset &tsds) : TimeSeriesDataset(tsds.znormalize, tsds.isTrain)
{
    data = tsds.data;
    labels = tsds.labels;
    maxLength = tsds.maxLength;
    numberOfSamples = tsds.numberOfSamples;
}

TimeSeriesDataset::~TimeSeriesDataset()
{
}

TimeSeriesDataset &TimeSeriesDataset::operator=(const TimeSeriesDataset &tsds)
{
    if (&tsds != this)
    {
        znormalize = tsds.znormalize;
        isTrain = tsds.isTrain;
        data = tsds.data;
        labels = tsds.labels;
        maxLength = tsds.maxLength;
        numberOfSamples = tsds.numberOfSamples;
    }
    return *this;
}

bool TimeSeriesDataset::getZnormalize() const
{
    return znormalize;
}

void TimeSeriesDataset::setZnormalize(bool _znormalize)
{
    znormalize = _znormalize;
}

bool TimeSeriesDataset::getIsTrain() const
{
    return isTrain;
}

void TimeSeriesDataset::setIsTrain(bool _isTrain)
{
    isTrain = _isTrain;
}

int TimeSeriesDataset::getMaxLength() const
{
    return maxLength;
}

void TimeSeriesDataset::setMaxLength(int _maxLength)
{
    maxLength = _maxLength;
}

int TimeSeriesDataset::getNumberOfSamples() const
{
    return numberOfSamples;
}

void TimeSeriesDataset::setNumberOfSamples(int _numberOfSamples)
{
    numberOfSamples = _numberOfSamples;
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double> &series, int label)
{
    std::vector<double> normalizedSeries = series;
    if (znormalize && !series.empty())
    {
        double sum = std::accumulate(series.begin(), series.end(), 0.0);
        double mean = sum / series.size();
        double sq_sum = std::inner_product(series.begin(), series.end(), series.begin(), 0.0);
        double stdev = std::sqrt(sq_sum / series.size() - mean * mean);
        if (stdev > 0)
        {
            for (auto &val : normalizedSeries)
            {
                val = (val - mean) / stdev;
            }
        }
    }
    data.push_back(normalizedSeries);
    labels.push_back(label);
    if (normalizedSeries.size() > maxLength)
    {
        maxLength = normalizedSeries.size();
    }
    numberOfSamples++;
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double> &series)
{
    std::vector<double> normalizedSeries = series;
    if (znormalize && !series.empty())
    {
        double sum = std::accumulate(series.begin(), series.end(), 0.0);
        double mean = sum / series.size();
        double sq_sum = std::inner_product(series.begin(), series.end(), series.begin(), 0.0);
        double stdev = std::sqrt(sq_sum / series.size() - mean * mean);
        if (stdev > 0)
        {
            for (auto &val : normalizedSeries)
            {
                val = (val - mean) / stdev;
            }
        }
    }
    data.push_back(normalizedSeries);
    labels.push_back(-1); // dummy label
    if (normalizedSeries.size() > maxLength)
    {
        maxLength = normalizedSeries.size();
    }
    numberOfSamples++;
}

const std::vector<std::vector<double>> &TimeSeriesDataset::getData() const
{
    return data;
}

const std::vector<int> &TimeSeriesDataset::getLabels() const
{
    return labels;
}

std::ostream &TimeSeriesDataset::PrintOn(std::ostream &os) const
{
    os << "TimeSeriesDataset with " << numberOfSamples << " samples, maxLength: " << maxLength << ", znormalize: " << znormalize << ", isTrain: " << isTrain;
    return os;
}