//created by Wang Jianwei on 01 Dec 2012
#ifndef LINEARINTERPOLATOR_H
#define LINEARINTERPOLATOR_H
#include "AbstractInterpolator.h"
#include "Constants.h"

namespace utilities{	

	template<typename T> class LinearInterpolator: public AbstractInterpolator<T>{
		
	typedef tuple<T, double> point;

	public:

		LinearInterpolator(point startPoint, point endPoint):AbstractInterpolator(startPoint, endPoint){
			_b0 = NaN;
			_b1 = NaN;
			_b2 = NaN;
			_algo = enums::QUADRATIC;
		}

		virtual point interpolate(T xVal){
			xValInRangeCheck(xVal);
			if (_b0 == NaN || _b1 == NaN || _b2 == NaN){
				throw "Parameters not initialized!";
			}
			double yVal = _b0 + _b1 * xVal + _b2 * xVal^2;
			return point(xVal, yVal);
		}

		void setB0(double b0){_b0=b0);
		void setB1(double b1){_b1=b1);
		void setB2(double b2){_b2=b2);

	private:

		double _b0;
		double _b1;
		double _b2;
	};
}
#endif