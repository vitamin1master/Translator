//
// Created by bso on 11.09.17.
//

#ifndef COMPIL_METH_DOWNLINK_TRANSLATOR_H
#define COMPIL_METH_DOWNLINK_TRANSLATOR_H

#include <stack>
#include <string>
#include <queue>
#include "rule_info.h"

class downlink_translator {
public:
    explicit downlink_translator();
private:
    std::stack<rule_info> m_change_history;
    std::queue<rule_info> m_output_chain;
};


#endif //COMPIL_METH_DOWNLINK_TRANSLATOR_H
