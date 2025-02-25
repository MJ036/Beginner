#include "String.h"
// Test reference to http://coolshell.cn/articles/10478.html

void foo(String x)
{
	std::cout << x.c_str() << std::endl;
}

void bar(const String& x)
{
	std::cout << x.c_str() << std::endl;
}

String baz()
{
	String ret("world");
	return ret;
}

void test(){

	char text[] = "world";

    cout << "s0" << endl;
	String s0;
    cout << "s1" << endl;
	String s1("hello");
    cout << "s2" << endl;
	String s2(s0);
    cout << "s3" << endl;
	String s3 = s1;
    cout << "s4" << endl;
	String s4(text);
    cout << " = " << endl;
	s2 = s1;

    cout << "foo" << endl;
	foo(s1);
    cout << "bar" << endl;
	bar(s1);
    cout << "foo(tem)" << endl;
	foo("temporary");
    cout << "bar(tem)" << endl;
	bar("temporary");
	String s5 = baz();

	std::vector<String> svec;
	svec.reserve(8);
    cout << "s0" << endl;
	svec.push_back(std::move(s0));
    cout << "s1" << endl;
	svec.push_back(s1);
	svec.push_back(s2);
	svec.push_back(s3);
	svec.push_back(s4);
	svec.push_back(s5);
	svec.push_back(baz());
    cout << "good" << endl;
	svec.push_back("good job");

	for (const auto &s : svec)
	{
		std::cout << s.c_str() << std::endl;
	}
}

int main()
{
    test();
//    String str1("mai jia bao");
//    String str2 = str1;
//    String str3;
//    str3 = str1;

    return 0;
}

