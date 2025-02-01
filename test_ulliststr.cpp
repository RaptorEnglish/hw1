#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

ULListStr * make_list(std::vector<std::string> const & values, bool pushBack)
{
	// circular list is not copyable so we have to pass it by pointer
	ULListStr * list = new ULListStr();

	if(pushBack)
	{
		for(std::vector<std::string>::const_iterator valuesIter = values.cbegin(); valuesIter != values.cend(); ++valuesIter)
		{
			list->push_back(*valuesIter);
		}
	}
	else
	{
		// push values in reverse from the front
		for(std::vector<std::string>::const_reverse_iterator valuesIter = values.crbegin(); valuesIter != values.crend(); ++valuesIter)
		{
			list->push_front(*valuesIter);
		}
	}

	return list;
}


int main(int argc, char* argv[])
{

  std::vector<std::string> content = {"sup", "er", "cal", "i", "frag", "il", "ist", "ic", "exp", "i", "alo", "doc", "ious"};

	ULListStr * list = make_list(content, false);

  // list->print_head();
  std::cout <<list->back()<<std::endl;

	

  // ULListStr dat;
  // dat.push_front("7");
  // dat.push_front("9");
  // dat.push_front("71");
  // dat.push_front("7");
  // dat.push_front("9");
  // dat.push_front("71");
  // dat.push_front("7");
  // dat.push_front("9");
  // dat.push_front("71");
  // dat.push_back("8");
  // dat.push_back("9");
  // dat.push_back("10");
  // dat.push_back("11");
  // dat.push_back("12");
  // // dat.push_back("13");
  // // dat.push_back("14");
  // // dat.push_back("15");
  // // dat.push_back("16");
  // // dat.push_back("adsf");
  // // dat.push_back("adsf");
  // // dat.pop_back();
  // // dat.pop_back();
  // // dat.push_back("orange");
  // // dat.push_back("orange");
  // // // dat.pop_back();
  // // dat.pop_back();
  // // // dat.pop_back();
  // // dat.push_back("zero");
  // // dat.pop_back();
  // // dat.push_back("self");
  // // dat.push_front("self");
  // // dat.push_front("hi");
  // // dat.push_front("ho");
  // // dat.push_front("z");
  // // dat.push_front("a");
  // // dat.push_front("b");

  // dat.push_front("z");
  // dat.push_front("a");
  // dat.pop_front();
  // // dat.push_front("b");
  // // dat.push_front("a");
  // // dat.push_front("b");

  // //dat.print_head();
  // // dat.print_tail();
  // dat.print_head();

  // std::cout << dat.front() << std::endl;
  // std::cout << dat.get(0) <<" "<<dat.get(1)<<" "<<dat.get(2) << std::endl;

}
