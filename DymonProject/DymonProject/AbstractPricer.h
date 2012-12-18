//created by Hu Kun on 16 Dec 2012
#ifndef ABSTRACTPRICER_H
#define ABSTRACTPRICER_H
#include "currency.h"
#include "date.h"
#include <vector>
#include <tuple>
#include <map>
#include "YieldCurve.h"

using namespace std;
using namespace instruments;
using namespace utilities;

namespace instruments {
	//tuple<date,double>
	typedef tuple<date,double> PV;
	//typedef map<tuple<date,date>,double> FWDR;

	//map<tuple<tenorNumofMonths,delta>, volatility>
	typedef map<tuple<double,double>,double> volSurfacePoint;
	
	class AbstractPricer {
	
	public:
		//base class for all other instruments to be derived from
		AbstractPricer(){};
		~AbstractPricer(){};
		
		
		template <class T, class P> double getMPV(T aInstrument,YieldCurve curve);
		
		
		template <class T, class P> vector<PV> getPVLeg(T aInstrument,YieldCurve curve, int fixOrFloating);
		

	protected: 

		
	};
}
#endif