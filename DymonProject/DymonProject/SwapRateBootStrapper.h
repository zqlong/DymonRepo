//created by Wang Jianwei on 01 Dec 2012
#ifndef SWAPRATEBOOTSTRAPPER_H
#define SWAPRATEBOOTSTRAPPER_H
#include <string>
#include <vector>
#include "AbstractBootStrapper.h"
#include "YieldCurve.h"
#include "Enums.h"

namespace utilities {
	class SwapRateBootStrapper: public AbstractBootStrapper{
		
	public:
		
		typedef tuple<date, double> point;

		typedef double (*targetFuncT) (double d);

		SwapRateBootStrapper(point startPoint, date endDate, double swapRate, vector<date>* timeLine, YieldCurve* curve, AbstractInterpolator::interpolAlgo interpolAlgo,
			AbstractNumerical::NumericAlgo numericAlgo, enums::DayCountEnum dayCount):AbstractBootStrapper(startPoint, endDate, interpolAlgo, numericAlgo){
			_curve = curve;
			_swapRate = swapRate;
			_timeLine = *timeLine;
			_dayCount = dayCount;
		}
				
		AbstractInterpolator* bootStrap();
	
		double numericalFunc(double xVal);

	private:

		YieldCurve* _curve;
		double _swapRate;
		vector<date> _timeLine;
		enums::DayCountEnum _dayCount;

		unsigned int _startIndex;
		unsigned int _endIndex;

		unsigned int findElementIndex(date date0);
	};
}
#endif