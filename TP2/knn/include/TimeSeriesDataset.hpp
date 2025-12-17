#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include "Base.hpp"
#include <vector>

class TimeSeriesDataset : public Base
{
public:
    TimeSeriesDataset();                           /* constructeur par défaut */
    TimeSeriesDataset(bool, bool);                 /* constructeur avec paramètres */
    TimeSeriesDataset(const TimeSeriesDataset &);  /* constructeur de copie */
    virtual ~TimeSeriesDataset();                   /* destructeur */

    virtual TimeSeriesDataset &operator=(const TimeSeriesDataset &); /* opérateur d'affectation */

    virtual bool getZnormalize() const;
    virtual void setZnormalize(bool);
    virtual bool getIsTrain() const;
    virtual void setIsTrain(bool);
    virtual int getMaxLength() const;
    virtual void setMaxLength(int);
    virtual int getNumberOfSamples() const;
    virtual void setNumberOfSamples(int);

    virtual void addTimeSeries(const std::vector<double> &, int);
    virtual void addTimeSeries(const std::vector<double> &);

    virtual const std::vector<std::vector<double>> &getData() const;
    virtual const std::vector<int> &getLabels() const;

    virtual std::ostream &PrintOn(std::ostream &) const override;

private:
    bool znormalize;
    bool isTrain;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    int maxLength;
    int numberOfSamples;
};

#endif /* TimeSeriesDataset_hpp */