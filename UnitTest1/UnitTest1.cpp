#include "pch.h"
#include "CppUnitTest.h"
#include "../PRR_12.6/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Queue q;
			q.enqueue("one");
			q.enqueue("two");
			q.enqueue("three");
			q.invertQueue();
			std::string expected = "three two one \n";
			std::stringstream ss;
			std::streambuf* old = std::cout.rdbuf(ss.rdbuf());
			q.printQueue();
			std::string actual = ss.str();
			std::cout.rdbuf(old);
			Assert::AreEqual(expected, actual);
		}
	};
}
