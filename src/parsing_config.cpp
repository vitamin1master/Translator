#include "parsing_config.h"
#include <fstream>
#include <iostream>

bool parsing_config::parse(const std::string& config_path)
{
	address_config_file = config_path;
	Json::Value root;
	Json::Reader reader;
	std::ifstream in(address_config_file);

	if (!reader.parse(in, root)) {
		std::cerr << "bool parsing_config::parse(const std::string& config_path): Could't parse configuration file" << std::endl;
		return false;
	}

	try {
		input_line = root["input_line"].asString();

		for(Json::Value &it:root["lang"])
		{
			rule_info rule;
			rule.rule=it["rule"].asString();
			rule.alternative=it["alternative"].asString();
			rule.number_alt=it["number_alt"].asInt();

			rules.push_back(rule);
		}
	}
	catch (const Json::LogicError &er)
	{
		std::cerr << er.what() << std::endl;
		return false;
	}
	catch (const std::exception &ec)
	{
		std::cerr << "bool parsing_config::parse(const std::string& config_path): Incorrect field values in the configuration file: " << ec.what() << std::endl;
		return false;
	}

	if(rules.empty())
	{
		std::cerr<<"empty lang"<<std::endl;
		return false;
	}

	return true;
}