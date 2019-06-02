#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <regex>
using namespace std;
class TestingExamples{
    public:
        std::vector<std::string> examples;
        string replacement;
        TestingExamples();
        ~TestingExamples();
};

TestingExamples::TestingExamples(){
    replacement = "";
    examples.push_back("<div>WE ar</p>e here<sdkfasldk>>> <> <l=""sdfasdf<>> <///sdfalk> <sdfak iit=sdfaksdfl'> to tak<div id='sdfasd'>e care of things</div><span>hello </span> and new things to find. <b>BOLDED</b>");
    examples.push_back("<script>delete a.path}else d=this.urlForQueryRecord(i,n)</script> NORMAL THINGS <javascript> <javascript src=\"somehith\">delete a.path}else d=this.urlForQueryRecord(i,n) </javascript> <script src=\"../fas.jpg\" > asdf delete a.path}else d=this.urlForQueryRecord(i,n) </javascript>");
    examples.push_back("<style> sdfsad sdf sd  </style> </style>");
}

TestingExamples::~TestingExamples(){
    
}

auto getWhitelistedRegex(){
    std::vector<std::string> whitelist = {"br","p","b","i","ol","il","li"};
    std::string whitelistedMerged = "", regex;
    for(auto x: whitelist)
        whitelistedMerged = whitelistedMerged + x + "|";
    whitelistedMerged.pop_back();
    regex = "<(?!((?:\/\)?(?:" + whitelistedMerged + ")))([^>])+>";
    return regex;
}

auto getJavascriptRegex() {
    std::string regex;
    regex = "<(script|javascript|livescript)(.*?)>(.*?)<\/(script|javascript|livescript|(\s)*)>";
    return regex;
}

auto getInlineJavascriptRegex() {
	std::string regex;
	regex = "";
	return regex;
}

int main() {
    TestingExamples a;
    std::regex regex1(getWhitelistedRegex());
    std::regex regex2(getJavascriptRegex());

	for (auto i : a.examples){
		std::string new_i = std::regex_replace(i, regex2, a.replacement);
        std::cout << new_i << std::endl;
	}
	
    return 0;
}

//std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");

// boost::regex re("<(?!((?:\/\s*)?(?:br|p|b|u|[o|i]l|li)))([^>])+>");

// (?<=(<pre>))(\w|\d|\n|[().,\-:;@#$%^&*\[\]"'+–\/\/®°⁰!?{}|`~]| )+?(?=(<\/pre>))

// ((<(script|javascript)(\s)*(\w|\d|\n|[().,\-:;@=#$%^&*\[\]"'+–\/\/®°⁰!?{}|`~]| )*>))(\s)*(\w|\d|\n|[().,\-:;@#$%^&*\[\]"'=+–\/\/®°⁰!?{}|`~]| )+?(?=(<\/(script|javascript)(\s)*>))

// <(script|javascript|livescript)(.*?)>(.*?)<\/(script|javascript|livescript|(\s)*)>

