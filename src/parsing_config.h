#pragma once
#include <string>
#include <vector>
#include "json.h"
#include "rule_info.h"

struct parsing_config
{
	std::string address_config_file;
	std::vector<rule_info> rules;
	std::string input_line;

	bool parse(const std::string& config_path);
};
