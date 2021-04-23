#include<iostream>
#include "XMLParser.h"
#include <string>
using namespace std;

int main() {

	XMLParser parser("../Data.xml");
	auto data = parser.getData();
	data.print();
	return 0;
}

//#include <fstream>
//#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <regex>
//#include "Token.h"
//
//int main()
//{
//	//// Tokenization (non-matched fragments)
//	//// Note that regex is matched only two times; when the third value is obtained
//	//// the iterator is a suffix iterator.
//	//const std::string text = "Quick brown fox.";
//	//const std::regex ws_re("\\s+"); // whitespace
//	//std::copy(std::sregex_token_iterator(text.begin(), text.end(), ws_re, -1),
//	//	std::sregex_token_iterator(),
//	//	std::ostream_iterator<std::string>(std::cout, "\n"));
//
//	//std::cout << '\n';
//
//	// Iterating the first submatches
//	std::string s = R"(<root><planes_for_sale><plane_data><year>1977</year><model>Boeing </model><color>Light blue and white</color><description> New paint, nearly new interior, 685 hours SMOH, full IFR King avionics </description><price>23,495 </price><seller>Skyway Aircraft </seller><location><city>Rapid City,</city><state>South Dakota</state></location></plane_data><plane_data><year>1965 </year><model>Airbus </model><color>Gold </color><description> 240 hours SMOH, new Cleveland brakes, great shape </description><seller> John Seller</seller><location><city>St. Joseph,</city><state>Missouri</state></location></plane_data></planes_for_sale></root>)";
//	//const std::regex url_re(R"!!(<\s*A\s+[^>]*href\s*=\s*"([^"]*)")!!", std::regex::icase);
//	
//	for (auto token : Tokens) {
//		cout << token.text << " " << token.startIndex << " " << token.type<<'\n';
//	}
//	/*while (a != rend) {
//		Tokens.push_back(Token(*a, TokenType::Text, std::distance(s.begin(), a->first)));
//		std::cout << " [" << *a++ << "] " << std::distance(s.begin(), a->first) << *a->first << " " << *(a->second-3);
//		std::cout << '\n';
//	}
//	std::cout << std::endl;*/
//
//}
//
