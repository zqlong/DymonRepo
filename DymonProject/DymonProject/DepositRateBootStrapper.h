//created by Wang Jianwei on 01 Dec 2012
#ifndef DEPOSITRATEBOOTSTRAPPER_H
#define DEPOSITRATEBOOTSTRAPPER_H
#include <string>
#include "AbstractBootStrapper.h"
#include "cashflow.h"
#include "Enums.h"
#include "currency.h"

using namespace instruments;

namespace utilities {
	class DepositRateBootStrapper: public AbstractBootStrapper{
		
	public:
		
		typedef tuple<date, double> point;

		void init(Configuration* cfg);

		DepositRateBootStrapper(point startPoint, date endDate, cashflow cashFlow, enums::interpolAlgo interpolAlgo,
			enums::NumericAlgo numericAlgo, currency market, double bizDaysAfterSpotRate):AbstractBootStrapper(startPoint, endDate, interpolAlgo, numericAlgo){
			_depositRate = cashFlow.getCouponRate();
			_cashFlow = cashFlow;
			_market = market;
			_bizDaysAfterSpotRate = bizDaysAfterSpotRate;
			_dayCountCash = market.getDayCountCashConvention();
		};
				
		AbstractInterpolator* bootStrap();

		double numericalFunc(double x);

	private:

		double _depositRate;
		currency _market;
		cashflow _cashFlow;
		double _bizDaysAfterSpotRate;
		enums::DayCountEnum _dayCountCash;
	};
}
#endif