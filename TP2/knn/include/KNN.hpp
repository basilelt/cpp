#ifndef KNN_H
#define KNN_H

#include "Base.hpp"
#include "TimeSeriesDataset.hpp"
#include <vector>
#include <string>

class KNN : public Base
{
public:
    KNN();                              /* constructeur par défaut */
    KNN(int, const std::string &);      /* constructeur avec paramètres */
    KNN(const KNN &);                   /* constructeur de copie */
    virtual ~KNN();                     /* destructeur */

    virtual KNN &operator=(const KNN &); /* opérateur d'affectation */

    virtual int getK() const;
    virtual void setK(int);
    virtual std::string getSimilarityMeasure() const;
    virtual void setSimilarityMeasure(const std::string &);

    virtual double evaluate(const TimeSeriesDataset &, const TimeSeriesDataset &, const std::vector<int> &);

    virtual std::ostream &PrintOn(std::ostream &) const override;

private:
    int k;
    std::string similarity_measure;
};

#endif /* KNN_hpp */