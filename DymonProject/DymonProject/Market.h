//created by Hu Kun on 29 Nov 2012

#ifndef Market_H
#define Market_H
#include <tuple>
#include "dateUtil.h"
#include "Enums.h"

namespace instruments {

	class Market {

	public:
		Market(){};
		Market(enums::MarketEnum);
		~Market(){};

		std::string getNameString();
		void display();

		enums::MarketEnum getMarketEnum(){return _marketName;}
		enums::DayCountEnum getDayCountCashConvention(){return _dayCountCashConvention;}
		enums::DayCountEnum getDayCountSwapConvention(){return _dayCountSwapConvention;}
		enums::DayCountEnum getDayCountBondConvention(){return _dayCountBondConvention;}
		enums::DayRollEnum getDayRollCashConvention(){return _dayRollCashConvention;}
		enums::DayRollEnum getDayRollSwapConvention(){return _dayRollSwapConvention;}
		enums::DayRollEnum getDayRollBondConvention(){return _dayRollBondConvention;}
		enums::DayRollEnum getAccrualAdjustCashConvention(){return _accrualAdjustCashConvention;}
		enums::DayRollEnum getAccrualAdjustSwapConvention(){return _accrualAdjustSwapConvention;}
		int getBusinessDaysAfterSpot(){return _businessDaysAfterSpot;}

		void setMarketEnum(enums::MarketEnum marketName){_marketName = marketName;}
		void setDayCountCashConvention(enums::DayCountEnum dayCountCashConvention){_dayCountCashConvention = dayCountCashConvention;}
		void setDayCountSwapConvention(enums::DayCountEnum dayCountSwapConvention){_dayCountSwapConvention = dayCountSwapConvention;}
		void setDayCountBondConvention(enums::DayCountEnum dayCountBondConvention){_dayCountBondConvention = dayCountBondConvention;}
		void setDayRollCashConvention(enums::DayRollEnum dayRollCashConvention){_dayRollCashConvention = dayRollCashConvention;}
		void setDayRollSwapConvention(enums::DayRollEnum dayRollSwapConvention){_dayRollSwapConvention = dayRollSwapConvention;}
		void setDayRollBondConvention(enums::DayRollEnum dayRollBondConvention){_dayRollBondConvention = dayRollBondConvention;}
		void setAccrualAdjustCashConvention(enums::DayRollEnum accrualAdjustCashConvention){_accrualAdjustCashConvention = accrualAdjustCashConvention;}
		void setAccrualAdjustSwapConvention(enums::DayRollEnum accrualAdjustSwapConvention){_accrualAdjustSwapConvention = accrualAdjustSwapConvention;}
		void setBusinessDaysAfterSpot(int businessDaysAfterSpot){_businessDaysAfterSpot =businessDaysAfterSpot;}

	private:
		enums::MarketEnum _marketName;
		enums::DayCountEnum _dayCountCashConvention;
		enums::DayCountEnum _dayCountSwapConvention;
		enums::DayCountEnum _dayCountBondConvention;
		enums::DayRollEnum _dayRollCashConvention;
		enums::DayRollEnum _dayRollSwapConvention;
		enums::DayRollEnum _dayRollBondConvention;
		enums::DayRollEnum _accrualAdjustCashConvention;
		enums::DayRollEnum _accrualAdjustSwapConvention;
		int _businessDaysAfterSpot;
	};

}
#endif