//#include<iostream>
//#include "XMLParser.h"
//#include <string>
//using namespace std;
//
//int main() {
//
//	XMLParser x("../Data.xml");
//	return 0;
//}

#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <regex>
#include "Token.h"
void add_tokens(const std::regex reg, string& text, vector<Token>& tokens, TokenType type);
int main()
{
	//// Tokenization (non-matched fragments)
	//// Note that regex is matched only two times; when the third value is obtained
	//// the iterator is a suffix iterator.
	//const std::string text = "Quick brown fox.";
	//const std::regex ws_re("\\s+"); // whitespace
	//std::copy(std::sregex_token_iterator(text.begin(), text.end(), ws_re, -1),
	//	std::sregex_token_iterator(),
	//	std::ostream_iterator<std::string>(std::cout, "\n"));

	//std::cout << '\n';

	// Iterating the first submatches
	std::string s = R"(<root><planes_for_sale><plane_data><year>1977</year><model>Boeing </model><color>Light blue and white</color><description> New paint, nearly new interior, 685 hours SMOH, full IFR King avionics </description><price>23,495 </price><seller>Skyway Aircraft </seller><location><city>Rapid City,</city><state>South Dakota</state></location></plane_data><plane_data><year>1965 </year><model>Airbus </model><color>Gold </color><description> 240 hours SMOH, new Cleveland brakes, great shape </description><seller> John Seller</seller><location><city>St. Joseph,</city><state>Missouri</state></location></plane_data></planes_for_sale></root>)";
	//const std::regex url_re(R"!!(<\s*A\s+[^>]*href\s*=\s*"([^"]*)")!!", std::regex::icase);
	const std::regex re_openTags(R"!!(<([\w+]*)>)!!", std::regex::icase);
	const std::regex re_closedTags(R"!!(</([\w+]*)>)!!", std::regex::icase);
	//const std::regex re_text(R"!!(^(<)([\w+]*)^(>))!!", std::regex::icase);
	//const std::regex re_text(R"!!([>](.*+)[<])!!", std::regex::icase);
	const std::regex re_text(R"!!([>]([\w\s.,\(\)\[\]+]+)[<])!!", std::regex::icase);
	std::cout << "entire matches:\n";


	std::regex_token_iterator<std::string::iterator> a(s.begin(), s.end(), re_text);
	std::regex_token_iterator<std::string::iterator> rend;
	vector<Token> Tokens;

	add_tokens(re_openTags, s, Tokens, TokenType::OpenTag);
	add_tokens(re_closedTags, s, Tokens, TokenType::CloseTag);
	add_tokens(re_text, s, Tokens, TokenType::Text);

	sort(Tokens.begin(), Tokens.end());
	for (auto token : Tokens) {
		cout << token.text << " " << token.startIndex << " " << token.type<<'\n';
	}
	/*while (a != rend) {
		Tokens.push_back(Token(*a, TokenType::Text, std::distance(s.begin(), a->first)));
		std::cout << " [" << *a++ << "] " << std::distance(s.begin(), a->first) << *a->first << " " << *(a->second-3);
		std::cout << '\n';
	}
	std::cout << std::endl;*/

}

void add_tokens(const std::regex reg, string& text, vector<Token>& tokens, TokenType type) {
	std::regex_token_iterator<std::string::iterator> a(text.begin(), text.end(), reg);
	std::regex_token_iterator<std::string::iterator> rend;
	while (a != rend) {
		if (type == TokenType::Text) {
			string myText = (*a).str();
			myText = myText.substr(1, myText.size() - 2);
			tokens.push_back(Token(myText, type, std::distance(text.begin(), (a->first)+1)));
		}
		else
			tokens.push_back(Token(*a, type, std::distance(text.begin(), a->first)));
		a++;
		/*std::cout << " [" << *a++ << "] " << std::distance(text.begin(), a->first) << *a->first << " " << *(a->second - 3);
		std::cout << '\n';*/
	}
}