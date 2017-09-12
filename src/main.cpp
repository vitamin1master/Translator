//
// Created by bso on 11.09.17.
//
#include <iostream>
#include "json.h"
#include "parsing_config.h"
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cerr<<"invalid config path"<<std::endl;
        return 1;
    }

    std::string config_path=argv[1];
    struct parsing_config parser;
    if(!parser.parse(config_path))
    {
        std::cerr<<"couldn't parse config"<<std::endl;
        return 1;
    }

    std::cout<<"Hello world"<<std::endl;
    return 0;
}