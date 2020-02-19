#include "deque.h"
#include <deque>
#include <string>
#include <iostream>


class test
{
private:
	int k; 
public:
	test()
	{
		std::cout << "this is default constructor" << std::endl;
		k = 0; 
		kek = 0;
	}
	test(const test& t)
	{
		std::cout << "this is copy constructor" << std::endl;
		kek = t.kek;
	}
	test(int kek) : kek(kek)
	{
		std::cout << "this is consrtuctor with kek" << std::endl;
		k = 1;
	}
	test(int kek, int a) : kek(kek)
	{
		std::cout << "this is consrtuctor with kek" << std::endl;
	}
	~test()
	{
		std::cout << "this is destructor" << std::endl;
		if (k == 1)
			std::cout << "(cons with kek)" << std::endl;

		if (k == 0)
			std::cout << "(cons with def)" << std::endl;
	}
	int getSomeKek()
	{
		return kek;
	}
private:
	int kek;
};

void stdDeq()
{

	/*std::deque::deque<std::string> deqStd;
	deqStd.push_back( "abcd0" );
	deqStd.push_back( "abcd1" );
	deqStd.push_back( "abcd2" );


	itStd--;
	deqStd.push_back( "abcd3" );
	deqStd.push_back( "abcd4" );

	std::cout << *itStd << std::endl;
	std::cout << " hello " << std::endl; */

	std::deque<std::string> deqStd;
	deqStd.push_back("abcd0");
	deqStd.push_back("abcd1");
	deqStd.push_back("abcd2");
	deqStd.push_back("abcd3");
	deqStd.push_back("abcd4");
	deqStd.push_back("abcd5");

	//deqStd.erase(deqStd.end());
	//deqStd.erase( deqStd.end(), deqStd.begin() );
	//std::cout << *( deqStd.begin() + 3 ) << std::endl; 
	//std::cout << *( deqStd.erase( deqStd.begin(), deqStd.begin() + 3 ) ) << std::endl;

	std::deque<std::string> deqStd1;
	deqStd1.push_back("Anotherabcd0");
	deqStd1.push_back("Anotherabcd1");
	deqStd1.push_back("Anotherabcd2");
	deqStd1.push_back("Anotherabcd3");
	deqStd1.push_back("Anotherabcd4");
	deqStd1.push_back("Anotherabcd5");

	std::deque<std::string>::iterator it1 = deqStd.begin();
	std::deque<std::string>::iterator it2 = deqStd1.begin();

	std::cout << *it1 << std::endl;
	deqStd.swap(deqStd1);
	std::cout << *it1 << std::endl;

	//std::deque::deque<std::string>::iterator itStd = deqStd.begin();
	//std::deque::deque<std::string>::iterator itStd1 = deqStd.begin();

	//*itStd = "abc3d";
	//std::cout << itStd [ 0 ] << std::endl;

	//deqStd [ 0 ];
	//  int i = itStd + itStd1;

}

void test1()
{
	mydeque::deque<std::string> deq;
	deq.push_back("abcd");
	deq.push_back("abcd");
	deq.push_back("abcd");
	deq.push_back("abcd");
	deq.push_front("abcd");
	deq.push_front("abcd");
	deq.push_front("abcd");
	deq.push_front("abcd");
	deq.pop_back();
	deq.pop_back();
	deq.pop_back();
	deq.pop_back();
	deq.pop_back();
	deq.pop_front();
	deq.pop_front();
	deq.pop_back();
	deq.pop_back();
	deq.pop_back();
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");
	deq.push_back("abcd6");
	deq.push_back("abcd7");
	deq.push_back("abcd8");
	std::cout << deq.size();
}

void test2()
{
	//*
	//bool
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");
	deq.push_back("abcd6");
	deq.push_back("abcd7");
	deq.push_back("abcd8");

	mydeque::deque<std::string>::iterator it = deq.begin();
	std::cout << *it << std::endl;


	mydeque::deque<std::string>::iterator it1;
	if (it1)
		std::cout << "here" << std::endl;
	else
		std::cout << "here too" << std::endl;
}

void test3()
{
	//++
	//!= 
	//end()
	//exc
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");
	deq.push_back("abcd6");
	deq.push_back("abcd7");
	deq.push_back("abcd8");

	mydeque::deque<std::string>::iterator it;

	for (it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << std::endl;

	try
	{
		std::cout << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void test4()
{
	//==
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	mydeque::deque<std::string>::iterator it = deq.begin();
	it++;

	mydeque::deque<std::string>::iterator it1 = deq.begin();
	if (it == it1)
		std::cout << "okay" << std::endl;
	else
		std::cout << "not okay" << std::endl;

	if (it < it1)
		std::cout << "it less" << std::endl;
	else
		std::cout << "it not less" << std::endl;


	it1++;
	if (it == it1)
		std::cout << "okay" << std::endl;
	else
		std::cout << "not okay" << std::endl;
}

void test5()
{
	//<
	//>
	//<=
	//>=
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");

	mydeque::deque<std::string>::iterator it1 = deq.begin();
	mydeque::deque<std::string>::iterator it2 = deq.begin();
	it2++;

	mydeque::deque<std::string>::iterator it3 = deq.begin();


	if (it1 == it3)
		std::cout << "== ok" << std::endl;

	if (it1 < it2)
		std::cout << "< ok" << std::endl;

	if (it2 > it1)
		std::cout << "> ok" << std::endl;

	if (it1 <= it2 && it3 <= it1)
		std::cout << "<= ok" << std::endl;

	if (it2 >= it1 && it3 >= it1)
		std::cout << ">= ok" << std::endl;

}

void test6()
{

	/*
	//+=
	//-=
	//+
	//-

	mydeque::deque<std::string> deq;
	deq.push_back( "abcd0" );
	deq.push_back( "abcd1" );
	deq.push_back( "abcd2" );
	deq.push_back( "abcd3" );
	deq.push_back( "abcd4" );
	deq.push_back( "abcd5" );

	mydeque::deque<std::string>::iterator it = deq.begin();

	mydeque::deque<std::string>::iterator it1 = it + 5;

	std::cout << *it1 << std::endl;


	std::cout << *it1 << std::endl;
	*/
}

void test7()
{
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");

	mydeque::deque<std::string>::iterator it1 = deq.begin();

	mydeque::deque<std::string>::iterator it2 = deq.end();
	it2 += -1;
	std::cout << it2 - it1 << std::endl;
}

void test8()
{
	// []
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");

	mydeque::deque<std::string>::iterator it1 = deq.begin();

	std::cout << *it1 << std::endl;

	it1[3] = "lolkek";
	std::cout << *(it1 + 3) << std::endl;


	mydeque::deque<int> deqInt;
	deqInt.push_back(1);
	deqInt.push_back(2);
	deqInt.push_back(3);
	deqInt.push_back(4);
	deqInt.push_back(5);
	mydeque::deque<int>::iterator it2 = deqInt.begin();
	it2[0] = 20;
	std::cout << *it2 << std::endl;

}

void test9()
{
	//insert
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");

	mydeque::deque<std::string>::iterator it1 = deq.begin();
	it1 = deq.insert(it1, "abcd00");
	it1 = deq.insert(it1, "abcd-1");
	it1 = deq.insert(it1, "abcd-2");
	it1 = deq.insert(it1, "abcd-3");
	it1 = deq.insert(it1, "abcd-4");
	it1 += 4;
	it1 = deq.insert(it1, "abcd-5");

	it1 = deq.insert(it1, 3, "nineteensixtysixteen");

	std::cout << std::endl;
	it1--;
	for (int i = 0; i < 5; i++)
	{
		std::cout << *it1 << std::endl;
		it1++;
	}
	std::cout << std::endl;


	for (mydeque::deque<std::string>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	/*
	mydeque::deque<std::string>::iterator it2 = deq.end();

	try
	{
	it2 = deq.insert(it2, "abcd00");
	}
	catch (std::exception& e)
	{
	std::cout << e.what() << std::endl;
	}
	*/
}

void test10()
{
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	mydeque::deque<std::string>::iterator it1 = deq.begin();

	/*it1 = deq.erase(it1);
	it1 = deq.erase(it1);
	it1 = deq.erase(it1);
	it1 = deq.erase(it1);
	it1 = deq.erase(it1); */

	std::cout << '\n' << std::endl;
	std::cout << *it1 << std::endl;
	std::cout << '\n' << std::endl;
	std::cout << '\n' << std::endl;
	for (mydeque::deque<std::string>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

void test11()
{

	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	mydeque::deque<std::string>::iterator it1 = deq.begin();
	it1++;
	mydeque::deque<std::string>::iterator it2 = deq.end();
	std::cout << *it1 << std::endl;

	mydeque::deque<std::string>::iterator it3 = deq.end();
	if (it2 >= it3)
		std::cout << "here" << std::endl;
}

void test12()
{
	//center 
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");
	deq.push_back("abcd6");

	mydeque::deque<std::string>::iterator it1 = deq.begin();
	mydeque::deque<std::string>::iterator it2 = it1 + 3;


	std::cout << *deq.erase(deq.begin(), deq.begin()) << std::endl << std::endl;
	/* try
	{
	deq.erase( deq.end(), deq.begin() );
	}
	catch ( std::exception& e )
	{
	std::cout << e.what() << std::endl;
	} */

	std::cout << *deq.begin() << std::endl;
	std::cout << deq.size() << std::endl;
	for (mydeque::deque<std::string>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

void test13()
{
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");
	deq.push_back("abcd6");

	deq.resize(0); int i = 1;
	deq.resize(10);

	std::cout << "here" << std::endl;
	deq.resize(0);
	deq.resize(10, "abracadabra");
	for (mydeque::deque<std::string>::iterator it = deq.begin(); it != deq.end(); it++, i++)
	{
		std::cout << i << " " << *it << std::endl;
	}
}

void test14()
{
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");

	mydeque::deque<std::string> deq1;
	deq1.push_back("AnotherAbcd0");
	deq1.push_back("AnotherAbcd1");
	deq1.push_back("AnotherAbcd2");

	mydeque::deque<std::string>::iterator it = deq.begin();
	mydeque::deque<std::string>::iterator it1 = deq1.begin();

	std::cout << *it << std::endl;
	deq.swap(deq1);
	std::cout << *it << std::endl;

	for (mydeque::deque<std::string>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

void test15()
{
	mydeque::deque<test> deq;
	//deq.push_back( test() );

	//deq.push_back(test(2));
	deq.emplace_back(2);
	//deq.emplace_front(1);

	/*
	deq.emplace(deq.begin() + 1, 10);

	for (mydeque::deque<test>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << (*it).getSomeKek() << std::endl;
	}*/
}

void test16()
{
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");

	mydeque::deque<std::string>::iterator it = deq.begin();
	mydeque::deque<std::string>::iterator it1 = it;
	mydeque::deque<std::string>::iterator it2(it1);

	std::cout << *it << std::endl;
	std::cout << *it1 << std::endl;
	std::cout << *it2 << std::endl;

}

void test17()
{
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");
	deq.push_back("abcd5");


	mydeque::front_insert_iterator<mydeque::deque<std::string>> it(deq);

	it = "abcd-1";
	it = "abcd-2";
	it = "abcd-3";
	it = "abcd-4";
	it = "abcd-5";
	it = "abcd-6";

	for (mydeque::deque<std::string>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	//mydeque::deque<std::string>::input_iterator it = deq.begin();
	//mydeque::deque<std::string>::input_iterator it1 = it;
}

void test18()
{
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");

	deq.assign(4, "lolkek");

	for (mydeque::deque<std::string>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << *it << std::endl;
	}

}

void test19()
{
	mydeque::deque<std::string> deq;
	deq.push_back("abcd0");
	deq.push_back("abcd1");
	deq.push_back("abcd2");
	deq.push_back("abcd3");
	deq.push_back("abcd4");

	std::cout << deq.at(4) << std::endl;
	std::cout << deq[4] << std::endl;
	std::cout << deq.front() << std::endl;
	std::cout << deq.back() << std::endl;
}

void test20()
{
	mydeque::deque<std::string> deq(4, "lolkek");
	mydeque::deque<std::string> deq1 = deq;

	std::cout << deq.size() << std::endl;
	for (mydeque::deque<std::string>::iterator it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "here" << std::endl;
	mydeque::deque<std::string> deq3(deq);
	for (mydeque::deque<std::string>::iterator it = deq3.begin(); it != deq3.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	mydeque::deque<std::string> deq4 = deq;
	std::cout << "here" << std::endl;

	for (mydeque::deque<std::string>::iterator it = deq4.begin(); it != deq4.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	if (deq3 == deq)
		std::cout << "equal" << std::endl;
	else
		std::cout << "not equal" << std::endl;

	deq.push_back("lo");

	if (deq3 == deq)
		std::cout << "equal" << std::endl;
	else
		std::cout << "not equal" << std::endl;

	if (deq3 != deq)
		std::cout << "not equal" << std::endl;
	else
		std::cout << "equal" << std::endl;
}

void testN()
{
	mydeque::deque<test> deq; 
	//deq.push_back(test(4));

	deq.emplace_back(4);
	std::cout << "here" << std::endl; 
}

int main()
{
	//int a = 4; 
	//int b = 4; 
	//int c = 4; 
	//int d = 4; 

	// if (a == (b == (c == d)))
	//std::cout << "lol" << std::endl; 
	//stdDeq();
	//test2();
	//test3();
	//test4();
	//test6();
	//test8();
	//test10();
	//test11(); 

	//test12();
	//test13();
	//test14();
	//test15();
	//test17();
	//test18();
	//test20();
	testN();
	system("pause");
}