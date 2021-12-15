#include "pch.h"
#include "CppUnitTest.h"
#include"\User\Desktop\ConsoleApplication1\ConsoleApplication1\processing.h"
#include"\User\Desktop\ConsoleApplication1\ConsoleApplication1\wind_rose.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	wind_rose* build_subscription(double speed_sr)
	{
		wind_rose* rose = new wind_rose;
		
		rose->speed = speed_sr;
		return rose;
	}

	//       
	void delete_subscription(wind_rose* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}


	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(TestMethod2) //        
		{
			//тест для первого месяца
			wind_rose* roses[2];
			roses[0] = build_subscription( 3.3 );  
			roses[1] = build_subscription(4.3);  
			Assert::AreEqual(3.8, process(roses, 2, 1));
			delete_subscription(roses, 2);
		}
		TEST_METHOD(TestMethod3) //        
		{
			//тест для 2ого месяца
			wind_rose* roses[2];
			roses[0] = build_subscription(7.3);
			roses[1] = build_subscription(15.3);
			Assert::AreEqual(11.3, process(roses, 2, 2));
			delete_subscription(roses, 2);
		}
		TEST_METHOD(TestMethod4) //        
		{
			//тест для 3ого месяца
			wind_rose* roses[2];
			roses[0] = build_subscription(6.3);
			roses[1] = build_subscription(2.3);
			Assert::AreEqual(4.3, process(roses, 2, 3));
			delete_subscription(roses, 2);
		}
	};
}
