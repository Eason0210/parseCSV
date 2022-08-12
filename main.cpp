#include <iostream>     // cout, endl
#include <fstream>      // fstream
#include <vector>
#include <string>
#include <algorithm>    // copy
#include <iterator>     // ostream_operator
#include <boost/tokenizer.hpp>

int main()
{
    std::string data("demo.csv");

    std::ifstream in(data.c_str());
    if (!in.is_open()) return 1;

    typedef boost::tokenizer< boost::escaped_list_separator<char> > Tokenizer;
    std::vector< std::string > vec;
    std::string line;

    while (getline(in,line))
    {
        Tokenizer tok(line);
        vec.assign(tok.begin(),tok.end());

        // vector now contains strings from one row, output to cout here
        copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, "|"));

        std::cout << "\n----------------------" << std::endl;
    }
}
